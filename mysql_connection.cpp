#include <iostream>
#include <string>

#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/connection.h>
#include <cppconn/exception.h>
#include <cppconn/datatype.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/parameter_metadata.h>
#include <cppconn/resultset.h>
#include <cppconn/resultset_metadata.h>

class Value {
    public:
        std::string name;
        std::string value;
};

static Value *query(const std::string &, const std::string &);

int main(int argc, const char *argv[]) {
    std::string username {""};
    std::string password {""};

    do {
        std::cout << "Username: ";
        std::getline(std::cin, username);

        std::cout << "Password: ";
        std::getline(std::cin, password);

        if (!username.empty() && !password.empty()) {
            break;
        }

        std::cout << "Informações incorretas." << std::endl;
    } while (true);

    std::cout << "Consultando..." << std::endl;

    try {
    	Value *result = query(username, password);
        std::cout << "Variável: " << result->name << ", Valor: " << result->value << std::endl;
    } catch(int &e) {
	std::cout << "Houve uma falha na consulta ao banco de dados." << std::endl;
    }

    return 0;
}

static Value *query(const std::string &username, const std::string &password) {
    Value *result = new Value();

    try {
        sql::Driver *driver = get_driver_instance();
        sql::Connection *conn = driver->connect("tcp://127.0.0.1:3306", username, password);

        conn->setSchema("cplusplus");

        sql::Statement *stmt = conn->createStatement();
        sql::ResultSet *rs = stmt->executeQuery("show variables like 'version';");

        while (rs->next()) {
            result->name = rs->getString("variable_name");
            result->value = rs->getString("value");
        }

        delete rs;
        delete stmt;
        delete conn;
    } catch (sql::SQLException &e) {
        std::cout << "what message: " << e.what() << std::endl;
        std::cout << "sqlerrorcode: " << e.getErrorCode() << std::endl;
        std::cout << "sqlstate:   : " << e.getSQLState() << std::endl;
	throw 1;
    }

    return result;
}
