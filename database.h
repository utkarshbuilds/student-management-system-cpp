#ifndef DATABASE_H
#define DATABASE_H

#include "sqlite3.h"
#include <string>
using namespace std;

class Database 
{
    public:
    sqlite3 *db;
    Database();
    ~Database();
    void createTable();
    void addStudent(int id, string name, int age);
    void viewStudents();
};
    
#endif