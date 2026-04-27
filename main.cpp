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

    while (true)
    {
        cout << "\n--- Student Management System ---\n";
        cout << "1. Add Student\n";
        cout << "2. View Students\n";
        cout << "3. Update Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            Student s;
            s.input();
            db.addStudent(s.id, s.name, s.age);
            
        }
        else if (choice == 2)
        {
            db.viewStudents();
        }
        else if (choice == 3)
        {
            int id;
            cout << "Enter student ID to update: ";
            cin >> id;
            // For simplicity, we will just delete and re-add the student
        }
        else if (choice == 4)
        {
            int id;
            cout << "Enter student ID to delete: ";
            cin >> id;
            // For simplicity, we will just delete the student
        }
        else if (choice == 5)
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

