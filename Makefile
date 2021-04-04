.PHONY: all clean execute

# por padrao o target sera a execucao do arquivo compilado
all: clean execute

# caso o arquivo esteva com o timestamp mais antigo, sera apagado
clean:
	@rm -rf ./bin/
	@echo "arquivos removidos"

# local e arquivo que sera gerado na execucao da compilacao do arquivo do source code
./bin/mysql_connection: ./mysql_connection.cpp
	@echo "compilando..."
	@mkdir bin/
	@g++ -std=c++14 -Wall -o ./bin/mysql_connection mysql_connection.cpp -lpthread -lmysqlcppconn

# simplesmente executa o arquivo caso nao tenha havido modificacao no source code
execute: ./bin/mysql_connection
	@./bin/mysql_connection
