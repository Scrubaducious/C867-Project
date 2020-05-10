#pragma once
#include "student.h"
#include <string>

const std::string studentData[] =
{
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Scott,Woods,swoo268@wgu.edu,20,14,14,14,SOFTWARE"
};

class Roster
{
public:

	Roster();

	int classRosterArraySize = 5;
	Student* classRosterArray[5];

	void add(
		std::string studentID, 
		std::string firstName, 
		std::string lastName, 
		std::string emailAddress, 
		int age, 
		int daysInCourse1, 
		int daysInCourse2, 
		int daysInCourse3,
		int arrayLocation,
		DegreeProgram degreeProgram
		);
	void remove(std::string studentID);
	void printAll();
	void printAverageDaysInCourse(std::string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);

	~Roster();
};