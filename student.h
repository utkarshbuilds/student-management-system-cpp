#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

class Student {
public:
    string name;
    int age;
    int id;
    string addNo;
    string program;
    string section;
public:
    void display();
    bool isValidString(string program);
    bool isValidAddnum(string addnum);
    bool isValidSection(int section);
};

#endif // STUDENT_H