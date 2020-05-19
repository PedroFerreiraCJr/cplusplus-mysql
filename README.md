# cpp-mysql-sample

Amostra de código utilizando a linguagem de programação C++ para fazer a conexão com o banco de dados MySQL 8.
O driver que está sendo utilizado ainda está sendo o da versão legacy JDBC 4.

Dependendo da versão do bando de dados do MySQL, será necessário alterar a forma de autenticação da senha do
usuário do banco. Como está sendo utilizado o driver legado, o usuário deverá possuir a forma nativa de autenticação.
Em caso de erro na execução do programa, utilizar o script abaixo:

```sql
ALTER USER 'username'@'localhost' IDENTIFIED WITH mysql_native_password BY 'password';
```
