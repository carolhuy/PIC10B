//I, Caroline Huynh, declare that this work is my own. I did this work honestly and can fully stand behind
//everything that I am submitting.
//None of the code submitted is copied from another person’s work.
//Section 3A

//including the appropriate header files 
#include<iostream>
#include<fstream>
#include<vector>
#include<iomanip>

//defining the recursive function 
/*@param double for base, int for exponent*/
double mypower(double x, int n) {

	//creating a double that stores 1 
	double myResult=1.0;

	//base condition - if the exponent is equal to 0, then return 1 
	if (n == 0) {
		return 1; 
	}

	//if the exponenet is greater than 0 
	if (n > 0) {
		//multiply x the n number of times 
		myResult = x * mypower(x, n-1);

		//return result stored 
		return myResult;
	}

	if (n < 0) {
		//if negative exponent, then increase the power until reach n=0
		//then divide result by 1 
		myResult = 1/ x * mypower(x, n + 1);

		//return the result stored 
		return myResult; 
	}
};

int main() {
	
	//storing a vector that has the desired exponenets 
	std::vector<int> storage {-5,-4,-3,-2,-1,0,1,2,3,4};

	//creating an output file stream 
	std::ofstream oss; 

	//creating a file to write the data to 
	oss.open("powers.txt");

	//storing the base number 
	double pi = 3.14; 

	//write the data to the file 
	for (int i = 0; i < storage.size(); ++i) {

		//calling the recursive function 
		double finalResult = mypower(pi, storage[i]);

		//output the result to the file 
		oss << std::fixed << std::setprecision(5) << finalResult << '\n';
	}

	//close the file 
	oss.close();

	return 0; 
}