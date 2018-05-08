
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
        std::string tempStr;
        int temp, i, len;

        // Find and ignore any trailing 
        if (str.find('-') != std::string::npos) {
            std::cout << "String is negative baby!" << std::endl;
            i = 1;
            positive = false;
        } else if (str.find('+') != std::string::npos) {
            std::cout << "String is positive baby!" << std::endl;
            i = 1;
            positive = true;
        } else {
            i = 0;
            positive = true;
            std::cout << "nothing.."<< std::endl;
        }

        len = str.length();
        while (i < len) {
            tempStr = str.substr(i, 1);
            temp = std::atoi(tempStr.c_str());
            num.insert(num.begin(), temp);
            
            i++;
        }

        carry = 0;
        size = num.size();
        //std::cout << "Size = the str length" << std::endl;

        /*
        check for leading negative, remove
        or check for leading positive, remove
        while there are still numbers in the str
            take first number, add to front of vector
        set size
        
        // Add each value to the front of the 
        

        */
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
        std::string numString;
        std::vector<int> n = integ.getNum();
        if (!(integ.isPositive())) {
            numString += '-';
        } else {
            numString += '+';
        }
        for (unsigned int i = 0; i < integ.getSize(); ++i)
            numString += std::to_string(n[i]);

        ostr << numString;
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

