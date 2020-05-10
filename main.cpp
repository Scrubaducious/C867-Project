#include <iostream>
#include <string>
#include <sstream>
#include "roster.h"
#include "student.h"
#include "degree.h"

int main()
{
	//Print my Project Info
	std::cout << "Scripting and Programming Applications - C867" << "\nProject written in C++" << "\nStudent ID: 001210376" << "\nScott Woods" << std::endl;
	
	Roster classRoster;
	
	//Add info from StudentData to class Roster
	for (int i = 0; i < 5; i++)
	{
		size_t endPoint = studentData[i].find(',');
		std::string currentStudentID = studentData[i].substr(0, endPoint);

		size_t startPoint = endPoint + 1;
		endPoint = studentData[i].find(',', startPoint);
		std::string currentFirstName = studentData[i].substr(startPoint, endPoint - startPoint);

		startPoint = endPoint + 1;
		endPoint = studentData[i].find(',', startPoint);
		std::string currentLastName = studentData[i].substr(startPoint, endPoint - startPoint);

		startPoint = endPoint + 1;
		endPoint = studentData[i].find(',', startPoint);
		std::string currentEmailAddress = studentData[i].substr(startPoint, endPoint - startPoint);

		startPoint = endPoint + 1;
		endPoint = studentData[i].find(',', startPoint);
		std::string currentAgeStr = studentData[i].substr(startPoint, endPoint - startPoint);
		std::stringstream currentAgeStream(currentAgeStr);
		int currentAge = 0;
		currentAgeStream >> currentAge;

		//Days remaining in course
		int currentDaysInCourse[3];

		startPoint = endPoint + 1;
		endPoint = studentData[i].find(',', startPoint);
		std::string daysCourseOne = studentData[i].substr(startPoint, endPoint - startPoint);
		std::stringstream daysCourseOneStream(daysCourseOne);
		daysCourseOneStream >> currentDaysInCourse[0];

		startPoint = endPoint + 1;
		endPoint = studentData[i].find(',', startPoint);
		std::string daysCourseTwo = studentData[i].substr(startPoint, endPoint - startPoint);
		std::stringstream daysCourseTwoStream(daysCourseTwo);
		daysCourseTwoStream >> currentDaysInCourse[1];

		startPoint = endPoint + 1;
		endPoint = studentData[i].find(',', startPoint);
		std::string daysCourseThree = studentData[i].substr(startPoint, endPoint - startPoint);
		std::stringstream daysCourseThreeStream(daysCourseThree);
		daysCourseThreeStream >> currentDaysInCourse[2];

		startPoint = endPoint + 1;
		endPoint = studentData[i].find(',', startPoint);
		std::string currentDegreeProgramStr = studentData[i].substr(startPoint, endPoint);
		DegreeProgram currentDegreeProgram = DegreeProgram::DEFAULT;
		if (currentDegreeProgramStr == "SECURITY")
		{
			currentDegreeProgram = DegreeProgram::SECURITY;
		}
		else if (currentDegreeProgramStr == "NETWORK")
		{
			currentDegreeProgram = DegreeProgram::NETWORK;
		}
		else if (currentDegreeProgramStr == "SOFTWARE")
		{
			currentDegreeProgram = DegreeProgram::SOFTWARE;
		}

		classRoster.add(currentStudentID, currentFirstName, currentLastName, currentEmailAddress, currentAge, currentDaysInCourse[0], currentDaysInCourse[1], currentDaysInCourse[2], i, currentDegreeProgram);
	}

	classRoster.printAll();
	
	classRoster.printInvalidEmails();

	for (int i = 0; i < classRoster.classRosterArraySize; i++)
	{
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
	}

	classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);

	classRoster.remove("A3");

	classRoster.printAll();

	classRoster.remove("A3");

	return 0;
}