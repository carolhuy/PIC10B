//I, Caroline Huynh, declare that this work is my own. I did this work honestly and can fully stand behind
//everything that I am submitting.
//None of the code submitted is copied from another person’s work.
//Section 3A

//include appropriate header files 
#include<iostream>
#include<iomanip>
#include "Cards.h"
#include<vector>

int main() {
	//creating a bool to store whether program is complete 
	bool done = false;

	//stores the type of card user wants 
	int cardType;

	//vector of Card pointers to hold the information
	std::vector<Card*> vecCard;

	std::cout << "*********** Print Cards ***********\n" << '\n';

	//while the user still wants to input cards 
	while (done == false) {
		//output the information 
		std::cout << "Enter card information by selecting type (0 when done)\n";
		std::cout << "1.Basic Card \t 2. ID Card \t 3.Bank Card\n";
		std::cout << "Card type: ";

		//user inputs the type of card 
		std::cin >> cardType;

		//if user does not want to enter more cards 
		if (cardType == 0) {

			//tells that program is complete 
			done = true;

			//output new line 
			std::cout << '\n';
		}

		//if user wants Basic Card type 
		else if (cardType == 1) {
			//user can still input cards 
			done = false;

			//create a pointer of type Card 
			Card* basic = new Card;

			//variables user can input 
			std::string cardHold;
			std::string organization;
			std::string cardNum;
			std::string expDate;

			//prompt user to enter information 
			//getline allows for user to input line
			std::cout << "Card holder name: ";
			std::cin.ignore();  			//ignore new line
			std::getline(std::cin, cardHold);
			std::cout << "Organization name: ";
			std::getline(std::cin, organization);
			std::cout << "Card number: ";
			std::getline(std::cin, cardNum);
			std::cout << "Expiration date (MMDDYYY), enter N/A if none: ";
			std::getline(std::cin, expDate);
			std::cout << '\n';

			//store the information in the Card 
			basic->setName(cardHold);
			basic->setOrg(organization);
			basic->setCardNum(cardNum);
			basic->setExpDate(expDate);

			//store in vector 
			vecCard.push_back(basic);
		}

		//if ID Card 
		else if (cardType == 2) {

			//variables user can input
			std::string org;
			std::string holder;
			std::string cardNumber;
			std::string expirationDate;
			std::string DOB;

			//create a pointer of type ID, in order to use the setDOB function 
			IDCard* ID = new IDCard;

			//prompt user to enter information 
			//getline allows for user to input line
			std::cout << "Card holder name: ";
			std::cin.ignore();			//ignore new line
			std::getline(std::cin, holder);
			std::cout << "Organization name: ";
			std::getline(std::cin, org);
			std::cout << "Card number: ";
			std::getline(std::cin, cardNumber);
			std::cout << "Expiration date (MMDDYYY), enter N/A if none: ";
			std::getline(std::cin, expirationDate);
			std::cout << "Date of Birth (MMDDYYYY): ";
			std::getline(std::cin, DOB);
			std::cout << '\n';

			//store the information in ID
			ID->setName(holder);
			ID->setOrg(org);
			ID->setCardNum(cardNumber);
			ID->setExpDate(expirationDate);
			ID->setDOB(DOB);
			//ID->agePerson(); //there exists no current date at this point to compare to 

			//store in vector 
			vecCard.push_back(ID);
		}

		//if Bank Card 
		else if (cardType == 3) {

			//variables user can input
			std::string cardHold;
			std::string organization;
			std::string cardNum;
			std::string expDate;
			std::string accountNum;
			std::string securityCode;

			//create a pointer of type BankCard in order to use functions setAccNum and setSecureCode
			BankCard* bank = new BankCard;

			//prompt user to enter information 
			//getline allows for user to input line
			std::cout << "Card holder name: ";
			std::cin.ignore(); 			//ignore new line
			std::getline(std::cin, cardHold);
			std::cout << "Organization name: ";
			std::getline(std::cin, organization);
			std::cout << "Card number: ";
			std::getline(std::cin, cardNum);
			std::cout << "Expiration date (MMDDYYY), enter N/A if none: ";
			std::getline(std::cin, expDate);
			std::cout << "Account number: ";
			std::getline(std::cin, accountNum);
			std::cout << "Security code: ";
			std::getline(std::cin, securityCode);
			std::cout << '\n';

			//store the information in bank
			bank->setName(cardHold);
			bank->setOrg(organization);
			bank->setCardNum(cardNum);
			bank->setExpDate(expDate);
			bank->setAccNum(accountNum);
			bank->setSecureCode(securityCode);

			//store in vector 
			vecCard.push_back(bank);
		}
	}

	//prompts the user to input the current date
	std::string currentDate; 
	std::cout << "Please enter today's date (MMDDYYYY): "; 
	std::cin >> currentDate; 
	std::cout << '\n';

	//for each member in the vector 
	for (int i = 0; i < vecCard.size(); i++) {

		//store current date within each class
		vecCard[i]->setCurDate(currentDate);

		//check whether card is expired 
		vecCard[i]->expDateCheck();

		//print the information in the element
		vecCard[i]->print();

		//delete the pointer to prevent memory leak 
		delete vecCard[i];
	}
	return 0;
}