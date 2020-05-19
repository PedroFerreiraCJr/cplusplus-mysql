#include <iostream>

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

/*
    g++ -std=c++14 -Wall -o mysql_connection mysql_connection.cpp -lpthread -lmysqlcppconn
*/

using namespace std;

int main(int argc, const char *argv[]) {
    try {
        sql::Driver *driver {0};
        sql::Connection *conn {0};
        sql::Statement *stmt {0};
        sql::ResultSet *rs {0};

        driver = get_driver_instance();
        conn = driver->connect("tcp://127.0.0.1:3306", "pedro", "pedro");

        conn->setSchema("cplusplus");

        stmt = conn->createStatement();
        rs = stmt->executeQuery("show variables like 'version';");
    
        while (rs->next()) {
            cout << rs->getString("variable_name") << endl;
            cout << rs->getString("value") << endl;
        }

        delete rs;
        delete stmt;
        delete conn;
    } catch (sql::SQLException &e) {
        cout << e.what() << endl;
        cout << e.getErrorCode() << endl;
        cout << e.getSQLState() << endl;
    }

    return 0;
}