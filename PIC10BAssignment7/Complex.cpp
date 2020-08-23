//I, Caroline Huynh, declare that this work is my own. I did this work honestly and can fully stand behind
//everything that I am submitting.
//None of the code submitted is copied from another person’s work.
//Section 3A

//including all necessary header files 
#include<iostream>
#include<fstream>
#include "Complex.h"

//initializing constructors 

//Constructor 1: if there is no imaginary number 
Complex::Complex(double a):realNum(a),imagin(0) {};

//Constructor 2: has real and imaginary number 
Complex::Complex(double r, double i) : realNum(r), imagin(i){};

//defining member functions 

double Complex::real() const{

	//return the real number stored 
	return realNum;
};

double Complex::imag() const{

	//return the imaginary number stored 
	return imagin;
};

//adds to the real number 
Complex& Complex::operator+=(double toAdd) {
	//update the real number with the sum of the real number and the double 
	//use this because it is calling the pointer to the Complex object 
	this->realNum = this->realNum + toAdd; 

	//returns the updated Complex object 
	return *this; 
};

//prefix form 
Complex Complex::operator++() {
	//makes a Complex object to store the original value (before addition)
	Complex preFix(realNum, imagin);

	//update the value in the new object with one more than the original 
	preFix.realNum = ++realNum;

	//return updated value 
	return preFix; 
};

//postfix form - int tells the compiler this is the definition for post-fix 
Complex Complex::operator++(int postFix) {
	//makes a Complex object to store the original value (before addition)
	Complex postVersion(realNum,imagin);

	//make the real number stored in postVersion one more than the real number entered 
	postVersion.realNum=realNum++; 

	//return the updated value (updates after ++) 
	return postVersion;
}; 

//Defining non-member function operators

//defining the non member function for addition operator 
Complex operator+(const Complex& left, const Complex& right) {
	double realNumber;
	double imagNumber;
	realNumber = left.real() + right.real();
	imagNumber = left.imag() + right.imag();
	Complex result(realNumber,imagNumber);
	return result;
};

//defining the non member function for subtraction operator 
Complex operator-(const Complex& left, const Complex& right) {

	//creating variables to store the real and imaginary values 
	double realNumber;
	double imagNumber;

	//formulas to calculate the real and imaginary numbers 
	realNumber = left.real() - right.real();
	imagNumber = left.imag() - right.imag();

	//creating a Complex object with the calculated values 
	Complex result(realNumber,imagNumber);

	//return the updated Complex object
	return result; 
};

//defining the non member function for multiplication operator 
Complex operator*(const Complex& left, const Complex& right) {

	//creating variables to store the real and imaginary values 
	double realNumber;
	double imagNumber;

	//formulas to calculate the real and imaginary numbers 
	realNumber = (left.real() * right.real()) - (left.imag() *right.imag());
	imagNumber = (left.imag()*right.real()) + (left.real() *right.imag());

	//creating a Complex object with the calculated values 
	Complex result(realNumber, imagNumber);

	//return the updated Complex object
	return result;
};

//defining the non member function for division operator 
Complex operator/(const Complex& left, const Complex& right) {

	//creating variables to store the real and imaginary values 
	double realNumber;
	double imagNumber;

	//formulas to calculate the real and imaginary numbers 
	realNumber = ((left.real() * right.real()) + (left.imag() * right.imag()))/((right.real() *right.real())+(right.imag() *right.imag()));
	imagNumber = ((left.imag() * right.real()) - (left.real() * right.imag()))/ ((right.real() * right.real()) + (right.imag() * right.imag()));
	
	//creating a Complex object with the calculated values
	Complex result(realNumber, imagNumber);

	//return the updated Complex object
	return result;
};

//negates the signs of the real and imaginary numbers 
Complex operator-(const Complex& negative) {

	//creating variables to store the updated values 
	double newNegative;
	double newImagin;

	//storing the new negative values  
	newNegative = -negative.real();
	newImagin = -negative.imag();

	//creating a new object with the negative values 
	Complex newNeg(newNegative, newImagin);

	//return the object
	return newNeg; 
};

//defining the output operator 
std::ostream& operator<<(std::ostream& out, const Complex& variable) {

	//creating variables to store the real and imaginary numbers 
	double realTestNum=variable.real(); 
	double realImagNum = variable.imag();

	//different parameters to print 

	//if the real number is equal to zero 
	if (realTestNum == 0) {
		out << realImagNum << "i";
		return out;
	}

	//if the imaginary number is zero 
	else if (realImagNum==0) {
		out << realTestNum;
		return out;
	}

	//if the imaginary number is between zero and one 
	else if (realImagNum>0 && realImagNum < 1) {
		out << realTestNum << "+" << realImagNum << "i";
		return out;
	}

	//if the imaginary number is one 
	else if (realImagNum == 1) {
		out << realTestNum << "+i";
		return out;
	}

	//if the imaginary number is greater than one 
	else if (realImagNum > 1) {
		out << realTestNum << "+" << realImagNum << "i";
		return out;
	}

	//if the imaginary number is between negative one and zero 
	else if (-1 < realImagNum && realImagNum < 0) {
		out << realTestNum << realImagNum << "i";
		return out;
	}

	//if the imaginary number is equal negative one 
	else if (realImagNum == -1) {
		out << realTestNum << "-i";
		return out;
	}

	//if the imaginary number is less than negative one 
	else if (realImagNum < -1) {
		out << realTestNum << realImagNum<<"i";
		return out;
	}
};