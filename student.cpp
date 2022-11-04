
//part B student file with setup
#include <iostream>
#include <string>
using namespace std;
#include "student.h"

//task D create class student with accessors, mutators and variables given.
Student::Student() {
	this->studentId = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->Age = 0;
	this->days = new int [3];
	this->degree = DegreeProgram::SOFTWARE;
}
Student::Student(string studentId, string firstName, string lastName, string emailAddress, int Age, int days[], DegreeProgram degreeProgram)
{
	this->studentId = studentId;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->Age = Age;
	this->days = new int[3];
	for (int i = 0; i < 3; i++) this->days[i] = days[i];
	this->degree = degreeProgram;
}

//Deconstructor step F5
Student::~Student() {
	delete[] days;

}
//Access the data step D2a
string Student::GetstudentId() {
	return studentId;
}
string Student::GetfirstName() {
	return firstName;
}
string Student::GetlastName() {
	return lastName;
}
string Student::GetemailAddress() {
	return emailAddress;
}
int Student::GetAge() {
	return Age;
}
int* Student::Getdays() {
	return days;
}
DegreeProgram Student::Getdegree() {
	return degree;
}
//Mutate the data step D2b

void Student::SetstudentId(string studentId) {
	this->studentId = studentId;
	return;
}
void Student::SetfirstName(string firstName) {
	this->firstName = firstName;
	return;
}
void Student::SetlastName(string lastName) {
	this->lastName = lastName;
	return;
}
void Student::SetemailAddress(string emailAddress) {
	this->emailAddress = emailAddress;
	return;
}
void Student::SetAge(int Age) {
	this->Age = Age;
	return;
}
void Student::Setdays(int days[]) {
	for (int i = 0; i < 3; ++i) this->days[i] = days[i];
}

//print the data step D2e
void Student::print() {
	int *tempdays = Getdays();
	string degree_program;
	if (degree == DegreeProgram::NETWORK) {
		degree_program = "NETWORK";
	}
	else if (degree == DegreeProgram::SECURITY) {
		degree_program = "SECURITY";
	}
	else if (degree == DegreeProgram::SOFTWARE) {
		degree_program = "SOFTWARE";
	}
	
	cout << GetstudentId() << "\t" << GetfirstName() << "\t" << GetlastName() << "\t" << GetemailAddress() << "\t" << GetAge() << "\t" << "{" << tempdays[0] << "," << tempdays[1] << ", " << tempdays[2] << "}" << "\t" << degree_program << endl;

	return;
	
}