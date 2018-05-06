#pragma once

#ifndef INTEGER_H
#define INTEGER_H

#include <iostream>
#include <string>
#include <vector>

/**
 * Integer.h for E9 COSC326
 * @author Finn Luxton and Nikolah Pearce
 */

namespace cosc326 {

    class Integer {

    public:
        // Constructors
        Integer();
        //Integer(const Integer& integ);
        //Integer(const std::string& str);

        Integer(const Integer&);
        Integer(const std::string&);

        // Destructor
        ~Integer();
/*
        // Assignment operator =
        Integer& operator=(const Integer& integ);

        // The unary operators: + and -
        Integer& operator+(const Integer& integ);
        Integer& operator-(const Integer& integ);

        // The inequal binary arithmetic operators /, and %
        Integer& operator/(const Integer& integ);
        Integer& operator%(const Integer& integ);

        // The compound assignment operators: +=, -=, *=, /=, and %=
        Integer& operator+=(const Integer& integ);
        Integer& operator-=(const Integer& integ);
        Integer& operator*=(const Integer& integ);
        Integer& operator/=(const Integer& integ);
        Integer& operator%=(const Integer& integ);

        // The comparison operators: ==, !=,<,<=,>, and >=
        Integer& operator==(const Integer& integ);
        Integer& operator!=(const Integer& integ);
        Integer& operator<(const Integer& integ);
        Integer& operator<=(const Integer& integ);
        Integer& operator>(const Integer& integ);
        Integer& operator>=(const Integer& integ);

        // Afunction,gcd(a,b),thatreturnsthegreatestcommondivisoroftwoIntegers
        
        int gcd(unsigned int a, unsigned int b) const;
        */

        int getDigits() const;
        std::vector<int> getNum();
        bool isPositive() const;

        //int getNum() const;
    private:
        //int num_;

        //Working with vectors we'd need...
        int digits;
        std::vector<int> num;
        int carry;
        bool positive;    
    };
/*
    // The equal-either-way binary arithmetic operators: +, -, *
    Integer operator+(const Integer& i1, const Integer& i2);
    Integer operator-(const Integer& i1, const Integer& i2);
    Integer operator*(const Integer& i1, const Integer& i2);
*/
    // The streaming insertion and extraction operators: << and >>
    std::ostream& operator<<(std::ostream& ostr, const Integer& integ);
	std::istream& operator>>(std::istream& istr, Integer& integ);

}

#endif
