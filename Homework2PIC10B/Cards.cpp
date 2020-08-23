//I, Caroline Huynh, declare that this work is my own. I did this work honestly and can fully stand behind
//everything that I am submitting.
//None of the code submitted is copied from another person’s work.
//Section 3A

//include appropriate header files 
#include"Cards.h"
#include<iostream>
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
void Card::print() {
	std::cout << org<<'\n';
	std::cout << std::setw(20) << "Name: " << holder << std::endl;
	std::cout << std::setw(20) << "Expiration Date: " << expirationDate << '\n';
	std::cout << '\n';
};

void IDCard::setDOB(std::string dateBirth) {
	//sets the private variable to what the user input
	DOB = dateBirth;
};
void IDCard::print() {
	//output the name of org 
	std::cout << org << '\n';

	//output the name with a length of 20 and whitespace before the characters 
	std::cout << std::setw(20) << "Name: " << holder << std::endl;

	//output the expiration date with a length of 20 and whitespace before the characters 
	std::cout << std::setw(20) << "Expiration Date: " << expirationDate << '\n';
	
	//output the date of birth with a length of 20 and whitespace before the characters 
	std::cout << std::setw(20) << "Date of birth: " << DOB << '\n';

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

	//output new line character 
	std::cout << '\n';
}; 

