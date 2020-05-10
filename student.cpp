#include "student.h"
#include <iostream>

//Constructor Definitions
Student::Student()
{

}

Student::Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram)
	//: studentID(studentID), firstName(firstName), lastName(lastName), emailAddress(emailAddress), age(age), daysInCourse(new int(daysInCourseSize))
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	this->daysInCourse = new int[daysInCourseSize];
	this->degreeProgram = degreeProgram;

	for (int i = 0; i < daysInCourseSize; i++)
	{
		this->daysInCourse[i] = daysInCourse[i];
	}
}

//Accessor Definitions
const std::string Student::getStudentID()
{
	return studentID;
}

const std::string Student::getFirstName()
{
	return firstName;
}

const std::string Student::getLastName()
{
	return lastName;
}

const std::string Student::getEmailAddress()
{
	return emailAddress;
}

const int Student::getAge()
{
	return age;
}

const int* Student::getDaysInCourse()
{
	return daysInCourse;
}

DegreeProgram Student::getDegreeProgram()
{
	return degreeProgram;
}

//Mutator Definitions
void Student::setStudentID(std::string studentID)
{
	this->studentID = studentID;
}

void Student::setFirstName(std::string firstName)
{
	this->firstName = firstName;
}

void Student::setLastName(std::string lastName)
{
	this->lastName = lastName;
}

void Student::setEmailAddress(std::string emailAddress)
{
	this->emailAddress = emailAddress;
}

void Student::setAge(int age)
{
	this->age = age;
}

void Student::setDaysInCourse(int daysInCourse[])
{
	this->daysInCourse = new int(daysInCourseSize);
}

void Student::setDegreeProgram(DegreeProgram degreeProgram)
{
	this->degreeProgram = degreeProgram;
}

//Print Function
void Student::printStudentData()
{
	std::cout << "\n\nStudent ID: " + getStudentID();
	std::cout << "\nFirst Name: " + getFirstName();
	std::cout << "\nLast Name: " + getLastName();
	std::cout << "\nEmail Address: " + getEmailAddress();
	std::cout << "\nAge: " << getAge();

	const int* days = getDaysInCourse();
	std::cout << "\nDays In Course: " << days[0] << ", " << days[1] << ", " << days[2];
	switch (getDegreeProgram())
	{
	case DegreeProgram::NETWORK:
		std::cout << "\nDegree Program: NETWORK";
		break;
	case DegreeProgram::SECURITY:
		std::cout << "\nDegree Program: SECURITY";
		break;
	case DegreeProgram::SOFTWARE:
		std::cout << "\nDegree Program: SOFTWARE";
		break;
	default:
		std::cout << "\nDegree Program: DEFAULT";
	}
}

//Deconstructor Definition
Student::~Student()
{

}