
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
        num = a;
        den = one;
        whole = zero;
        pos = a.isPositive();
        num.setPositive(true);
        
    }
    
    // Takes in two Integers to create a Rational (a/b)
    Rational::Rational(const Integer& a, const Integer& b) {
        Integer zero;
        num = a;
        den = b;
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

    // Takes in three Integers to create a Rational (a + b/c)
    Rational::Rational(const Integer& a, const Integer& b, const Integer& c) {
        whole = a;
        num = b;
        den = c;
        if (a.isPositive()) {
            pos = true;
        } else {
            pos = false;
        }
        whole.setPositive(true);
        num.setPositive(true);
        den.setPositive(true);
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

    // Mutator for setting all fields num, den, whole and pos
    void Rational::setAllFields(const Integer& n, const Integer& d, const Integer& w, bool p) {
        num = n;
        den = d;
        whole = w;
        pos = p;
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
		if (*this != r) {
            num = r.getNum();
            den = r.getDen();
            whole = r.getWhole();
            pos = r.isPos();
		}
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
        *this = unsimplify(*this);
        Integer newNum;
        newNum = (r.getNum() * den);
        den *= r.getDen();
        num *= r.getDen();
        num += newNum;
        //*this = simplify(*this);

		return *this;
	}

    // Compound assignment operator -=
	Rational& Rational::operator-=(const Rational& r1) {
        Rational r = unsimplify(r1);
        *this = unsimplify(*this);
        Integer newNum;
        newNum = (r.getNum() * den);
        den *= r.getDen();
        num *= r.getDen();
        num -= newNum;
        //*this = simplify(*this);
		return *this;
	}

    // Compound assignment operator *=
	Rational& Rational::operator*=(const Rational& r1) {
        Rational r = unsimplify(r1);
        *this = unsimplify(*this);
        den *= r.getDen();
        num *= r.getNum();
        //*this = simplify(*this);
		return *this;
	}

    // Compound assignment operator /=
	Rational& Rational::operator/=(const Rational& r1) {
		Rational r = unsimplify(r1);
        *this = unsimplify(*this);
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
        Integer n = r.getNum();
        Integer d = r.getDen();
        Integer w = r.getWhole();
    
        // If a/b > 1, set the whole part
        if (n >= d) {
            Integer tmp = n;
            // w = (n/d);
            // n = (n - (w*d));
        }
        // Simplify remaining fraction part 
        //Integer g = gcd(n, d);
        //n = (n / g);
        //d = (d / g);
        r2.setNum(n);
        r2.setDen(d);
        r2.setWhole(w);
        return r2;
    } 

    // Helper method to UNsimplify
    Rational unsimplify(const Rational& r) {
        Rational r2 = r;
        Integer zero;
        r2.setWhole(zero);
        Integer newNum = ((r.getWhole() * r.getDen()) + r.getNum());
        r2.setNum(newNum);
        return r2;
    }

    // Helper method to check if simplified
    bool isSimplified(const Rational& r) {
        //if (gcd(r.getNum(), r.getDen()) == 1) {
         //    return true
       // } 
        return false;
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
	std::ostream& operator<<(std::ostream& ostr, const Rational& r) {
		std::string numString;
        //Rational r = simplify(r1);
        
        if (!r.isPos()) {
            ostr << '-';
        }
        Integer w = r.getWhole();
        if (!isZero(w)) {
            ostr << w << ".";
        }
        ostr << r.getNum();
        Integer d = r.getDen();
        if (!isZero(d) && !isOne(d)) {
            ostr << "/" << d;
        }
        return ostr;
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
        if (i1 < i2) {
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
		Rational r1 = unsimplify(lhs);
        Rational r2 = unsimplify(rhs);
        Integer i1 = (r1.getNum() * r2.getDen());
        Integer i2 = (r2.getNum() * r1.getDen());    
        if (i1 == i2) {
            return true;
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