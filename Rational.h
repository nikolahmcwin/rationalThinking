#pragma once

#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <string>
#include "Integer.h"

/**
 * Rational.h for E9 COSC326
 * @author Finn Luxton and Nikolah Pearce
 */

namespace cosc326 {

    class Rational {

    private:
        bool pos;
        Integer num;
        Integer den;
        Integer whole;
        
    public: 
        // Constructors
 		Rational();
        Rational(const std::string& str);
        Rational(const Rational& r);
        Rational(const Integer& a); 
        Rational(const Integer& a, const Integer& b);
        Rational(const Integer& a, const Integer& b, const Integer& c);

        // Deconstructor
        ~Rational();

        // Accessors
        const Integer& getNum() const;
        const Integer& getDen() const;
        const Integer& getWhole() const;
        bool isPos() const;

        // Mutators
        void setAllFields(const Integer&, const Integer&, const Integer&, bool p);
        void setNum(const Integer&);
        void setDen(const Integer&);
        void setWhole(const Integer&);
        void setPos(bool p);

        // The assignment operator =
        Rational& operator=(const Rational& r);
        
		// Unary operators
		Rational operator-() const;
		Rational operator+() const;
	   
        // Arithmetic assignment operators
		Rational& operator+=(const Rational& r);
		Rational& operator-=(const Rational& r);
		Rational& operator*=(const Rational& r);
		Rational& operator/=(const Rational& r);
    };

    // Helper method to simplify
    Rational simplify(const Rational& r); 
    // Helper method to UNsimplify
    Rational unsimplify(const Rational& r);
    // Helper method to check if simplified
    bool isSimplified(const Rational& r);

	// Binary operators
	Rational operator+(const Rational& lhs, const Rational& rhs); // lhs + rhs;
	Rational operator-(const Rational& lhs, const Rational& rhs); // lhs - rhs;
	Rational operator*(const Rational& lhs, const Rational& rhs); // lhs * rhs;
	Rational operator/(const Rational& lhs, const Rational& rhs); // lhs / rhs;
	
	std::ostream& operator<<(std::ostream& os, const Rational& i);  // std::cout << i << std::endl;
	std::istream& operator>>(std::istream& is, Rational& i);        // std::cin >> i;

    bool operator<(const Rational& lhs, const Rational& rhs);
	bool operator>(const Rational& lhs, const Rational& rhs); // lhs > rhs
	bool operator<=(const Rational& lhs, const Rational& rhs); // lhs <= rhs
	bool operator>=(const Rational& lhs, const Rational& rhs); // lhs >= rhs
	bool operator==(const Rational& lhs, const Rational& rhs); // lhs == rhs
	bool operator!=(const Rational& lhs, const Rational& rhs); // lhs != rhs

}

#endif
