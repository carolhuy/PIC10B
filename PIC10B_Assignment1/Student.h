#pragma once
#ifndef __STUDENT_H__
#define __STUDENT_H__

#include<string>
#include<vector>
#include<iomanip>
#include<iostream>

class Student
{
private:
	std::string name;
	int age;
public:
	Student(std::string n, int y);
	std::string get_name() const;
	int get_age() const;
};


#endif
