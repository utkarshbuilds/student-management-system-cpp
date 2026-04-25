#include "student.h"
#include <iostream>
using namespace std;

void Student::input()
{
    cout << "Enter id: " << endl;
    cin >> id;

    cout << "Enter name: " << endl;
    cin >> name;   

    cout << "Enter grade: " << endl;
    cin >> grade;
}

void Student::display()
{
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Grade: " << grade << endl;
}