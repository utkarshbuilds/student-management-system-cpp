#include <iostream>
#include "student.h"
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
   
    vector<Student> students;
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
            students.push_back(s);
        }
        else if (choice == 2)
        {
            for (auto &s : students)
            {
                s.display();
                cout << "----------------\n";
            }
        }
        else if (choice == 3)
        {
            int id;
            cout << "Enter student ID to update: ";
            cin >> id;
            bool found = false;
            for (auto &s : students)
            {
                if (s.id == id)
                {
                    s.input();
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                cout << "Student not found\n";
            }
        }
        else if (choice == 4)
        {
            int id;
            cout << "Enter student ID to delete: ";
            cin >> id;
            auto it = remove_if(students.begin(), students.end(), [id](Student &s)
                                { return s.id == id; });
            if (it != students.end())
            {
                students.erase(it, students.end());
                cout << "Student deleted\n";
            }
            else
            {
                cout << "Student not found\n";
            }
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
