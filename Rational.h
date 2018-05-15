#pragma once

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
        bool positive;
        Integer numerator;
        Integer denominator;
        
    public: 
        // Constructors
        // Creates rational with value of 0
        Rational();
        // Creates rational that duplicates the provided rational
        Rational(const Rational& rat);
        // Takes in Integer with result r1 = a
        Rational(const Integer&);
        // Takes in Integers with result r2 = a/b
        Rational(const Integer&, const Integer&);
        // Takes in Integers with result r3 = a + b/c
        Rational(const Integer&, const Integer&, const Integer&);
        // Constructs with a string parameter
        Rational(const std::string& str);

        // Deconstructor
        ~Rational();

        // Getters
        const Integer& getNumerator() const;
        const Integer& getDenominator() const;
        bool getRatSign() const;

/*
        // Assignment operator =
        Rational& operator=(const Rational& rat);

        // The unary operators: + and -
        Rational& operator+();
        Rational& operator-();

        // The inequal binary arithmetic operators /, and %
        Rational& operator/(const Rational& rat);
        Rational& operator%(const Rational& rat);

        // The compound assignment operators: +=, -=, *=, /=, and %=
        Rational& operator+=(const Rational& rat);
        Rational& operator-=(const Rational& rat);
        Rational& operator*=(const Rational& rat);
        Rational& operator/=(const Rational& rat);
        Rational& operator%=(const Rational& rat);

        // The comparison operators: ==, !=,<,<=,>, and >=
        bool operator==(const Rational& rat);
        bool operator!=(const Rational& rat);
        bool operator<(const Rational& rat);
        bool operator<=(const Rational& rat);
        bool operator>(const Rational& rat);
        bool operator>=(const Rational& rat);
*/
    };

    // The equal-either-way binary arithmetic operators: +, -, *
    Rational operator+(const Rational& rat1, const Rational& rat2);
    Rational operator-(const Rational& rat1, const Rational& rat2);
    Rational operator*(const Rational& rat1, const Rational& rat2);


    // The streaming insertion and extraction operators: << and >>
    std::ostream& operator<<(std::ostream& ostr, const Rational& rat);
	std::istream& operator>>(std::istream& istr, Rational& rat);

}
