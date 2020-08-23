//I, Caroline Huynh, declare that this work is my own. I did this work honestly and can fully stand behind
//everything that I am submitting.
//None of the code submitted is copied from another person’s work.
//Section 3A

//include appropriate header files 
#include"Cards.h"
#include<iostream>
#include<sstream>
#include<iomanip>
#include<string>

void Card::setOrg(std::string organization) {

	//sets the private variable to what the user input
	org = organization;
};
void Card::setName(std::string name) {

	//sets the private variable to what the user input
	holder = name;
};
void Card::setCardNum(std::string cardNum) {

	//sets the private variable to what the user input
	cardNumber = cardNum;
};
void Card::setExpDate(std::string expDate) {
	//sets the private variable to what the user input
	expirationDate = expDate;
};

void Card::setCurDate(std::string curDate) {
	//sets private variable to what user input for current date 
	currentDate = curDate;
};

/*@param strings representing the current date and expiration Date
@return a bool */
bool operator < (std::string curDate, std::string expDate) {

	//store the month, day and year 
	int curMonth; 
	int curDay;
	int curYear; 

	//changing type to int in order to compare 
	curMonth = stoi(curDate.substr(0, 2));
	curDay = stoi(curDate.substr(2, 2));
	curYear = stoi(curDate.substr(4));

	//store the month, day and year of the expiration date
	int expMonth; 
	int expDay; 
	int expYear; 

	//changing type to int in order to compare 
	expMonth = stoi(expDate.substr(0, 2));
	expDay= stoi(expDate.substr(2, 2));
	expYear= stoi(expDate.substr(4));

	//if the current year is less than the expiration year, indicate not expired 
	if (curYear < expYear) {
		return true; 
	}

	//if the expiration year has past, indicate expired 
	else if (expYear < curYear) {
		return false;
	}

	//if the expiration month has not passed and year is same 
	else if (curMonth < expMonth) {
		return true;
	}

	//if the expiration month has passed and year is same 
	else if (expMonth < curMonth) {
		return false;
	}

	//if the expiration day has not passed and year is same 
	else if(curDay<expDay){
		return true;
	}
	return false; 
};

/*@return statement on whether the card is expired */
void Card::expDateCheck() {

	/* if the current date is the same as its expiration date or the card doesn’t have an expiration date,
	then card is not expired */
	if (expirationDate == "N/A"|| currentDate == expirationDate || currentDate < expirationDate) {
		expStatus="No";
	}
	//else the card is expired 
	else {
		expStatus="Yes";
	}
};

void Card::print() {
	std::cout << org << '\n';
	std::cout << std::setw(20) << "Name: " << holder << std::endl;
	std::cout << std::setw(20) << "Expiration Date: " << expirationDate << '\n';
	std::cout << std::setw(20) << "If expired: " << expStatus << '\n';
	std::cout << '\n';
};

void IDCard::setDOB(std::string dateBirth) {
	//sets the private variable to what the user input
	DOB = dateBirth;
};

/*@return stores the age of the person based on a current date */
void IDCard::agePerson() {

	//store the month, day and year as int 
	int currentDateYear;
	int currentDateMonth; 
	int currentDateDay; 

	//changing the type from string to int 
	currentDateMonth = stoi(currentDate.substr(0, 2));
	currentDateDay = stoi(currentDate.substr(2, 2));
	currentDateYear = stoi(currentDate.substr(4));

	//store the month, day and year of birthday as int 
	int birthYear;
	int birthMonth; 
	int birthDay; 

	//changing the type from string to int 
	birthMonth = stoi(DOB.substr(0, 2));
	birthDay = stoi(DOB.substr(2, 2));
	birthYear = stoi(DOB.substr(4));

	//modify age 
	age = currentDateYear - birthYear;

	//if the birth month has passed or the months are equal and the birth day has passed 
	if (currentDateMonth>birthMonth || (currentDateDay>birthDay&&currentDateMonth==birthMonth) ) {
		age = age+1;
	}
	else {
		age = age;
	}

};

void IDCard::print() {
	//output the name of org 
	std::cout << org << '\n';

	//output the name with a length of 20 and whitespace before the characters 
	std::cout << std::setw(20) << "Name: " << holder << std::endl;

	//output the expiration date with a length of 20 and whitespace before the characters 
	std::cout << std::setw(20) << "Expiration Date: " << expirationDate << '\n';
	
	//output whether card is expired 
	std::cout << std::setw(20) << "If expired: " << expStatus << '\n';

	//output the date of birth with a length of 20 and whitespace before the characters 
	std::cout << std::setw(20) << "Date of birth: " << DOB << '\n';

	//output the age based on the current date
	agePerson();
	std::cout << std::setw(20) << "Age: " << age <<'\n'; 

	//new line character
	std::cout << '\n';
};


void BankCard::setAccNum(std::string accountNumber) {
	//sets the private variable to what the user input
	accNum = accountNumber;
};
void BankCard::setSecureCode(std::string securityCode) {
	//sets the private variable to what the user input
	secureCode = securityCode;
};
void BankCard::print() {
	//output name of org and new line 
	std::cout << org << '\n';

	//output the name with a length of 20 and whitespace before the characters 
	std::cout << std::setw(20) << "Name: " << holder << std::endl;

	//output the expiration date with a length of 20 and whitespace before the characters 
	std::cout << std::setw(20) << "Expiration Date: " << expirationDate << '\n';

	//output the account number with a length of 20 and whitespace before the characters 
	std::cout << std::setw(20) << "Account number: " << accNum << '\n';

	//output the security code with a length of 20 and whitespace before the characters 
	std::cout << std::setw(20) << "Security code: " << secureCode << '\n';

	//output whether card is expired 
	std::cout << std::setw(20) << "If expired: " << expStatus << '\n';

	//output new line character 
	std::cout << '\n';
};

