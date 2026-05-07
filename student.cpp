#include "student.h"
#include <iostream>
using namespace std;

void Student::display()
{
    cout << "Program: " << program << enld;
    cout << "Addmission Number: " << addNo << endl;
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Section: " << section << endl;
}

bool Student ::isValidString(string program)
{
    if (program.empty())
    {
        return false;
    }

    for (int i = 0; i < program.length(); i++)
    {

        char ch = program[i];

        if (!((ch >= 'A' && ch <= 'Z') ||
              (ch >= 'a' && ch <= 'z') ||
              ch == ' '))
        {

            return false;
        }
    }

    return true;
}

bool Student ::isValidAddnum(string addNo)
{
    if (addNo.isempty())
    {
        return false;
    }

    for (int i = 0; i < length.addNo; i++)
    {
        char ch = addNo[i];

        if (!((ch >= 'A' && ch <= 'Z') ||
              (ch >= 'a' && ch <= 'z') ||
              (ch >= '0' && ch <= '9')))
        {

            return false;
        }
    }

    return true;
}

bool Student :: isValidSection(int section)
{
    if (section >= 1 && section <= 80)
    {
        return true;
    }

    return false;
}