
#include "Rational.h"
#include "Integer.h"

/**
 * Rational.cpp for E9 COSC326
 * @author Finn Luxton and Nikolah Pearce
 */
 
namespace cosc326 {

    // Creates rational with value of 0
    Rational::Rational() {
        Integer zero;
        num = zero;
        den = zero;
        whole = zero;
        pos = true;
    }

    // Creates rational that duplicates the provided rational
    Rational::Rational(const Rational& r) {
        num = r.getNum();
        den = r.getDen();
        whole = r.getWhole();
        pos = r.isPos();
    }
    
    // Takes in a single Integer to create a Rational (a/1)
    Rational::Rational(const Integer& a) {
        Integer one("1");
        Integer zero;
        num = Integer(a);
        den = one;
        whole = zero;
        pos = a.isPositive();
        num.setPositive(true);        
    }
    
    // Takes in two Integers to create a Rational (a/b)
    Rational::Rational(const Integer& a, const Integer& b) {
        Integer zero;
        if (isZero(b)) {
            whole = Integer(a);
            num = zero;
            den = Integer("1");
            pos = a.isPositive();
            whole.setPositive(true);
        } else {
            num = Integer(a);
            den = Integer(b);
            whole = zero;
            if ((a.isPositive()) && (b.isPositive())) {
                pos = true;
            } else if ((!a.isPositive()) && (!b.isPositive())) {
                pos = true;
            } else {
                pos = false;
            }
            num.setPositive(true);
            den.setPositive(true);
        }
        
        
        
    }

    // Takes in three Integers to create a Rational (a + b/c)
    Rational::Rational(const Integer& a, const Integer& b, const Integer& c) {
        /*whole = a;
        num = b;
        den = c;
        if (a.isPositive()) {
            pos = true;
        } else {
            pos = false;
        }
        whole.setPositive(true);
        num.setPositive(true);
        den.setPositive(true);*/

        Rational w = (a);
        Rational ab(b, c);
        *this = ab;
        *this += w;
    }

    // Constructs with a string parameter
    Rational::Rational(const std::string& str1) { 
        std::string str = str1;

        // Find and ignore any trailing -'s or +'s
        if (str.find('-') != std::string::npos) {
            pos = false;
        } else {
            pos = true;
        }

        size_t posSlash = str.find('/');
        size_t posDot = str.find('.');
        Integer zero;
        Integer one("1");

        if (posDot == std::string::npos) {
            // If there is no decimal place
            whole = zero;
            if (posSlash == std::string::npos) {
                // If there is no fraction
                Integer n(str.substr(0));
                num = n;
                den = one;                                
            } else {
                // If there is a fraction
                Integer n(str.substr(0, (posSlash)));
                num = n;
                Integer d(str.substr((posSlash+1)));
                den = d;
            }
        } else {
            // If there is a decimal place
            Integer w(str.substr(0, (posDot)));
            whole = w;
            if (posSlash == std::string::npos) {
                // If there is no fraction
                Integer n(str.substr((posDot+1)));
                num = n;
                den = one;
            } else {
                // If there is a fraction
                Integer n(str.substr((posDot+1), (posSlash-posDot-1)));
                num = n;
                Integer d(str.substr((posSlash+1)));
                den = d;
            }
        }
        whole.setPositive(true);
        num.setPositive(true);
        den.setPositive(true);
    }
    
    // Deconstructor
    Rational::~Rational() {

    }

    // Accessors for num
    const Integer& Rational::getNum() const {
        return num;
    }

    // Accessors for den
    const Integer& Rational::getDen() const {
        return den;
    }

    // Accessors for whole
    const Integer& Rational::getWhole() const {
        return whole;
    }

    // Accessors for pos
    bool Rational::isPos() const {
        return pos;
    }

    // Mutator for setting num
    void Rational::setNum(const Integer& in) {
        num = in;
    }

    // Mutator for setting den
    void Rational::setDen(const Integer& in) {
        den = in;
    }

    // Mutator for setting whole
    void Rational::setWhole(const Integer& in) {
        whole = in;
    }

    // Mutator for setting pos
    void Rational::setPos(bool p) {
        pos = p;
    }

    // The assignment operator =
	Rational& Rational::operator=(const Rational& r) {
        num = r.getNum();
        den = r.getDen();
        whole = r.getWhole();
        pos = r.isPos();
        //std::cout << "*this inside = operator **** : " << *this << std::endl;
        return *this;
	}

    // Unary Operator -
	Rational Rational::operator-() const {
        Rational n = (*this);
        if (pos) {
            n.setPos(false);
        } else {
            n.setPos(true);
        }
        return n;
	}

    // Unary Operator +
	Rational Rational::operator+() const {
		return Rational(*this);
	}

    // Compound assignment operator +=
	Rational& Rational::operator+=(const Rational& r1) {
        Rational r = unsimplify(r1);
        Integer zero;
        Integer newNum;
        if (whole != zero) {
            newNum = ((whole * den) + num);
            num = newNum;
            whole = zero;
        }  
        //std::cout << "*r1 simplifying inside +=: " << r << std::endl;
        //std::cout << "*THIS simplifying inside -=: " << *this << std::endl;

        //std::cout << "UNSimplified this is: " << *this <<std::endl;
        //std::cout << "UNSimplified    r is:" << r <<std::endl;
       
        if (pos) {
            if (r.isPos()) {
                // a + b
                Integer newNum;
                newNum = (r.getNum() * den);
                den *= r.getDen();
                num *= r.getDen();
                num += newNum;
            } else {
                // a + -b = a -b
                r.setPos(true);
                *this -= r;
            }
        } else { 
            if (r.isPos()) {
                // -a + b = b - a
                Rational tmp((*this));
                *this = r;
                tmp.setPos(true);
                *this -= tmp;
            } else {
                // -a + -b = -a - b = -(a+b);
                pos = true;
                Rational tmp(r);
                tmp.setPos(true);
                *this += tmp;
                pos = false;     
            }
        }
        //*this = simplify(*this);
		return *this;
	}

    // Compound assignment operator -=
	Rational& Rational::operator-=(const Rational& r1) {
        Rational r = unsimplify(r1);
        Integer zero;
        Integer newNum;
        if (whole != zero) {
            newNum = ((whole * den) + num);
            num = newNum;
            whole = zero;
        }  
        bool answerIsPositive;
        // If a > b, a - b is positive
        if (*this >= r1) {
            answerIsPositive = true;
        } else {
            // If a < b, a - b is negative
            answerIsPositive = false;
        }

        if (pos) {
            if (r.isPos()) {
                // a - b
                Integer newNum;
                newNum = (r.getNum() * den);
                den *= r.getDen();
                num *= r.getDen();
                num -= newNum;
                if (num.isPositive() == false) {
                    num.setPositive(true);
                    answerIsPositive = false;
                }
            } else {
                // a - -b = a + b
                r.setPos(true);
                *this += r;
            }
        } else { 
            if (r.isPos()) {
                // -a - b = -(a + b)
                pos = true;
                *this += r;
            } else {
                // -a - -b = -a + b = b - a;
                Rational tmp((*this));
                *this = r;
                tmp.setPos(true);
                pos = true;
                *this -= tmp;
            }
        }
        pos = answerIsPositive;
        //*this = simplify(*this);
		return *this;
	}

    // Compound assignment operator *=
	Rational& Rational::operator*=(const Rational& r1) {
        Rational r = unsimplify(r1);
        Integer zero;
        Integer newNum;
        if (whole != zero) {
            newNum = ((whole * den) + num);
            num = newNum;
            whole = zero;
        }

        den *= r.getDen();
        num *= r.getNum();
        //std::cout << "Den " << den << " Num " << num << std::endl;

        if (pos == r1.isPos()) {
            pos = true;
        } else {
            pos = false;
        }

        if (isZero(num) && isZero(whole)) {
            pos = true;
        }
        num.setPositive(true);
        den.setPositive(true);
        whole.setPositive(true);
        //*this = simplify(*this);
        //std::cout << "Resulting THIS " << *this << std::endl;
		return *this;
	}

    // Compound assignment operator /=
	Rational& Rational::operator/=(const Rational& r1) {
		Rational r = unsimplify(r1);
        Integer zero;
        Integer newNum;
        if (whole != zero) {
            newNum = ((whole * den) + num);
            num = newNum;
            whole = zero;
        }
        Rational swapped(r);
        swapped.setNum(r.getDen());
        swapped.setDen(r.getNum());
        *this *= swapped;
        //*this = simplify(*this);
        return *this;
	}

    /**
     *  METHODS BELOW HERE ARE NOT PART OF THE CLASS
     */


    // Helper method to simplify
    Rational simplify(const Rational& r) {
        Rational r2 = r;
        Integer n = r2.getNum();
        Integer d = r2.getDen();
        Integer w = r2.getWhole();
        /// If a/b > 1, set the whole part
        if (n >= d) {
            w = (n/d);
            n = (n - (w*d));
        }
        // Simplify remaining fraction part 
        Integer g = gcd(n, d);
        n = (n / g);
        d = (d / g);
        r2.setNum(n);
        r2.setDen(d);
        r2.setWhole(w);
        return r2;
    } 

    
    // Helper method to UNsimplify
    Rational unsimplify(const Rational& r) {
        Rational r2 = Rational(r);
        //std::cout << "AS STANDS: " << r <<std::endl;
        Integer zero;
        Integer newNum;

        if (r.getWhole() != zero) {
            newNum = ((r2.getWhole() * r2.getDen()) + r2.getNum());
            r2.setNum(newNum);
            r2.setWhole(zero);
        } 

        //std::cout << "after undoing: " << r2 <<std::endl;
        return r2;
    }

    // The binary arithmetic operator +
   	Rational operator+(const Rational& lhs, const Rational& rhs) {
        Rational sum(lhs);
        sum += rhs;
		return sum;
	}

    // The binary arithmetic operator -
	Rational operator-(const Rational& lhs, const Rational& rhs) {
		Rational sum(lhs);
        sum -= rhs;
		return sum;
	}

    // The binary arithmetic operator *
	Rational operator*(const Rational& lhs, const Rational& rhs) {
		Rational sum(lhs);
        sum *= rhs;
		return sum;
	}

    // The binary arithmetic operator /
	Rational operator/(const Rational& lhs, const Rational& rhs) {
		Rational sum(lhs);
        sum /= rhs;
		return sum;
	}

    // The print stream operator <<
	std::ostream& operator<<(std::ostream& ostr, const Rational& r1) {
		std::string numString;
        Rational r = simplify(r1);   
        //Rational r = r1;     
        Integer w = r.getWhole();
        Integer n = r.getNum();
        Integer d = r.getDen();
        w.setPositive(true);
        n.setPositive(true);
        d.setPositive(true);

        if (isZero(w) && isZero(n)) {
            ostr << "0";
            return ostr;
        }

        if (!r.isPos()) {
            ostr << '-';
        }

        if ((!isZero(w)) && (!isZero(n))) {
            ostr << w << "." << n;
            if (!isZero(d) && !isOne(d)) {
                ostr << "/" << d;
            }
            return ostr;
        } else {
            ostr << w;
            return ostr;
        }
	}

    // The input stream operator >>
	std::istream& operator>>(std::istream& istr, Rational& r) {
		std::string strValue;
		istr >> strValue;
		r = Rational(strValue);
        return istr;
	}

    // The comparison operator <
	bool operator<(const Rational& lhs, const Rational& rhs) {
        if (lhs == rhs) {
            return false;
        } 
        Rational r1 = unsimplify(lhs);
        Rational r2 = unsimplify(rhs);
        Integer i1 = (r1.getNum() * r2.getDen());
        Integer i2 = (r2.getNum() * r1.getDen());
        i1.setPositive(lhs.isPos());
        i2.setPositive(rhs.isPos());     
        if (i1 < i2) {
            i1.setPositive(true);
            i2.setPositive(true);
            return true;
        }
		return false;
	}

    // The comparison operator >
	bool operator>(const Rational& lhs, const Rational& rhs) {
		if ((lhs < rhs) || (lhs == rhs)) {
            return false;
        }
		return true;
	}

    // The comparison operator <=
	bool operator<=(const Rational& lhs, const Rational& rhs) {
        if ((lhs == rhs) || (lhs < rhs)) {
            return true;
        }
		return false;
	}

    // The comparison operator >=
	bool operator>=(const Rational& lhs, const Rational& rhs) {
		if (lhs < rhs) {
            return false;
        }
		return true;
	}

    // The comparison operator ==
	bool operator==(const Rational& lhs, const Rational& rhs) {
        if (lhs.isPos() == rhs.isPos()) {
            Rational r1 = unsimplify(lhs);
            Rational r2 = unsimplify(rhs);
            Integer i1 = (r1.getNum() * r2.getDen());
            Integer i2 = (r2.getNum() * r1.getDen());
            i1.setPositive(lhs.isPos());
            i2.setPositive(rhs.isPos());     
            if (i1 == i2) {
                i1.setPositive(true);
                i2.setPositive(true);
                return true;
            }
        }
		return false;
	}

    // The comparison operator !=
	bool operator!=(const Rational& lhs, const Rational& rhs) {
        if (lhs == rhs) {
            return false;
        }
		return true;
	}

}