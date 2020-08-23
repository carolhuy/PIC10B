#include "Student.h"

Student::Student(std::string n, int y)
{
	name = n;
	age = y;
}

std::string Student::get_name() const
{
	return name;
}

int Student::get_age() const
{
	return age;
}

