//I, Caroline Huynh, declare that this work is my own. I did this work honestly and can fully stand behind
//everything that I am submitting.
//None of the code submitted is copied from another person’s work.
//Section 3A

//needed for a header file 
#ifndef _CARDS_
#define _CARDS_

//include appropriate header files 
#include<string>

class Card{
	//making variables that can be accessed by derived classes 
protected: 
	//org holds org name 
	//holder holds name of person
	//cardNumber holds number of card 
	//expirationDate holds when expiration 
	std::string org; 
	std::string holder; 
	std::string cardNumber;
	std::string expirationDate;

public:
	/*sets the name of the organization 
	@param name of organization */
	void setOrg(std::string organization);

	/*sets the name of person
@param name of person */
	void setName(std::string name);

	/*sets the card number
@param card number*/
	void setCardNum(std::string cardNum);

	/*sets the expiration date 
@param expiration date */
	void setExpDate(std::string expDate);

	/*prints a set of information retrieved from the class
	virtual because need to be able to use different versions of print for each class 
	*/
	virtual void print();
};

//making IDCard inherit the characteristics of Card 
class IDCard: public Card {

//member variables 
private:
	//DOB holds date of birth in MMDDYYYY format 
	std::string DOB; 
public:
	/*sets the date of birth 
@param date of birth */
	void setDOB(std::string dateBirth);

	/*prints a set of information that is retrieved from the corresponding class*/
	void print(); 
};

//making BankCard inherit the characteristics of Card 
class BankCard: public Card {

//member variables 
private:
	//accNum stores the account number 
	//secureCode stores the security code 
	std::string accNum; 
	std::string secureCode;

public:
	/*sets the account number 
@param account number */
	void setAccNum(std::string accountNumber);

	/*sets the security code 
@param security Code  */
	void setSecureCode(std::string securityCode);

	/*prints a set of information that is retrieved from the corresponding class*/
	void print(); 
};
#endif 
