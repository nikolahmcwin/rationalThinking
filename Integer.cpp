
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
        size = num.size();
    }

    // Copy constructor that duplicates the provided Integer
    Integer::Integer(const Integer& integ) {
        num = integ.num;
        size = num.size();
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
        *this -= integ;
        return *this;
    }

    // Binary arithmetic operator /
    Integer& Integer::operator/(const Integer& integ) {
        *this /= integ;
        return *this;
    }

    // Binary arithmetic operator %
    Integer& Integer::operator%(const Integer& integ) {
        *this %= integ;
        return *this;
    }

    // Compound assignment operator +=
    Integer& Integer::operator+=(const Integer& integ) {
        std::cout << "THIS IS A TEST IN += operator function" << std::endl;
        int carry = 0;
        int size1 = size;
        int size2 = integ.getSize();
        int smallerSize;

        std::vector<int> num1 = num;
        std::vector<int> num2 = integ.getNum();
        std::vector<int> answer;

        // Add in trailing 0's for either of the numbers it they are different sizes
        if(size1 > size2) {
            smallerSize = size2;
            int i = smallerSize;
            while (i < size1) {
                num2.push_back(0);
                i++;
            }

        } else if (size1 < size2) {
            smallerSize = size1;
            int i = smallerSize;
            while (i < size2) {
                num1.push_back(0);
                i++;
            }
        }

        // Test print 
        std::string numString1 = "Num1: ";
        for (int i = 0; i < num1.size(); i++) {
            numString1 += std::to_string(num1[i]);
        }
        std::cout << numString1 << std::endl;

        std::string numString2 = "Num2: ";
        for (int i = 0; i < num2.size(); i++) {
            numString2 += std::to_string(num2[i]);
        }
        std::cout << numString2 << std::endl;
        
        if (positive) {
            if (integ.isPositive()) {
                // Both pos
                // a + b
                int i = 0;
                while (i < num1.size()) {
                    int sum = num1[i] + num2[i] + carry;
                    if (sum > 9) {
                        sum = sum % 10;
                        // Now set the new carry for next time
                        carry = 1;
                    } else {
                        carry = 0;
                    }
                    answer.push_back(sum);
                    i++;
                    if ((i == num1.size()) && (carry == 1)) {
                        answer.push_back(carry);
                    }
                }
                num = answer;
                return *this;
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
        a suprising number of library subtract and keep going.
             But super inefficient for big intS
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
    Integer Integer::gcd(const Integer& i1, const Integer& i2) {
        Integer a(i1);
        Integer b(i2);
        Integer zero;
        Integer tmp;
        while (b != zero) {
            tmp = b;
            // Will not yet work as the % doesn't work...
            b = a % b;
            a = tmp;
        }
        return a;
    }
    /*int gcd(unsigned int a, unsigned int b){
        unsigned int tmp;
        while(b != 0) {
            tmp = a;
            a = b;
            b = tmp % b;
        }
        return a;


        function gcd(a, b)
            while b ≠ 0
            t := b; 
            b := a mod b; 
            a := t; 
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
            //numString += '+';
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

