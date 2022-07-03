#include "roster.h"

const string studentData[] =
    {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Bob,Builder,bobbuilder@yahoo.com,27,4,8,35,SOFTWARE"

};

Roster::Roster()
{
    addStudentData();
}

Roster::~Roster()
{
    cout << " --- VALID DESTRUCTOR CALL ---" << endl;
}

void Roster::addStudentData()
{
    for (int i = 0; i < 5; i++)
    {
        vector<string> entry;
        istringstream inSS(studentData[i]);
        while (inSS.good())
        {
            string substr;
            getline(inSS, substr, ',');
            entry.push_back(substr);
        }
        DegreeProgram degree = SECURITY;
        if (entry.at(8) == "SOFTWARE")
        {
            degree = SOFTWARE;
        }
        if (entry.at(8) == "SECURITY")
        {
            degree = SECURITY;
        }
        if (entry.at(8) == "NETWORK")
        {
            degree = NETWORK;
        }

        Student student(entry.at(0), entry.at(1), entry.at(2), entry.at(3), stoi(entry.at(4)), stoi(entry.at(5)), stoi(entry.at(6)), stoi(entry.at(7)), degree);
        classRosterArray.push_back(student);
    }
}

void Roster::add(string studentID, string firstName, string lastName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
    Student student(studentID, firstName, lastName, email, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
    classRosterArray.push_back(student);
}

void Roster::remove(string studentID)
{
    bool inv = true;
    for (unsigned int i = 0; i < classRosterArray.size(); i++)
    {

        if (classRosterArray[i].getStudentID() == studentID)
        {
            classRosterArray.erase(classRosterArray.begin() + (i - 1));
            inv = false;
        }
        if (i == (classRosterArray.size() - 1) && inv == true)
        {
            cout << "INVALID ID - STUDENT NOT FOUND" << endl;
        }
    }
}

void Roster::printAll()
{
    for (unsigned int i = 0; i < classRosterArray.size(); i++)
    {
        classRosterArray[i].print();
    }
}

void Roster::printAverageDaysInCourse(string studentID)
{
    bool inv = true;
    for (unsigned int i = 0; i < classRosterArray.size(); i++)
    {
        if (classRosterArray[i].getStudentID() == studentID)
        {
            int average = (classRosterArray[i].getDaysInCourse1() + classRosterArray[i].getDaysInCourse2() + classRosterArray[i].getDaysInCourse3()) / 3.0;
            cout << "AVERAGE DAYS IN COURSE: " << average << endl;
            inv = false;
        }
        if (i == (classRosterArray.size() - 1) && inv == true)
        {
            cout << "INVALID ID - STUDENT NOT FOUND" << endl;
        }
    }
}

void Roster::printInvalidEmails()
{
    cout << "INVALID STUDENT EMAIL ADDRESSES: ";
    for (int i = 0; i < classRosterArray.size(); ++i)
    {
        bool invAt = false;
        bool invPeriod = false;
        bool invSpace = false;
        string invEmail = "";
        invEmail = classRosterArray[i].Student::getEmail();
        for (char &charIndex : invEmail)
        {
            if (charIndex == '@')
            {
                invAt = true;
            }
            if (charIndex == '.')
            {
                invPeriod = true;
            }
            if (charIndex == ' ')
            {
                invSpace = true;
            }
        }
        if (invAt == false || invPeriod == false || invSpace == true)
        {
            cout << classRosterArray[i].Student::getEmail() << endl;
        }
    }
}

void Roster::printByDegreeProgram(DegreeProgram degreeprogram)
{
    for (unsigned int i = 0; i < classRosterArray.size(); i++)
    {
        switch (degreeprogram)
        {
        case SOFTWARE:
            if (classRosterArray[i].getDegreeProgram() == "Software")
            {
                classRosterArray[i].print();
            }
            break;
        case NETWORK:
            if (classRosterArray[i].getDegreeProgram() == "Network")
            {
                classRosterArray[i].print();
            }
            break;
        case SECURITY:
            if (classRosterArray[i].getDegreeProgram() == "Security")
            {
                classRosterArray[i].print();
            }
            break;
        default:
            break;
        }
    }
}
