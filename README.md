# Laboratório - Acessando o banco de dados MySQL através do driver legado em C++

Laboratório de código utilizando a linguagem de programação C++ que faz a conexão com o banco de dados MySQL 8.<br>
O driver que está sendo utilizado ainda está sendo da versão legacy JDBC 4.

Dependendo da versão do bando de dados MySQL, será necessário alterar a forma de autenticação da senha do
usuário do banco que é utilizado para fazer a consulta. Como está sendo utilizado o driver legado, o usuário
deverá possuir a forma nativa de autenticação.
Em caso de erro na execução do programa, utilizar o script abaixo:

```sql
ALTER USER 'username'@'localhost' IDENTIFIED WITH mysql_native_password BY 'password';
```

**Obs**: Para executar o programa, é necessário criar o banco de dados chamado cplusplus.
