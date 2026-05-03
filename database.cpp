#include "database.h"
#include <iostream>
#include <string>
using namespace std;

Database::Database()
{
    if (sqlite3_open("students.db", &db))
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
    const char *sql =
        "CREATE TABLE IF NOT EXISTS students ("
        "id INTEGER PRIMARY KEY, "
        "name TEXT, "
        "age INTEGER);";

    char *errMsg = 0;
    if (sqlite3_exec(db, sql, 0, 0, &errMsg) != SQLITE_OK)
    {
        std::cout << "Error creating table: " << errMsg << std::endl;
    }
    else
    {
        std::cout << "Table ready\n";
    }
}

void Database::addStudent(int id, string name, int age)
{
    string sql = "INSERT INTO students (id, name, age) VALUES (" + to_string(id) + ", '" + name + "', " + to_string(age) + ");";
    char *errMsg = 0;
    if (sqlite3_exec(db, sql.c_str(), 0, 0, &errMsg) != SQLITE_OK)
    {
        std::cout << "Error adding student: " << errMsg << std::endl;
    }
    else
    {
        std::cout << "Student added\n";
    }
}

void Database::viewStudents()
{
    const char *sql = "SELECT * FROM students;";
    char *errMsg = 0;
    if (sqlite3_exec(db, sql, [](void *, int argc, char **argv, char **colName) -> int
                     {
        for (int i = 0; i < argc; i++) {
            cout << colName[i] << ": " << (argv[i] ? argv[i] : "NULL") << " | ";
        }
        cout << endl;
        return 0; }, 0, &errMsg) != SQLITE_OK)
    {
        std::cout << "Error viewing students: " << errMsg << std::endl;
    }
}

void Database::searchStudent(int id)
{
    string sql = "SELECT * FROM students WHERE id = " + to_string(id) + ";";
    char *errMsg = 0;
    if (sqlite3_exec(db, sql.c_str(), [](void *, int argc, char **argv, char **colName) -> int
                     {
        for (int i = 0; i < argc; i++) {
            cout << colName[i] << ": " << (argv[i] ? argv[i] : "NULL") << " | ";
        }
        cout << endl;
        return 0; }, 0, &errMsg) != SQLITE_OK)
    {
        std::cout << "Error searching student: " << errMsg << std::endl;
    }
}

void Database::deleteStudent(int id)
{
    std::string sql = "DELETE FROM students WHERE id = " + std::to_string(id) + ";";

    char *errMsg = 0;

    if (sqlite3_exec(db, sql.c_str(), 0, 0, &errMsg) != SQLITE_OK)
    {
        std::cout << "Delete Error: " << errMsg << std::endl;
    }
    else
    {
        std::cout << "Student deleted successfully\n";
    }
}

void Database::updateStudent(int id, std::string name, int age)
{
    std::string sql = "UPDATE students SET name='" + name +
                      "', age=" + std::to_string(age) +
                      " WHERE id=" + std::to_string(id) + ";";

    char *errMsg = 0;

    if (sqlite3_exec(db, sql.c_str(), 0, 0, &errMsg) != SQLITE_OK)
    {
        std::cout << "Update Error: " << errMsg << std::endl;
    }
    else
    {
        std::cout << "Student updated successfully\n";
    }
}