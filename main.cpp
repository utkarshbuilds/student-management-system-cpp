#include <iostream>
#include "student.h"
#include <vector>
using namespace std;

int main() 
{
    vector<Student> students;
    int choice;

    while (true) {
        cout << "\n--- Student Management System ---\n";
        cout << "1. Add Student\n";
        cout << "2. View Students\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            Student s;
            s.input();
            students.push_back(s);
        }
        else if (choice == 2) {
            for (auto &s : students) {
                s.display();
                cout << "----------------\n";
            }
        }
        else if (choice == 3) {
            break;
        }
        else {
            cout << "Invalid choice\n";
        }
    }

    return 0;
}

