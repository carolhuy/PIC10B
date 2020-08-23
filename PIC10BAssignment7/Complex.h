//I, Caroline Huynh, declare that this work is my own. I did this work honestly and can fully stand behind
//everything that I am submitting.
//None of the code submitted is copied from another person’s work.
//Section 3A

#include<iostream>
#include<fstream>

#ifndef _COMPLEX_
#define _COMPLEX_

class Complex {
private: 

	//stores the values for the real and imaginary number 
	double realNum; 
	double imagin; 

public:

	/*
	Constructs a complex number with only a real number 
	@param a for the real number 
	*/
	Complex(double a);

	/*
	Constructs a complex number with real and imaginary number 
	@param r for real 
	@param i for imaginary 
	*/
	Complex(double r, double i);

	/*
	returns the value of real number
	*/
	double real() const;

	/*
	returns the value of imaginary number
	*/
	double imag() const;

	/*
	Adds a number to the Complex  
	@return updated value
	@param double to add to Complex 
	*/
	Complex& operator+=(double toAdd);

	/*Increments real number portion by one */

	//prefix form 
	Complex operator++(); 

	//postfix form 
	Complex operator++(int postFix); 

};

//Declaring non-member function operators 

	/*Adds two Complex variables
	@return updated Complex variable
	@param Complex variable
	@param Complex variable
	*/
	Complex operator+(const Complex& left, const Complex& right);

	/*
	Subtracts two Complex variables
	@return updated Complex variable
	@param Complex variable
	@param Complex variable
	*/
	Complex operator-(const Complex& left, const Complex& right);

	/*
	Multiples two Complex variables
	@param Complex variable
	@param Complex variable
	*/
	Complex operator*(const Complex& left, const Complex& right);

	/*
	Divides two Complex variables
	@return updated Complex variable
	@param Complex variable
	@param Complex variable
	*/
	Complex operator/(const Complex& left, const Complex& right);

	/*
	Outputs Complex variables 
	@return ostream to display Complex variable 
	@param reference to ostream 
	@param Complex variable
	*/
	std::ostream& operator<<(std::ostream& out, const Complex& variable);

	/*
	Negates Complex variable
	@return updated Complex variable
	@param Complex variable
	*/
	Complex operator-(const Complex& negative);

#endif 