
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "degree.h"
#include "roster.h"

using namespace std;

int main()
{
    Roster classRoster;
    classRoster.printAll();
    cout << endl;
    classRoster.printInvalidEmails();
    cout << endl;
    classRoster.printAverageDaysInCourse(classRoster.classRosterArray[3].getStudentID());
    cout << endl;
    classRoster.printByDegreeProgram(SOFTWARE);
    cout << endl;
    classRoster.remove("A3");
    cout << endl;
    classRoster.printAll();
    cout << endl;
    classRoster.remove("A3");

    return 0;
}
