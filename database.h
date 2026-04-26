#ifndef Database_H
#define Database_H

#include "sqlite3.h"
class Database 
{
    public:
    sqlite3 *db;
    Database();
    ~Database();
    void createTable();
};
    
#endif