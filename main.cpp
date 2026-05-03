#include <iostream>
#include "student.h"
#include <vector>
#include "database.h"
#include <algorithm>
using namespace std;

int main()
{

    Database db;
    db.createTable();
    int choice;

    int id, age;
    string name;

    while (true)
    {
        cout << "Enter ID: ";
        if (!(cin >> id))
        {
            cout << "Invalid ID\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter Age: ";
        if (!(cin >> age) || age <= 0 || age > 120)
        {
            cout << "Invalid Age\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        break;
    }

    while (true)
    {
        cout << "\n--- Student Management System ---\n";
        cout << "1. Add Student\n";
        cout << "2. View Students\n";
        cout << "3. Update Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Search Studentf\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            Student s;
            db.addStudent(id, name, age);
        }
        else if (choice == 2)
        {
            db.viewStudents();
        }
        else if (choice == 3)
        {
            int id;
            string name;
            int age;
            cout << "Enter student ID to update: ";
            cin >> id;
            cout << "Enter new name: ";
            cin >> name;
            cout << "Enter new age: ";
            cin >> age;
            db.updateStudent(id, name, age);
        }
        else if (choice == 4)
        {
            int id;
            cout << "Enter student ID to delete: ";
            cin >> id;
            db.deleteStudent(id);
        }
        else if (choice == 5)
        {
            int id;
            cout << "Enter student ID to search: ";
            cin >> id;
            db.searchStudent(id);
        }
        else if (choice == 6)
        {
            break;
        }
        else
        {
            cout << "Invalid choice\n";
        }
    }

    return 0;
}
