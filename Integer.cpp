#include <iostream>
#include <string>
#include "Integer.h"

/**
 * Integer.cpp for E9 COSC326
 * @author Finn Luxton and Nikolah Pearce
 */

namespace cosc326 {

    //Default constructor 
	Integer::Integer() : num_(0) {
        
    }

    //Copy constructor that duplicates the provided Integer
    Integer::Integer(const Integer& integ) : num_(integ.num_) {

    }

    //Constructor that takes a std::String of digits (possibility starts with a + or -)
    Integer::Integer(const std::string& str) : num_(0) {
        //real_ = = std::atof(str.c_str());

        // is it positive or negative?

        // Do we have any '/' e.g. fractions

        // Do we have a '.' e.g. floating point
    }

    //Destructor
    Integer::~Integer() {

    }

    //Unary Operator +

    //Unary Operator -

    //Binary arithmetic operator +

    //Binary arithmetic operator -

    //Binary arithmetic operator *

    //Binary arithmetic operator /

    //Binary arithmetic operator %

    //Compound assignment operator +=

    //Compound assignment operator -=

    //Compound assignment operator *=

    //Compound assignment operator /=

    //Compound assignment operator %=

    //Comparison operators ==

    //Comparison operators !=

    //Comparison operators <

    //Comparison operators <=

    //Comparison operators >

    //Comparison operators >=

    //Streaming insertion operator <<
	std::ostream& operator<<(std::ostream& ostr, const Integer& integ) {
		ostr << integ.getNum();
		return ostr;
	}

     //Streaming extraction operator >>
	std::istream& operator>>(std::istream& istr, Integer& integ) {
		std::string value;
		istr >> value;
		integ = Integer(value);
		return istr;
	}
   

    //gdc(a, b) which returns greatest common divisor of a and b

    int Integer::getNum() const {
		return num_;
	}
}

