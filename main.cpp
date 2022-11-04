
//part B main file with setup
#include <iostream>
#include <string>
using namespace std;
#include "roster.h"

int main() {

	// Student data as given in instructions with my information added for A5 -task A
	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Susan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Rachel,McDaniel,rmcda72@wgu.edu,34,49,49,49,SOFTWARE"
	};

		//Print header with course name, programming language, studentID, and name. - task F1
	cout << "C867-Scripting & Programming: Applications" << endl;
	cout << "Language: C++" << endl;
	cout << "Student ID: 010433659" << endl;
	cout << "Name: Rachel McDaniel" << endl << endl;

	Roster classRoster;

	for (int i = 0; i < 5; ++i)
	{
		classRoster.parse(studentData[i]);
	}
	
	
	classRoster.printAll(); 

	classRoster.printInvalidEmails(); 

	for (int i = 0; i < 5; ++i)
	{
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->GetstudentId()); 
	}
	classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE); 

	classRoster.remove("A3"); 

	classRoster.printAll(); 

	classRoster.remove("A3"); 








	return 0;
}
