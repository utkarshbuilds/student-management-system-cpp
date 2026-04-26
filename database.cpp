#include "database.h"
#include <iostream>
using namespace std;

Database::Database()
{
    if(sqlite3_open("student.db", &db))
    {
        cout << "Error opening database\n";
    }
    else
    {
        cout << "Database open successfully\n";
    }
}

Database::~Database()
{
    sqlite3_close(db);
}

void Database::createTable()
{
   const char* sql =
        "CREATE TABLE IF NOT EXISTS students ("
        "id INTEGER PRIMARY KEY, "
        "name TEXT, "
        "age INTEGER);";
        
    char* errMsg = 0;
    if (sqlite3_exec(db, sql, 0, 0, &errMsg) != SQLITE_OK) {
        std::cout << "Error creating table: " << errMsg << std::endl;
    } else {
        std::cout << "Table ready\n";
    }
}