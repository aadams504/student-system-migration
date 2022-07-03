#include "student.h"
using namespace std;

Student::Student()
{
}

Student::Student(string sStudentID, string sFirstName, string sLastName, string sEmail, int sAge, int sDaysInCourse1, int sDaysInCourse2, int sDaysInCourse3, DegreeProgram sDegreeProgram)
{
    setStudentID(sStudentID);
    setFirstName(sFirstName);
    setLastName(sLastName);
    setEmail(sEmail);
    setAge(sAge);
    setDaysInCourse(sDaysInCourse1, sDaysInCourse2, sDaysInCourse3);
    setDegreeProgram(sDegreeProgram);
}

//accessors
string Student::getStudentID()
{
    return studentID;
}

string Student::getFirstName()
{
    return firstName;
}

string Student::getLastName()
{
    return lastName;
}

string Student::getEmail()
{
    return email;
}

int Student::getAge()
{
    return age;
}

int Student::getDaysInCourse1()
{
    return daysInCourse.at(0);
}

int Student::getDaysInCourse2()
{
    return daysInCourse.at(1);
}

int Student::getDaysInCourse3()
{
    return daysInCourse.at(2);
}

string Student::getDegreeProgram()
{
    switch (degreeProgram)
    {
    case SECURITY:
        return "Security";
        break;
    case NETWORK:
        return "Network";
        break;
    case SOFTWARE:
        return "Software";
        break;
    default:
        return "Undeclared";

    }

}

//mutators
void Student::setStudentID(string sStudentID)
{
    studentID = sStudentID;
}

void Student::setFirstName(string sFirstName)
{
    firstName = sFirstName;
}

void Student::setLastName(string sLastName)
{
    lastName = sLastName;
}

void Student::setEmail(string sEmail)
{
    email = sEmail;
}

void Student::setAge(int sAge)
{
    age = sAge;
}

void Student::setDaysInCourse(int sDaysInCourse1, int sDaysInCourse2, int sDaysInCourse3)
{
    vector<int> daysInCourseArr = { sDaysInCourse1, sDaysInCourse2, sDaysInCourse3 };
    daysInCourse = daysInCourseArr;
}

void Student::setDegreeProgram(DegreeProgram sDegreeProgram)
{
    degreeProgram = sDegreeProgram;
}


void Student::print()
{
    cout << studentID << "\t" << "First Name: " << firstName << "\t" << "Last Name: " << lastName << "\t" << "Age: " << age << "\t" << "Days in Course: " << "{" << getDaysInCourse1() << ", " << getDaysInCourse2() << ", " << getDaysInCourse3() << "}  " << "Degree Program: " << getDegreeProgram() << endl;
}
