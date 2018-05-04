#pragma once

#include <iostream>
#include <string>
namespace cosc326 {

	class Complex {

	public:

		// Constructors
		Complex();
		Complex(double real);
		Complex(double real, double imag);
		Complex(const std::string& str); // eg: "-3.1+4.3i"
		Complex(const Complex& comp);

		~Complex();

		Complex& operator=(const Complex& comp);

		Complex& operator+=(const Complex& comp);
		Complex& operator*=(const Complex& comp);

		double getRealPart() const;
		double getImagPart() const;

	private:
		double real_;
		double imag_;
	};


	Complex operator+(const Complex& c1, const Complex& c2);
	Complex operator*(const Complex& c1, const Complex& c2);

	std::ostream& operator<<(std::ostream& ostr, const Complex& comp);
	std::istream& operator>>(std::istream& istr, Complex& comp);
}