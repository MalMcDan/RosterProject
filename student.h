#pragma once
//part B student file
#include "degree.h"

//task D create class student with accessors, mutators and variables given.
class Student {
	string studentId;
	string firstName;
	string lastName;
	string emailAddress;
	int Age;
	int *days;
	DegreeProgram degree;

public:
	Student();
	Student(string studentId, string firstName, string lastName, string emailAddress, int Age, int days[], DegreeProgram degreeProgram);
	~Student();

	string GetstudentId();
	string GetfirstName();
	string GetlastName();
	string GetemailAddress();
	int GetAge();
	int* Getdays();
	DegreeProgram Getdegree();

	void SetstudentId(string studentId);
	void SetfirstName(string firstName);
	void SetlastName(string lastName);
	void SetemailAddress(string emailAddress);
	void SetAge(int Age);
	void Setdays(int days[]);
	


	void print();
};
