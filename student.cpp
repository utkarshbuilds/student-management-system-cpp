#include "student.h"
#include <iostream>
using namespace std;

void Student::input()
{
    cout << "Enter id: ";
    cin  >> id;

    cout << "Enter name: ";
    cin >> name;

    cout << "Enter age: ";
    cin >> age;
}

void Student::display()
{
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
}