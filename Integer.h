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

    private:
        unsigned int size;
        std::vector<int> num;
        bool positive;   

    public:
        // Constructors
        Integer();
        Integer(const Integer&);
        Integer(const std::string&);

        // Destructor
        ~Integer();
        
        // Accessors
        unsigned int getSize() const;
        const std::vector<int>& getNum() const;
        bool isPositive() const;

        // Mutators
        void setAllFields(unsigned int s, std::vector<int>& vec, bool pos);
        void setSize(unsigned int s);
        void setNum(const std::vector<int>& vec);
        void setPositive(bool pos);
    
        // Methods to check if an Integer is 0 or 1 e.g. num == [0] or num == [1];
        bool isZero(const Integer&);
        bool isOne(const Integer&);

        // Method to handle carry in subtraction
        std::vector<int> handleCarry(int index, const std::vector<int>& vec);

        // Assignment operator =
        Integer& operator=(const Integer&);

        // The unary operators: + and -
        Integer& operator+();
        Integer& operator-();

        // The compound assignment operators: +=, -=, *=, /=, and %=
        Integer& operator+=(const Integer& integ);
        Integer& operator-=(const Integer& integ);
        Integer& operator*=(const Integer& integ);
        Integer& operator/=(const Integer& integ);
        Integer& operator%=(const Integer& integ);
/*
        // The comparison operators: ==, !=,<,<=,>, and >=
        bool operator==(const Integer& integ);
        bool operator!=(const Integer& integ);
        bool operator<(const Integer& integ);
        bool operator<=(const Integer& integ);
        bool operator>(const Integer& integ);
        bool operator>=(const Integer& integ);
*/
    };


    // The binary arithmetic operators: 
    Integer operator+(const Integer& i1, const Integer& i2);
    Integer operator-(const Integer& i1, const Integer& i2);
    Integer operator*(const Integer& i1, const Integer& i2);
    Integer operator/(const Integer& i1, const Integer& i2);
    Integer operator%(const Integer& i1, const Integer& i2);

    
    // The comparion operators:
    bool operator<(const Integer& lhs, const Integer& rhs);
    bool operator>(const Integer& lhs, const Integer& rhs);
	bool operator<=(const Integer& lhs, const Integer& rhs);
	bool operator>=(const Integer& lhs, const Integer& rhs);
	bool operator==(const Integer& lhs, const Integer& rhs);
	bool operator!=(const Integer& lhs, const Integer& rhs);
    
    // The streaming insertion and extraction operators: << and >>
    std::ostream& operator<<(std::ostream& ostr, const Integer& integ);
	std::istream& operator>>(std::istream& istr, Integer& integ);
    
    // Returns greatest common divisor of two Integers
    Integer gcd(const Integer&, const Integer&);
}

#endif
