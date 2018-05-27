
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
        num.setPositive(true);
        den = one;
        whole = zero;
        pos = a.isPositive();
    }
    
    // Takes in two Integers to create a Rational (a/b)
    Rational::Rational(const Integer& a, const Integer& b) {
        Integer zero;
        num = a;
        num.setPositive(true);
        den = b;
        den.setPositive(true);
        whole = zero;
        if ((a.isPositive()) && (b.isPositive())) {
            pos = true;
        } else if ((!a.isPositive()) && (!b.isPositive())) {
            pos = true;
        } else {
            pos = false;
        }

    }

    // Takes in three Integers to create a Rational (a + b/c)
    Rational::Rational(const Integer& a, const Integer& b, const Integer& c) {
        whole = a;
        whole.setPositive(true);
        num = b;
        num.setPositive(true);
        den = c;
        den.setPositive(true);
        if (a.isPositive()) {
            pos = true;
        } else {
            pos = false;
        }
    }

    // Constructs with a string parameter
    Rational::Rational(const std::string& str1){
        Integer n;
        Integer d;
        Integer w;
        int temp, i, len;

        std::string str = str1;
        // Find and ignore any trailing -'s or +'s
        if (str.find('-') != std::string::npos) {
            i = 1;
            pos = false;
        } else if (str.find('+') != std::string::npos) {
            i = 1;
            pos = true;
        } else if (str.find('/') != std::string::npos) {

        } else if (str.find('.') != std::string::npos) {

        } 

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
	Rational& Rational::operator+=(const Rational& r) {
		return *this;
	}

    // Compound assignment operator -=
	Rational& Rational::operator-=(const Rational& r) {
		return *this;
	}

    // Compound assignment operator *=
	Rational& Rational::operator*=(const Rational& r) {
		return *this;
	}

    // Compound assignment operator /=
	Rational& Rational::operator/=(const Rational& r) {
		return *this;
	}

    /**
     *  METHODS BELOW HERE ARE NOT PART OF THE CLASS
     */


    // Helper method to simplify
    Rational simplify(const Rational& r) {
        Rational r2;
        r2 = r;
        //Integer nines("999999");
        //r2.setNum(nines);
        
        // Utilise GCD 
        // Adjust

        return r2;
    } 

    // Helper method to UNsimplify
    Rational unsimplify(const Rational& r) {
        Rational r2;
        r2 = r;
        
        // Add the whole part back in
        // w.n/d ---> b/a ... where b = (w*d+n)
        return r2;
    }

    // Helper method to check if simplified
    bool isSimplified(const Rational& r) {
         // if GCD == 1 return true
        return false;
    }



    // The binary arithmetic operator +
   	Rational operator+(const Rational& lhs, const Rational& rhs) {
		return lhs;
	}

    // The binary arithmetic operator -
	Rational operator-(const Rational& lhs, const Rational& rhs) {
		return lhs;
	}

    // The binary arithmetic operator *
	Rational operator*(const Rational& lhs, const Rational& rhs) {
		return lhs;
	}

    // The binary arithmetic operator /
	Rational operator/(const Rational& lhs, const Rational& rhs) {
		return lhs;
	}

    // The print stream operator <<
	std::ostream& operator<<(std::ostream& ostr, const Rational& r1) {
		std::string numString;
        Rational r;
        r = simplify(r1);
        
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
		return true;
	}

    // The comparison operator >
	bool operator> (const Rational& lhs, const Rational& rhs) {
		return true;
	}

    // The comparison operator <=
	bool operator<=(const Rational& lhs, const Rational& rhs) {
		return true;
	}

    // The comparison operator >=
	bool operator>=(const Rational& lhs, const Rational& rhs) {
		return true;
	}

    // The comparison operator ==
	bool operator==(const Rational& lhs, const Rational& rhs) {
		return true;
	}

    // The comparison operator !=
	bool operator!=(const Rational& lhs, const Rational& rhs) {
		return true;
	}

}