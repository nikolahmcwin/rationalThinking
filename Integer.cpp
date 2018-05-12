
#include "Integer.h"

/**
 * Integer.cpp for E9 COSC326
 * @author Finn Luxton and Nikolah Pearce
 */

namespace cosc326 {

    // Default constructor 
    Integer::Integer() {
        num.push_back(0);
        positive = true;
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

        // Find and ignore any trailing -'s or +'s
        if (str.find('-') != std::string::npos) {
            i = 1;
            positive = false;
        } else if (str.find('+') != std::string::npos) {
            i = 1;
            positive = true;
        } else {
            i = 0;
            positive = true;
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
    }

    // Destructor
    Integer::~Integer() {

    }


    // Accessor for size
    unsigned int Integer::getSize() const {
        return size;
    }

    // Accessor for the vector num
    const std::vector<int>& Integer::getNum() const {
        return num;
    }

    // Accessor for positive
    bool Integer::isPositive() const {
        return positive;
    }

    // Assignment operator =
    Integer& Integer::operator=(const Integer& integ) {
        if (this != &integ) {
            size = integ.size;
            num = integ.num;
            carry = integ.carry;
            positive = integ.positive;     
		}
		return *this;
    }

    // Unary Operator +
    Integer& Integer::operator+() {
        return *this;
    }
        
    // Unary Operator -
    Integer& Integer::operator-() {
        if (positive) {
            positive = false;
        } else if (!positive) {
            positive = true;
        }
        return *this;
    }

    // Binary arithmetic operator -
    Integer& Integer::operator-(const Integer& integ) {
        this -= integ;
        return *this;
    }

    // Binary arithmetic operator /
    Integer& Integer::operator/(const Integer& integ) {
        this /= integ;
        return *this;
    }

    // Binary arithmetic operator %
    Integer& Integer::operator%(const Integer& integ) {
        Integer remainder(this);
        remainder %= integ;
        return *remainder;
    }

    // Compound assignment operator +=
    Integer& Integer::operator+=(const Integer& integ) {
        if (positive) {
            if (integ.isPositive()) {
                // Both pos
                // a + b
                
            } else {
                // This pos but second number is neg 
                // +a + -b = a - b
                
            }
        } else {
            if (integ.isPositive()) {
                // This is neg but Integ is pos
                // -a + +b = -a + b =  b - a
                
            } else {
                // Both are neg 
                // -a + -b = -a - b
                
            }
        }

        return *this;
    }
    
    // Compound assignment operator -=
    Integer& Integer::operator-=(const Integer& integ) {
        if (positive) {
            if (integ.isPositive()) {
                // Both pos
                // +a - +b = a - b
                
            } else {
                // This pos but second number is neg 
                // +a - -b = a + b
                
            }
        } else {
            if (integ.isPositive()) {
                // This is neg but Integ is pos
                // -a - +b = -a - b =  -a - b
                
            } else {
                // Both are neg 
                // -a - -b = -a + b = b - a
                
            }
        }
        return *this;
    }
    
    // Compound assignment operator *=
    Integer& Integer::operator*=(const Integer& integ) {
        
        return *this;
    }

    // Compound assignment operator /=
    Integer& Integer::operator/=(const Integer& integ) {
        /*
        if he wants to divide 1614814601 / 1390
        a suprising number of library subtract and keep going. But super inefficient for big intS
        something about a range of 0-9 to search (efficiently)
        */
        return *this;
    }
    
    // Compound assignment operator %=
    Integer& Integer::operator%=(const Integer& integ)  {
        
        return *this;
    }

    // Comparison operator ==
    bool Integer::operator==(const Integer& integ) {
        bool check = true;
        if ((positive == integ.positive) && (size == integ.size)) {
            for (unsigned int i = 0; i < size; i++) {
                if (num[i] != integ.num[i]) {
                    check = false;
                    break;
                }
            }
        } else {
            check = false;
        }
        return check;
    }
       
    // Comparison operator !=
    bool Integer::operator!=(const Integer& integ) {
        return !(*this == integ);
    }

    // Comparison operator <
    bool Integer::operator<(const Integer& integ) {
        // aka this < integ
        bool check;
        int thisSize = num.size();
        int integSize = integ.getNum().size();

        if (*this == integ) {
            return false;
        }
        if (positive) {
            if (integ.isPositive()) {
                // Both pos
                if (thisSize < integSize) {
                    return true;
                } else if (thisSize > integSize) {
                    return false;
                }
            } else {
                // integ is neg. 
                return false;
            }
        } else {
            if (integ.isPositive()) {
                // Integ is pos
                return true;
            } else {
                // Both neg 
                if (thisSize > integSize) {
                    return true;
                } else if (thisSize < integSize) {
                    return false;
                }
            }
        }

        // Otherwise numbers are the same size/length. loops through!
        std::vector<int> gt = integ.getNum();
        if (positive) {
             for (int i = num.size() - 1; i >= 0; i--) {
                // work with largest digit first for efficiency
                if (num[i] < gt[i]) {
                    return true;
                } else if (num[i] > gt[i]) {
                    return false;
                }
            }
        } else {
             for (int i = num.size() - 1; i >= 0; i--) {
                // work with largest digit first for efficiency
                if (num[i] > gt[i]) {
                    return true;
                } else if (num[i] < gt[i]) {
                    return false;
                }
            }
        }
       
        return false;
    }

    // Comparison operator <=
    bool Integer::operator<=(const Integer& integ) {
        if ((*this == integ) || (*this < integ)) {
            return true;
        } else {
            return false;
        }
    }

    // Comparison operator >
    bool Integer::operator>(const Integer& integ) {
        if ((*this == integ)) {
            return false;
        } else {
            return !(*this < integ);
        } 
    }

    // Comparison operator >=
    bool Integer::operator>=(const Integer& integ) {
        bool smaller = (*this < integ);
         if ((*this == integ) || (!(*this < integ))) {
            return true;
        } else {
            return false;
        }
    }

    // Returns greatest common divisor of a and b
    /*
    unsigned int gdc (unsigned int a, unsigned int b){
        unsigned int tmp;
        while(b != 0) {
            tmp = a;
            a = b;
            b = tmp % b;
        }
        return a;
    }*/

    /**
     *  These operators below are NOT part of the class itself.
     */

    // Binary arithmetic operator +
    Integer operator+(const Integer& i1, const Integer& i2) {
        Integer sum(i1);
        sum += i2;
		return sum;
    }

    // Binary arithmetic operator *   
    Integer operator*(const Integer& i1, const Integer& i2) {
        Integer sum(i1);
        sum *= i2;
		return sum;
    }


    // Streaming insertion operator <<
	std::ostream& operator<<(std::ostream& ostr, const Integer& integ) {
        std::string numString;
        std::vector<int> n = integ.getNum();
        if (!(integ.isPositive())) {
            numString += '-';
        } else {
            numString += '+';
        }
        for (int i = (integ.getSize() - 1); i >= 0; i--)
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
}

