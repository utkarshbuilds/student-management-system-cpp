#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

class Student {
public:
    string name;
    int age;
    int id;

public:
    void input();
    void display();
};

#endif // STUDENT_H