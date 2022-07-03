#pragma once
#ifndef ROSTER_H
#define ROSTER_H
#include<vector>
#include<string>
#include<iostream>
#include<sstream>
#include"student.h"

using namespace std;

class Roster {
public:
    Roster();
    ~Roster();
    vector<Student> classRosterArray;
    void addStudentData();

    void add(string studentID, string firstName, string lastName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
    void remove(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeprogram);

};
#endif

