
#include "Integer.h"

/**
 * Integer.cpp for E9 COSC326
 * @author Finn Luxton and Nikolah Pearce
 */

namespace cosc326 {

    // Default constructor 
    Integer::Integer() {
        num.push_back(0);
        carry = 0;
        size = num.size();
    }

    // Copy constructor that duplicates the provided Integer
    Integer::Integer(const Integer& integ) {
        num = integ.num;
        size = num.size();
        carry = integ.carry;
        positive = integ.positive; 
    }


    // Constructor that takes a std::String of digits (possibility starts with a + or -)
    Integer::Integer(const std::string& str) {
        //num_ = std::atof(str.c_str());
        // is it positive or negative?
    }

    // Destructor
    Integer::~Integer() {

    }

    // Unary Operator +

    // Unary Operator -

    // Binary arithmetic operator +

    // Binary arithmetic operator -

    // Binary arithmetic operator *

    // Binary arithmetic operator /

    // Binary arithmetic operator %

    // Compound assignment operator +=

    // Compound assignment operator -=

    // Compound assignment operator *=

    // Compound assignment operator /=

    // Compound assignment operator %=

    // Comparison operators ==

    // Comparison operators !=

    // Comparison operators <

    // Comparison operators <=

    // Comparison operators >

    // Comparison operators >=

    // Streaming insertion operator <<
	std::ostream& operator<<(std::ostream& ostr, const Integer& integ) {
        //ostr << integ.getNum();
        std::string numString;
        std::vector<int> n = integ.getNum();

        for (unsigned int i = 0; i < integ.getSize(); ++i)
            numString += std::to_string(n[i]);

        ostr << numString;
        //ostr << "This is a test case" <<  "+ 12345";
		return ostr;
	}

    // Streaming extraction operator >>
	std::istream& operator>>(std::istream& istr, Integer& integ) {
		std::string strValue;
		istr >> strValue;
		integ = Integer(strValue);
		return istr;
	}

    // gdc(a, b) which returns greatest common divisor of a and b
    /*unsigned int gdc (unsigned int a, unsigned int b){
        unsigned int tmp;
        while(b != 0) {
            tmp = a;
            a = b;
            b = tmp % b;
        }
        return a;
    }*/
    
    unsigned int Integer::getSize() const {
        return size;
    }

    const std::vector<int>& Integer::getNum() const {
        return num;
    }

    bool Integer::isPositive() const {
        return positive;
    }

}

