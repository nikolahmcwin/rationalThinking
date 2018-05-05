#pragma once

#include <iostream>
#include <string>
// A bit like a package in Java
// There is a std::Complex, but this is cosc326::Complex

namespace cosc326 {

	class Complex {

	public:

		// Constructors
		Complex();
		Complex(double real);
		Complex(double real, double imag);
		// Just takes a string, std::string
		// The & means a reference, like a pointer but can't do the pointer shit. 
		// No add or minus to move around Array
		// Typically use a & when pass in cos it then can not store the whole thing but still read the value
		// Use const so you can't change it and get lost
		Complex(const std::string& str); // eg: "-3.1+4.3i"
		//Called a copy constructor
		Complex(const Complex& comp);


		// A destructor to clean up anything done e.g. memory allocating. 
		// We won't really do much though.
		// This will be called as soon as the object is out of way. ASAP.
		~Complex();


		// operator overloading. Allow you to define what happens when you 
		// see these particular operators.
		// Can only overload existing operators in C++. 
		// Because they are part of core language infrastructure

		// The '=' operator.
		// Takes an operator on this side, again it will be constant
		// 'a.operator=(b)' == 'a = b' they are the same thing!
		Complex& operator=(const Complex& comp);

		//'a.operator+=(b)' == 'a += b' they are the same thing!
		Complex& operator+=(const Complex& comp);

		// 'a.operator*=(b)' == 'a *= b' they are the same thing!
		Complex& operator*=(const Complex& comp);


		double getRealPart() const;
		double getImagPart() const;

	private:
		double real_;
		double imag_;
	};

	// These aren't defined inside the class.
	// This is not like a.operator+(b), bad to do cos each a and b are equal in the addition
	Complex operator+(const Complex& c1, const Complex& c2);
	Complex operator*(const Complex& c1, const Complex& c2);


	// Streaming operators (bit shift operators in C) 
	// the input output methods
	// To write to a file. Think of it like moving stuff to the stdout e.g. terminal
	// Can overload for the complex type but
	std::ostream& operator<<(std::ostream& ostr, const Complex& comp);
	std::istream& operator>>(std::istream& istr, Complex& comp);
}