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
    Integer::Integer(const std::string& str1) {
        std::string tempStr;
        int temp, i, len;

        std::string str = str1;
        if (str1.compare("-0") == 0) {
            str.erase(0, 1);
        }
        //std::string str = str2;
        if (str1.length() != 1) {
            str.erase(0, std::min(str.find_first_not_of('0'), str.size()-1));
        }

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

    // Helper constructor takes in vector of ints
    Integer::Integer(const std::vector<int>& vec) {
        num = vec;
        size = vec.size();
        positive = true;
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

    // Mutator for Rationals to access the sign of each Integer.
    void Integer::setPositive(bool pos) {
        positive = pos;
    }

    // Assignment operator =
    Integer& Integer::operator=(const Integer& integ) {
        
        if (*this != integ) {
            size = integ.size;
            num = integ.num;
            positive = integ.positive;     
		}
		return *this;
    }

    // Unary Operator +
    Integer Integer::operator+() const{
        return Integer(*this);
    }
        
    // Unary Operator -
    Integer Integer::operator-() const {
        Integer n = (*this);
        if (positive) {
            n.positive = false;
        } else if (!positive) {
            n.positive = true;
        }
        return n;
    }

    // Compound assignment operator +=
    Integer& Integer::operator+=(const Integer& integ) {

        // Test if we are adding 0!
        if (isZero(integ)) {
            return *this;
        } else if (isZero(*this)) {
           *this = Integer(integ);
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
                *this = Integer(answer);
            } else {
                // +a + -b = a - b
                Integer b(integ);
                b.positive = true;
                *this -= b;
            }
        } else {
            if (integ.isPositive()) {
                // -a + +b = -a + b =  b - a
                Integer tmp(*this);
                *this = integ;
                tmp.positive = true;
                *this -= tmp;
            } else {
                // -a + -b = -a - b
                Integer tmp(integ);
                tmp.positive = true;
                *this -= tmp;
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
           *this = integ;
           return *this;
        } else if (*this == integ) {
            // Or the number is itself, return 0
            Integer zero;
            *this = zero;
            return *this;
        }

        int carry = 0;
        std::vector<int> smaller;
        std::vector<int> larger;
        std::vector<int> answer;
        bool answerIsPositive;

        if (num.size() > integ.getSize()) {
            smaller = integ.getNum();
            larger = num;
        } else if (num.size() < integ.getSize()){
            smaller = num;
            larger = integ.getNum();
        } else {
            if (*this >= integ) {
                smaller = integ.getNum();
                larger = num;
            } else {
                smaller = num;
                larger = integ.getNum();
            }
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
                // +a - +b = a - b
                int i = 0;
                while (i < smaller.size()) {
                    int sum;
                    sum = larger[i] - smaller[i];
                    if (sum < 0) {
                        larger = handleCarry(i, larger);
                        sum = larger[i] - smaller[i];
                    }        
                    answer.push_back(sum);
                    i++;
                } 
                // Keep going with the other vector
                while (i < larger.size()) {
                    if (larger[i] == -1) {
                        int ans;
                        larger = handleCarry(i, larger);
                        answer.push_back(larger[i]);
                    } else {
                        answer.push_back(larger[i]);
                    }
                    i++;
                }
                // Remove any extra 0's that were appened e.g. 1000 - 999 = 0001
                for (int i = answer.size()-1; i >= 0; i--) {
                    if ((answer[i] != 0) || (i == 0)){
                        break;
                    } else {
                        answer.erase(answer.begin() + i);
                    }
                } 
                *this = Integer(answer);
                positive = answerIsPositive;

            } else {
                // +a - -b = a + b
                Integer tmp(integ);
                tmp.positive = true;
                *this += tmp;
            }
        } else {
            if (integ.isPositive()) {
                // -a - +b = -a - b =  -a - b // -a - b = -(a+b)
                Integer tmp(integ);
                tmp.positive = true;
                positive = true;
                *this += tmp;
                positive = false;
            } else {
                // -a - -b = -a + +b = +b - +a
                Integer tmp(*this);
                *this = integ;
                tmp.positive = true;
                positive = true;
                *this -= tmp;
            }
        }
        return *this;
    }

    // Compound assignment operator *=
    Integer& Integer::operator*=(const Integer& integ) {
       
        std::vector<int> smaller;
        std::vector<int> larger;
        std::vector<int> tmp;
        std::vector<Integer> answer;
        Integer sum;
        bool sumIsPositive;
        int carry = 0;
        int index;

        // Check the input signs, to calculate sum sign
        if ((isPositive()) && (integ.isPositive())) {
            sumIsPositive = true;
        } else if ((!isPositive()) && (!integ.isPositive())) {
            sumIsPositive = true;
        } else {
            sumIsPositive = false;
        }
        // If either number is 0, return 0
        Integer zero;
        if ((isZero(integ)) || (isZero(*this))) {
            Integer zero;
            *this = zero;
            return *this;
        }
        // If either number is 1, return the other number
        if (isOne(integ)) {
            return *this;
        } else if (isOne(*this)) {
            *this = integ;
            return *this;
        }

        if (num.size() > integ.getSize()) {
            smaller = integ.getNum();
            larger = num;
        } else { 
            smaller = num;
            larger = integ.getNum();
        } 
        // For each digit in number 2 (smaller), do long multiplication
        for (int i = 0; i < smaller.size(); i++) {
            tmp.clear();
            for (int k = 0; k < i; k++) {
                tmp.push_back(0);
            }
            // If the digit to multiply is zero, ignore
            if (smaller[i] == 0) {
                tmp.push_back(0);
            } else {
                for (int j = 0; j < larger.size(); j++) {
                    int prod = (smaller[i] * larger[j]) + carry;
                    if (prod > 9) {
                        int newProd = (prod % 10);
                        carry = ((prod - newProd) / 10);
                        prod = newProd; 
                    } else {
                        carry = 0;
                    }
                    tmp.push_back(prod);
                }
                // Handle the remaining carry, if any
                if ((carry != 0)) {
                    tmp.push_back(carry);
                }
                carry = 0;
            }
            // Add the answer found for this index to an Integer
            Integer tmpInteger(tmp);
            // Push that integer into our vector of all Integers
            answer.push_back(tmpInteger);
        }
        // Loop through every integer in answer, adding them together.
        for (int i = 0; i < answer.size(); i++) {
            sum += answer[i];
        }
        *this = sum;
        positive = sumIsPositive;
        return *this;
    }

    // Compound assignment operator /=
    Integer& Integer::operator/=(const Integer& integ) {
        bool sumIsPositive;

        // Check the input signs, to calculate sum sign
        if ((isPositive()) && (integ.isPositive())) {
            sumIsPositive = true;
        } else if ((!isPositive()) && (!integ.isPositive())) {
            sumIsPositive = true;
        } else {
            sumIsPositive = false;
        }

        // If either number is 0, deal with it
        Integer zero;
        if (isZero(integ)) {
            std::cout << "You may not divide by zero" << std::endl;
            *this = Integer("-4999999888954");
            return *this;
        } else if (isZero(*this)) {
            *this = zero;
            return *this;
        }
        // If either number is 1, return special answers
        if (isOne(integ)) {
            return *this;
        } else if (isOne(*this)) {
            *this = zero;
            return *this;
        }

        Integer numberDivides;
        Integer one("1");
        if (sumIsPositive) {
            if (positive) {
                while ((*this > zero)) {
                    *this -= integ;
                    if (*this < zero) {
                        break;
                    }
                    numberDivides += one;
                }
            } else {
                while ((*this < zero)) {
                    *this -= integ;
                    if (*this > zero) {
                        break;
                    }
                    numberDivides += one;
                }
            }
        } else {
            if (positive) {
                while ((*this > zero)) {
                    *this += integ;
                    if (*this < zero) {
                        break;
                    }
                    numberDivides += one;
                }
            } else {
                while ((*this < zero)) {
                    *this += integ;
                    if (*this > zero) {
                        break;
                    }
                    numberDivides += one;
                }
            }
            
        }        
        *this = numberDivides;
        if (numberDivides == zero) {
            positive = true;
        } else {
            positive = sumIsPositive;
        }
        return *this;
    }
    
    // Compound assignment operator %=
    Integer& Integer::operator%=(const Integer& integ)  {
        Integer tmp(*this / integ);
        Integer max(tmp * integ);
        *this -= max;
        return *this;
    }

    /**
     *  METHODS BELOW HERE ARE NOT PART OF THE CLASS
     */


    // Method to check if an Integer is 0 e.g. num = [0];
    // Ignore sign, just check if the vector is 0
    bool isZero(const Integer& integ) {
        
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
    // Method to check if an Integer is 1 e.g. num = [1];
    // Ignore sign, just check if the vector is 1
    bool isOne(const Integer& integ) {
        std::vector<int> vec = integ.getNum();
        if (vec.size() > 1) {
            return false;
        } else {
            if (vec[0] ==  1) {
                return true;
            } else {
                return false;
            }
        }
    }

    // Method to handle carry in subtraction
    std::vector<int> handleCarry(int index, const std::vector<int>& v) {
        std::vector<int> vec = v;
        int i = index;
        if (i+1 < vec.size()) {
            vec[i+1] = (vec[i+1] - 1);
            vec[i] = vec[i] + 10;
        }
        return vec;
    }

    // Binary arithmetic operator +
    Integer operator+(const Integer& i1, const Integer& i2) {
        Integer sum(i1);
        sum += i2;
		return sum;
    }

    // Binary arithmetic operator -
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

    // Binary arithmetic operator /
    Integer operator/(const Integer& i1, const Integer& i2) {
        Integer sum(i1);
        sum /= i2;
		return sum;
    }

    // Binary arithmetic operator %
    Integer operator%(const Integer& i1, const Integer& i2) {
        Integer sum(i1);
        sum %= i2;
		return sum;
    }
    
    // The comparison operator <
    bool operator<(const Integer& lhs, const Integer& rhs) {
        bool check;
        int lhsSize = lhs.getSize();
        int rhsSize = rhs.getSize();

        if (lhs == rhs) {
            return false;
        }

        if (lhs.isPositive()) {
            if (rhs.isPositive()) {
                // Both pos
                if (lhsSize < rhsSize) {
                    return true;
                } else if (lhsSize > rhsSize) {
                    return false;
                }
            } else {
                // rhs is neg. 
                return false;
            }
        } else {
            if (rhs.isPositive()) {
                // rhs is pos
                return true;
            } else {
                // Both neg 
                if (lhsSize > rhsSize) {
                    return true;
                } else if (lhsSize < rhsSize) {
                    return false;
                }
            }
        }
        // Otherwise numbers are the same size/length. loops through!
        if (lhs.isPositive()) {
             for (int i = lhs.getSize() - 1; i >= 0; i--) {
                // work with largest digit first for efficiency
                if (lhs.getNum()[i] < rhs.getNum()[i]) {
                    return true;
                } else if (lhs.getNum()[i] > rhs.getNum()[i]) {
                    return false;
                }
            }
        } else {
             for (int i = lhs.getSize() - 1; i >= 0; i--) {
                // work with largest digit first for efficiency
                if (lhs.getNum()[i] > rhs.getNum()[i]) {
                    return true;
                } else if (lhs.getNum()[i] < rhs.getNum()[i]) {
                    return false;
                }
            }
        }
        return false;
	}

    // The comparison operator >
	bool operator>(const Integer& lhs, const Integer& rhs) {
        if ((lhs == rhs)) {
            return false;
        } else {
            return !(lhs < rhs);
        } 
	}

    // The comparison operator <=
	bool operator<=(const Integer& lhs, const Integer& rhs) {
		if ((lhs == rhs) || (lhs < rhs)) {
            return true;
        } else {
            return false;
        }
	}

    // The comparison operator >=
	bool operator>=(const Integer& lhs, const Integer& rhs) {
		bool smaller = (lhs < rhs);
        if ((lhs == rhs) || (!(lhs < rhs))) {
            return true;
        } else {
            return false;
        }
	}

    // The comparison operator ==
	bool operator==(const Integer& lhs, const Integer& rhs) {
		bool check = true;
        if ((lhs.isPositive() == rhs.isPositive()) && (lhs.getSize() == rhs.getSize())) {
            for (unsigned int i = 0; i < lhs.getSize(); i++) {
                if (lhs.getNum()[i] != rhs.getNum()[i]) {
                    return false;
                }
            }
        } else {
            return false;
        }
        return true;
	}

    // The comparison operator !=
	bool operator!=(const Integer& lhs, const Integer& rhs) {
		return !(lhs == rhs);
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

    // Returns greatest common divisor of a and b
    Integer gcd(const Integer& i1, const Integer& i2) {
        Integer a(i1);
        Integer b(i2);
        Integer zero;
        Integer tmp;
        while (b != zero) {
            tmp = b;
            b = (a % b);
            a = tmp;
        }
        return a;
    }
}

