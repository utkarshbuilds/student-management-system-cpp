#include <iostream>
#include "student.h"
#include "database.h"
#include <limits>
#include <string>
#include <vector>
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
        // --- VALIDATE ID ---
        cout << "Enter ID: ";
        while (!(cin >> id))
        {
            cout << "Invalid. Enter a numeric ID: ";
            cin.clear(); // Reset the error flag

            // Manually clear the buffer (The "Trash Collector")
            char ch;
            while (cin.get(ch) && ch != '\n')
                ;
        }

        // --- HANDLE NAME ---
        cout << "Enter Name: ";
        // Clear the leftover newline from the ID input
        char ch;
        while (cin.get(ch) && ch != '\n');
        getline(cin, name);

        // --- VALIDATE AGE ---
        cout << "Enter Age: ";
        while (!(cin >> age) || age <= 0 || age > 120)
        {
            cout << "Invalid Age (1-120). Try again: ";
            cin.clear();
            while (cin.get(ch) && ch != '\n')
                ;
        }

        break; // Success!
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
