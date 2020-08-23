//I, Caroline Huynh, declare that this work is my own. I did this work honestly and can fully stand behind
//everything that I am submitting.
//None of the code submitted is copied from another person’s work.
//Section 3A

#ifndef __STUDENTCLUB_H__
#define __STUDENTCLUB_H__
#include<iostream>
#include<string>
#include<vector>
#include"Student.h"

class StudentClub {
private:
	//stores name of student club 
	std::string name;

	//points to the student object for president 
	Student* president;
	
	//points to the student object for president 
	Student* treasurer;

	//vector of pointers to student objects for the members 
	std::vector<Student*> member;

public:
//create a student club with a name 
	StudentClub(std::string n) : name(n), president(nullptr), treasurer(nullptr), member{} {}

//create a student club with a name, president, treasurer, and members 
	StudentClub(std::string n, Student* p, Student* t, std::vector<Student*> m) : name(n), president(p), treasurer(t), member(m.begin(),m.end()){}

/*@return outputs the club and its member information*/
	void print() const;

/*@return object storing president is returned */
	std::string get_president() const;

/*@return object storing president is returned */
	std::string get_treasurer() const;

/*@return the vector of strings that hold the members */
	std::vector<Student*> get_member() const;

/*@param pointer to Student 
	sets the president */
	void set_president(Student* p);

/*@param pointer to Student
		sets the treasurer*/
	void set_treasurer(Student* t);

/*@param pointer to Student 
		appends the student pointer object to vector of students called member*/
	void add_member(Student* s);

};

//remove from class because main does not call math.find_youngest 
//find_youngest is not defined and cannot be used without class 

/*@param vector of pointers to student
@return the name of the youngest member(s) */
std::vector<std::string> find_youngest(const std::vector<Student*> member);

#endif