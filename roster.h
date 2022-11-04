#pragma once
//part B roster file
#include "student.h"

class Roster {
public:
	Roster();

	//deconstructor step F5
	~Roster();
	
	void parse(string row);
	
	//required functions step E3
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degree);
	void remove(string studentId);
	void printAll();
	void printAverageDaysInCourse(string studentId);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degree);


	int lastIndex = -1;
	const static int numStudents = 5;
	
	Student* classRosterArray[numStudents];

};
