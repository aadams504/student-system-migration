#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
#include <vector>
#include "degree.h"

using namespace std;

class Student
{
public:
    Student();

    Student(string sStudentID, string sFirstName, string sLastName, string sEmail, int sAge, int sDaysInCourse1, int getDaysInCourse2, int getDaysInCourse3, DegreeProgram sDegreeProgram);

    void setStudentID(string sStudentID);
    string getStudentID();

    void setFirstName(string sFirstName);
    string getFirstName();

    void setLastName(string sLastName);
    string getLastName();

    void setEmail(string sEmail);
    string getEmail();

    void setAge(int sAge);
    int getAge();

    void setDaysInCourse(int sDaysInCourse1, int sDaysInCourse2, int sDaysInCourse3);
    int getDaysInCourse1();
    int getDaysInCourse2();
    int getDaysInCourse3();

    void setDegreeProgram(DegreeProgram sDegreeProgram);
    string getDegreeProgram();

    void print();

private:
    string studentID;
    string firstName;
    string lastName;
    string email;
    int age;
    vector<int> daysInCourse;
    DegreeProgram degreeProgram;
};
#endif
