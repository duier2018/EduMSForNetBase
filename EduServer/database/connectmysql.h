#ifndef CONNECTMYSQL_H
#define CONNECTMYSQL_H

class ConnectMySQL
{
public:
    ConnectMySQL();

    bool createConnection();
    void closeConnection();
};

#endif // CONNECTMYSQL_H
