#include "roster.h"
#include "degree.h"
#include <iostream>

//Constructors
Roster::Roster()
{
	
}

//Functions
void Roster::add
	(
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
	)
{
	int daysInCourse[] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	Student* newStudent = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);
	classRosterArray[arrayLocation] = newStudent;
}

void Roster::remove(std::string studentID)
{
	bool studentFound = false;
	for (int i = 0; i < classRosterArraySize; i++)
	{
		if (classRosterArray[i] != NULL)
		{
			std::string targetStudentID = classRosterArray[i]->getStudentID();
			if (targetStudentID == studentID)
			{
				studentFound = true;
				for (int l = classRosterArraySize - 1; l > i; l--)
				{
					if (classRosterArray[l] != NULL)
					{
						classRosterArray[i] = classRosterArray[l];
						classRosterArray[l] = NULL;
						return;
					}
				}
			}
		}
	}

	if (studentFound == false)
	{
		std::cout << "\nError: A Student with this Student ID has not been found.";
	}
}

void Roster::printAll()
{
	for (int i = 0; i < classRosterArraySize; i++)
	{
		if (classRosterArray[i] != NULL)
		{
			classRosterArray[i]->printStudentData();
		}
	}
	std::cout << std::endl;
}

void Roster::printAverageDaysInCourse(std::string studentID)
{
	bool studentFound = false;
	int daysCourseOne = 0;
	int daysCourseTwo = 0;
	int daysCourseThree = 0;
	int sum;
	double averageDays;
	std::string targetStudentID;
	for (int i = 0; i < classRosterArraySize; i++)
	{
		targetStudentID = classRosterArray[i]->getStudentID();
		if (targetStudentID == studentID)
		{
			studentFound = true;
			daysCourseOne = classRosterArray[i]->getDaysInCourse()[0];
			daysCourseTwo = classRosterArray[i]->getDaysInCourse()[1];
			daysCourseThree = classRosterArray[i]->getDaysInCourse()[2];
			sum = daysCourseOne + daysCourseTwo + daysCourseThree;
			averageDays = sum / 3;
			std::cout << "\nStudent " << targetStudentID << " will spend an average of " << averageDays << " days in each course.";
		}
	}
	if (studentFound == false)
	{
		std::cout << "\nError: A Student with this Student ID has not been found.";
	}
	
	
}

void Roster::printInvalidEmails()
{
	for (int i = 0; i < classRosterArraySize; i++)
	{
		bool containsAt = false;
		bool containsPeriod = false;
		bool containsSpace = false;
		bool emailInvalid = false;
		std::string targetEmail = classRosterArray[i]->getEmailAddress();
		if (targetEmail.find('@') != std::string::npos)
		{
			containsAt = true;
		}
		if (targetEmail.find('.') != std::string::npos)
		{
			containsPeriod = true;
		}
		if (targetEmail.find(' ') != std::string::npos)
		{
			containsSpace = true;
		}
		if ((!containsAt) || (!containsPeriod) || (containsSpace))
		{
			emailInvalid = true;
		}
		if (emailInvalid)
		{
			std::cout << "\nStudent " << classRosterArray[i]->getStudentID() << " has an invalid Email Address: " << targetEmail << std::endl;
		}
	}
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
	for (int i = 0; i < classRosterArraySize; i++)
	{
		if (classRosterArray[i]->getDegreeProgram() == degreeProgram)
		{
			classRosterArray[i]->printStudentData();
		}
	}
}

//Destructor
Roster::~Roster()
{
	for (int i = 0; i < classRosterArraySize; i++)
	{
		if (classRosterArray[i] != NULL)
		{
			delete classRosterArray[i];
		}
	}
}