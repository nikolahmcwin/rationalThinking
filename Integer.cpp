
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

    // Mutator for everything
    void Integer::setAllFields(unsigned int s, std::vector<int>& vec, bool pos) {
        size = s;
        num = vec;
        positive = pos;
    }

     // Mutator for size
    void Integer::setSize(unsigned int s) {
        size = s;
    }

     // Mutator for num
    void Integer::setNum(const std::vector<int>& vec) {
        num = vec;
    }

     // Mutator for positive
    void Integer::setPositive(bool pos) {
        positive = pos;
    }

    // Method to check if an Integer is 0 e.g. num = [0];
    bool Integer::isZero(const Integer& integ) {
        std::vector<int> vec = integ.getNum();
        if (vec.size() > 1) {
            return false;
        } else {
            if (vec[0] ==  0) {
                return true;
            } else {
                return false;
            }
        }
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

    // Compound assignment operator +=
    Integer& Integer::operator+=(const Integer& integ) {

        // Test if we are adding 0!
        if (isZero(integ)) {
            return *this;
        } else if (isZero(*this)) {
           std::vector<int> vec = integ.getNum();
           setAllFields(integ.getSize(), vec, integ.isPositive());
           return *this;
        }

        int carry = 0;
        int size1 = size;
        int size2 = integ.getSize();
        int smallerSize;

        std::vector<int> smaller;
        std::vector<int> larger;
        std::vector<int> answer;

         if (size1 > size2) {
            smaller = integ.getNum();
            larger = num;
        } else {
            smaller = num;
            larger = integ.getNum();
        }

        if (positive) {
            if (integ.isPositive()) {
                // Both pos
                // a + b
                int i = 0;
                while (i < larger.size()) {
                    int sum;
                    if (i < smaller.size()) {
                        sum = smaller[i] + larger[i] + carry;
                    } else {
                        sum = larger[i] + carry;
                    }
                    if (sum > 9) {
                        sum = sum % 10;
                        carry = 1;
                    } else {
                        carry = 0;
                    }
                    answer.push_back(sum);
                    i++;
                } 
                if ((i == larger.size()) && (carry == 1)) {
                    answer.push_back(carry);
                }
                setAllFields(answer.size(), answer, true);
            } else {
                // This pos but second number is neg 
                // +a + -b = a - b
                Integer b(integ);
                b.setPositive(true);
                *this -= b;
            }
        } else {
            if (integ.isPositive()) {
                // This is neg but Integ is pos
                // -a + +b = -a + b =  b - a
                Integer a(*this);
                a.setPositive(true);
                Integer b(integ);
                b -= a;
                std::vector<int> vec = b.getNum();
                setAllFields(b.getSize(), vec, b.isPositive());
            } else {
                // Both are neg 
                // - 10 - 10 = -20 or -(a + b) ---> NEGATIVE
                // -a + -b = -a - b
                Integer a(*this);
                a.setPositive(true);
                Integer b(integ);
                b.setPositive(true);
                a += b;
                a.setPositive(false);
                std::vector<int> vec = a.getNum();
                setAllFields(a.getSize(), vec, a.isPositive());
            }
        }
        return *this;
    }
    
    // Compound assignment operator -=
    Integer& Integer::operator-=(const Integer& integ) {

        // Test if either numbers is 0!
        if (isZero(integ)) {
            return *this;
        } else if (isZero(*this)) {
           std::vector<int> vec = integ.getNum();
           setAllFields(integ.getSize(), vec, !(integ.isPositive()));
           return *this;
        }

        int carry = 0;
        std::vector<int> smaller;
        std::vector<int> larger;
        std::vector<int> answer;
        bool answerIsPositive;

         if (num.size() >= integ.getSize()) {
            smaller = integ.getNum();
            larger = num;
        } else {
            smaller = num;
            larger = integ.getNum();
        }

        // If a > b, a - b is positive
        if (*this >= integ) {
            answerIsPositive = true;
        } else {
            // If a < b, a - b is negative
            answerIsPositive = false;
        }

        int i = 0;
        if (positive) {
            if (integ.isPositive()) {
                // Both pos
                // +a - +b = a - b
                int i = 0;
                while (i < smaller.size()) {
                    int sum;
                    sum = larger[i] - smaller[i];
                    if (sum < 0) {
                        // Take the carry out of the next digit
                        carry = 1;
                        if ((i+1) < larger.size()) {
                            larger[i+1] = larger[i+1] - carry;
                        }
                        sum = 0;
                        int tmp = 10 + larger[i];
                        sum = tmp - smaller[i];
                    } else {
                        carry = 0;
                    }                    
                    answer.push_back(sum);
                    i++;
                } 
                // Keep going with the other vector
                while (i < larger.size()) {
                    answer.push_back(larger[i]);
                    i++;
                }
                // Remove any extra 0's that were appened e.g. 1000 - 999 = 0001
                for (int i = answer.size()-1; i >= 0; i--) {
                    if (answer[i] != 0) {
                        break;
                    } else {
                        answer.erase(answer.begin() + i);
                    }
                } 
                setAllFields(answer.size(), answer, answerIsPositive);   
            } else {
                // This pos but second number is neg 
                // +a - -b = a + b
                Integer b(integ);
                b.setPositive(true);
                *this += b;
            }
        } else {
            if (integ.isPositive()) {
                // This is neg but Integ is pos
                // -a - +b = -a - b =  -a - b // -a - b = -(a+b)
                Integer a(*this);
                a.setPositive(true);
                a += integ;
                std::vector<int> vec = a.getNum();
                setAllFields(a.getSize(), vec, false);
            } else {
                // Both are neg 
                // -a - -b = -a + b = b - +a
                Integer a(*this);
                a.setPositive(true);
                Integer b(integ);
                b.setPositive(true);
                b -= a;
                std::vector<int> vec = b.getNum();
                setAllFields(b.getSize(), vec, b.isPositive());
                /*




                NOT YET WORKIGN  fml





                */

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
    Integer gcd(const Integer& i1, const Integer& i2) {
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

    /**
     *  These operators below are NOT part of the class itself.
     */

    // Binary arithmetic operator +
    Integer operator+(const Integer& i1, const Integer& i2) {
        Integer sum(i1);
        sum += i2;
		return sum;
    }

     Integer operator-(const Integer& i1, const Integer& i2) {
        Integer sum(i1);
        sum -= i2;
		return sum;
    }

    // Binary arithmetic operator *   
    Integer operator*(const Integer& i1, const Integer& i2) {
        Integer sum(i1);
        sum *= i2;
		return sum;
    }

    Integer operator/(const Integer& i1, const Integer& i2) {
        Integer sum(i1);
        sum /= i2;
		return sum;
    }

    Integer operator%(const Integer& i1, const Integer& i2) {
        Integer sum(i1);
        sum %= i2;
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

