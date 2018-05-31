#include "Integer.h"

/**
 * Integer.cpp for E9 COSC326
 * @author Finn Luxton and Nikolah Pearce
 *
 * Paul's comments prefixed by PSC
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
        str.erase(0, std::min(str.find_first_not_of('0'), str.size()-1));

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
    /* PSC -- careful with this, you're leaking your abstraction here */
    unsigned int Integer::getSize() const {
        return size;
    }

    // Accessor for the vector num
    /* PSC -- careful with this, you're leaking your abstraction here */
    const std::vector<int>& Integer::getNum() const {
        return num;
    }

    // Accessor for positive
    /* PSC -- I should just be able to do this: 
     * Integer i = Integer("1"); 
     * i > Integer("0") ? "yes" : "no"
     */
    bool Integer::isPositive() const {
        return positive;
    }

    // Mutator for everything
	/* PSC -- why not just use one of the constructors and assign the result to the original value:
	 *
	 * Integer i = Integer("42");
	 * i = Integer("43");
     * 
     * 
     * DONEEEEEE
	 */
    void Integer::setAllFields(unsigned int s, std::vector<int>& vec, bool pos) {
        size = s;
        num = vec;
        positive = pos;
    }

     // Mutator for size
	/* PSC -- is this needed? Isn't the size a property of the vector you're using to store the digits? 


    DONEEEEEE
    
    */
    void Integer::setSize(unsigned int s) {
        size = s;

        //DONE
    }

     // Mutator for num
	/* PSC -- again, not sure why you don't just use one of the constructors 
    
    
    DONEEEEEE
    
    
    */
    void Integer::setNum(const std::vector<int>& vec) {
        num = vec;
        size = vec.size();
    }

     // Mutator for positive
     //
     /* PSC -- this is duplicating the functionality of the unary + 
     
     
     DONEEEEEE
     
     
     */
    void Integer::setPositive(bool pos) {
        positive = pos;
    }

    // Method to check if an Integer is 0 e.g. num = [0];
    /* PSC -- just use something like this:
     *
     *  Integer i = Integer("42");
     *  Integer zero = Integer("0");
     *
     *  if(i == zero){
     *     std::cout << "this is the end of the world!!!" << std::endl;
     * 
     * DONEEEEEE
     * 
     * DONE can't do that what if zero is pos or neg??/
     * 
     *  }
     */
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

    // Method to handle carry in subtraction
    std::vector<int> Integer::handleCarry(int index, const std::vector<int>& v) {
        std::vector<int> vec = v;
        int i = index;

        if (i+1 < vec.size()) {
            vec[i+1] = (vec[i+1] - 1);
            vec[i] = vec[i] + 10;
        } else {
        }
        
        return vec;
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
	/* PSC -- why does it matter if it *is* zero? */
        if (isZero(integ)) {
            return *this;
        } else if (isZero(*this)) {
           std::vector<int> vec = integ.getNum();
           setAllFields(integ.getSize(), vec, integ.isPositive());
           return *this;
        }

	/* PSC -- one thing about the stuff below is that it looks overly
	 * complex.
	 *
	 * Why not just modify *this? We're allowed to because we're in the +=
	 * operator, it does the addition *and* the assignment.
	 *
	 * I can see why though -- it makes it look similar to Java.
	 *
	 * It also seems like you've got more cases than you need. If I take
	 * two Integers a and b then you need to handle the following cases:
	 *
	 *  a  +  b 
	 *  a  + -b
	 * -a  +  b
	 * -a  + -b
	 *
	 * BUT:
	 *
	 * a + -b = a - b
	 * -a + b = b - a
	 * -a + -b = -1 * (a + b)
	 *
	 * So, there is only one case you realy need to implement, the others
	 * just call a different function. 
	 * 
	 * The same sort of logic will apply to the other operators too.
	 *
	 * The other thing that might be useful to think about is to make the
	 * addition a two phase operation. In your first phase you perform the
	 * addition (e.g. 9 + 9 = 18), then in the next phase you handle the
	 * carry (e.g. value[i] = 18 % 10, value[i+1] += 18/10) and ripple that
	 * up through the array of values.
     * 
     * 
     * 
     * 
     * 
     * 
     * DONEEEEEE
     * 
     * 
     * 
     * DONEEEEEE
     * 
     * DONEEEEEE
	 */


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
                // Both pos
                // +a - +b = a - b
                int i = 0;
                while (i < smaller.size()) {
                    int sum;
                    sum = larger[i] - smaller[i];
                    if (sum < 0) {
                        larger = handleCarry(i, larger);

                        //std::cout << "larger i is: " << larger[i] << std::endl;
                        sum = larger[i] - smaller[i];
                        //std::cout << "sum is: " << sum << std::endl;

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
                // -a - -b = -a + +b = +b - +a
                Integer a(*this);
                Integer b(integ);
                b.setPositive(true);
                a += b;
                std::vector<int> vec = a.getNum();
                setAllFields(a.getSize(), vec, a.isPositive());
            }
        }
        return *this;
    }
    
    






    // Compound assignment operator *=
    Integer& Integer::operator*=(const Integer& integ) {
       /* // Inefficent solution is to add repeatadly

        // If integ == 0, return 0
        
        if (isZero(integ)) {
            return *this;
        } else if (isZero(*this)) {
           std::vector<int> vec = integ.getNum();
           setAllFields(integ.getSize(), vec, integ.isPositive());
           return *this;
        }

        // If integ == 1, return integ

        if (integ.getNum() == 1){
            return *this;
        }

        // http://people.sabanciuniv.edu/levi/cs201/bigint.cpp
        // Doesnt use Vector of ints, but has very simple *= operator
         Essentially says

        For each digit i, from left to right
            sum = num * integ[i] + carry
            carry = sum / 10;
            ChangeDigit(i, sum%10)      ---> if (0 <= i && i < num.size()){
                                                digits[i] = char('0' + (sum%10))
                                             else{
                                                 error message for changeDigit
                                             }
        
        After thats all done, add whats in the carry back into the sum

        while (carry != 0){
            AddSigDigit(carry % 10)     ---> if(num.size >= integ.size){
                                                increase size of integ
                                             }
                                             integ[num] = char('0' + carry);
                                             num++;          
            carry /= 10
        }
                    */
        return *this;
    }








    // Compound assignment operator /=
    Integer& Integer::operator/=(const Integer& integ) {

	/*
	 * PSC -- yes I agree with the note below and there are more efficient
	 * solutions. However, with the remaining time in the semester I'd go
	 * with the general approach of 'get it working' as opposed to 'make it
	 * fast'. If you make a note of this in the submission I'll be happy
	 * with it.
	 *
	 */


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
	    /* PSC -- if you're clever about it, you should be able to use the
	     * division, multiplication, and subtraction operators here and
	     * actually do very little work. ;-) */

	return *this;
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
    
    // The comparison operators 
    bool operator<(const Integer& lhs, const Integer& rhs) {
	/*
	 * PSC -- I have a feeling that this could be simplified.
	 *
	 * You may be able to use similar logic as in the suggeste addition approach above.
	 */


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
        //std::vector<int> lhsV = rhs.getNum();
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

	bool operator>(const Integer& lhs, const Integer& rhs) {
        if ((lhs == rhs)) {
            return false;
        } else {
            return !(lhs < rhs);
        } 
	}

	bool operator<=(const Integer& lhs, const Integer& rhs) {
		if ((lhs == rhs) || (lhs < rhs)) {
            return true;
        } else {
            return false;
        }
	}

	bool operator>=(const Integer& lhs, const Integer& rhs) {
		bool smaller = (lhs < rhs);
        if ((lhs == rhs) || (!(lhs < rhs))) {
            return true;
        } else {
            return false;
        }
	}

	bool operator==(const Integer& lhs, const Integer& rhs) {
		bool check = true;
		/* PSC -- why not negate the condition and if true, return */
	        if ((lhs.isPositive() == rhs.isPositive()) && (lhs.getSize() == rhs.getSize())) {
	            for (unsigned int i = 0; i < lhs.getSize(); i++) {
	                if (lhs.getNum()[i] != rhs.getNum()[i]) {
				/* PSC -- why not just return here? */
	                    check = false;
	                    break;
	                }
	            }
	        } else {
	            check = false;
	        }
        return check;
	}

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

