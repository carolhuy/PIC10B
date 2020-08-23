//I, Caroline Huynh, declare that this work is my own. I did this work honestly and can fully stand behind
//everything that I am submitting.
//None of the code submitted is copied from another person’s work.
//Section 3A

//including the appropriate header files 
#include<iostream>
#include<string>
#include<vector>
#include"Student.h"
#include"StudentClub.h"

//given definition for print()
void StudentClub::print() const
{
	std::cout << std::setw(20) << "Club Name: " << name << std::endl;
	std::cout << std::setw(20) << "President Name: "
		<< get_president() << std::endl;
	std::cout << std::setw(20) << "Treasurer Name: "
		<< get_treasurer() << std::endl;
	std::cout << std::setw(20) << "Current members: "
		<< member.size() << std::endl;
};

/*@param vector of pointers to student
@return the youngest member(s) */
//returns the names of students who have the youngest age
std::vector<std::string> find_youngest(const std::vector<Student*> member) {

	//stores the names of the youngest people 
	std::vector<std::string> youngest;

	//stores the location of the people who are the youngest 
	std::vector<int> ages;

	//age of the youngest person 
	int small = (*member[0]).get_age();

	//compare the age and find where the position of the youngest members in the member vector 
	//for every object stored in vector
	for (int i = 0; i < member.size(); ++i) {

		//if the age of the member is youger than the current youngest member
		//must dereference member[i] to use functions because it is a pointer to address, not actual Student object  
		if ( (*member[i]).get_age() <= small ) {

			//update small if there is a new youngest age
			small = (*member[i]).get_age();

			//store the position of the youngest member in the vector 
			ages.push_back(i);
		}
	}

	//stores the names of youngest members
	//for however many youngest members there are 
	for (int a = 0; a < ages.size(); ++a) {

		//get the position of the youngest member
		int position = ages[a];

		//store the name of the youngest member into a vector 
		youngest.push_back((*member[position]).get_name());
	}
	return youngest;
};
/*@param pointer to Student */
void StudentClub::set_president(Student* p) {
	//set president pointer 
	president = p; 
};

/*@param pointer to Student*/
void StudentClub::set_treasurer(Student* t) {
	//set treasurer pointer 
	treasurer = t; 
};

/*@param pointer to Student*/
void StudentClub::add_member(Student* s) {
	//appends the student pointer object to vector of students called member
	member.push_back(s); 
};

//return the name of the president 
/*@return object storing president is returned */
std::string StudentClub::get_president() const {

	//dereferencing the pointer treasurer and calling the function get_name 
	//storing the result in string 
	std::string namePresident=(*president).get_name();
	return namePresident;
};

/*@return object storing president is returned */
std::string StudentClub::get_treasurer() const {

	//dereferencing the pointer treasurer and calling the function get_name 
	//storing the result in string 
	std::string nameTreasurer=(*treasurer).get_name();
	return nameTreasurer; 
};

/*@return the vector of strings that hold the members */
std::vector<Student*> StudentClub::get_member() const{
	//return member, which stores the members 
	return member;
};