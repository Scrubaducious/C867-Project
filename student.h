#pragma once
#include "degree.h"
#include <string>

class Student
{
private:
	std::string studentID, firstName, lastName, emailAddress;
	int age = 0;
	static const int daysInCourseSize = 3;
	int* daysInCourse;
	DegreeProgram degreeProgram = DegreeProgram::DEFAULT;

public:
	//Constructors
	Student();
	Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram);

	//Accessors
	const std::string getStudentID();
	const std::string getFirstName();
	const std::string getLastName();
	const std::string getEmailAddress();
	const int getAge();
	const int* getDaysInCourse();
	DegreeProgram getDegreeProgram();

	//Mutators
	void setStudentID(std::string studentID);
	void setFirstName(std::string firstName);
	void setLastName(std::string lastName);
	void setEmailAddress(std::string emailAddress);
	void setAge(int age);
	void setDaysInCourse(int daysInCourse[]);
	void setDegreeProgram(DegreeProgram degreeProgram);

	//Print function
	void printStudentData();

	//Destructor
	~Student();
};