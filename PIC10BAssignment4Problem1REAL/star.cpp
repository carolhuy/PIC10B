//I, Caroline Huynh, declare that this work is my own. I did this work honestly and can fully stand behind
//everything that I am submitting.
//None of the code submitted is copied from another person’s work.
//Section 3A

#include<iostream>
#include<string>
#include<iomanip>

//defining the function 
void starprint(int n) {
	//base condition: do nothing if int is 0 or negative 
	if (n <= 0) {
		return;
	}

	//if int is positive 
	else {
		//call function 
		starprint(n - 1);

		//fill with number of stars as n justified to the left 
		std::cout << std::left << std::setfill(' ') << std::setw(n);
		std::cout << std::string(n, '*') << std::endl;

		//if n is not equal to 1, then use recursion to call function for previous iteration 
		if (n != 1) {
			int less = n - 1;
			starprint(less);
		}
	}
};

int main() {
	//output tells user what to do 
	std::cout << "Please enter an integer: ";
	int number;

	//user inputs number 
	std::cin >> number;

	//call function 
	starprint(number);
}
