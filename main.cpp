#include <iostream>
using namespace std;

int main() {
    int choice;

    while (true) {
        cout << "\n--- Student Management System ---\n";
        cout << "1. Add Student\n";
        cout << "2. View Students\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Add Student selected\n";
        }
        else if (choice == 2) {
            cout << "View Students selected\n";
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