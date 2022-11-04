//part B roster file with setup
#include <iostream>
#include <string>
using namespace std;
#include "roster.h"

Roster::Roster() {
	
}

void Roster::parse(string row) {
	size_t rhs = row.find(",");
	string studentID = row.substr(0, rhs);

	size_t lhs = rhs + 1;
	rhs = row.find(",", lhs);
	string firstName = row.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	string lastName = row.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	string emailAddress = row.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	int age = stoi(row.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	int daysInCourse1 = stoi(row.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	int daysInCourse2 = stoi(row.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	int daysInCourse3 = stoi(row.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	string strDegree = row.substr(lhs, rhs - lhs);

	DegreeProgram degree = DegreeProgram::SOFTWARE;
	if (strDegree == "SECURITY") {
		degree = DegreeProgram::SECURITY;
	}
	else if (strDegree == "NETWORK") {
		degree = DegreeProgram::NETWORK;
	}
	
	this->add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degree); 

	

}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degree) {
	 
	int DaysIC[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };

	this->classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, DaysIC, degree);

}

void Roster::printAll() {

	cout << "Displaying all students:" << endl;
	for (int i = 0; i <= Roster::lastIndex; i++) {
		this->classRosterArray[i]->print();
	}
	
	cout << endl;
}

void Roster::printByDegreeProgram(DegreeProgram degree) {
	cout << "Showing students by degree program: " << endl;

	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (classRosterArray[i]->Getdegree() == degree) classRosterArray[i]->print();
	}
	cout << endl;
}

void Roster::printInvalidEmails()
{
	cout << "Displaying invalid emails:" << endl << endl;
	bool any = false;
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		string eMail = (classRosterArray[i]->GetemailAddress());
		if (eMail.find("@") == string::npos || (eMail.find(".") == string::npos || (eMail.find(" ") != string::npos)))
		{
			any = true;
			cout << eMail << " - is invalid." << endl;
		}
	}
	if (!any) cout << "NONE" << endl;

	cout << endl;
}

void Roster::printAverageDaysInCourse(string studentId)
{
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (classRosterArray[i]->GetstudentId() == studentId)
		{
			cout << "Student ID: " << classRosterArray[i]->GetstudentId() << ", ";
			cout << "average days in course is: " << (classRosterArray[i]->Getdays()[0] + classRosterArray[i]->Getdays()[1] + classRosterArray[i]->Getdays()[2]) / 3 << endl;
		}
	}
	cout << endl;
}

void Roster::remove(string studentId)
{
	cout << "Removing " << studentId << ":" << endl << endl;
	bool found = false;
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (classRosterArray[i]->GetstudentId() == studentId)
		{
			found = true;
			if (i < numStudents - 1)
			{
				Student* temp = classRosterArray[i];
				classRosterArray[i] = classRosterArray[numStudents - 1];
				classRosterArray[numStudents - 1] = temp;

			}
			Roster::lastIndex--;
		}
	}
	if (found == false)
	{
		cout << "Removing " << studentId << " again" << endl << endl << "The student with the ID: " << studentId << " was not found." << endl;
	}
	
}
Roster::~Roster()
{
	cout << "DESTRUCTOR CALLED!!" << endl << endl;
	for (int i = 0; i < numStudents; i++)
	{
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}

}










