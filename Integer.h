#include <iostream>
#include <string>

namespace e9 {

    Class Integer {

        // Constructors
        Integer();
        Integer(const Integer& integ)
        Integer(const std::string& str);

        // Destructor
        ~Integer();

        // Assignment operator =
        Integer& operator=(const Integer& integ);

        // The unary operators: + and -
            //WHAT?!

        // The inequal binary arithmetic operators /, and %
        Integer& operator/(const Integer& integ);
        Integer& operator%(const Integer& integ);

        // The compound assignment operators: +=, -=, *=, /=, and %=
        Integer& operator+=(const Integer& integ);
        Integer& operator-=(const Integer& integ);
        Integer& operator*=(const Integer& integ);
        Integer& operator/=(const Integer& integ);
        Integer& operator%=(const Integer& integ);

        // The comparison operators: ==, !=,<,<=,>, and >=
        Integer& operator==(const Integer& integ);
        Integer& operator!=(const Integer& integ);
        Integer& operator<(const Integer& integ);
        Integer& operator<=(const Integer& integ);
        Integer& operator>(const Integer& integ);
        Integer& operator>=(const Integer& integ);

        // Afunction,gcd(a,b),thatreturnsthegreatestcommondivisoroftwoIntegers

    }

    // The equal-either-way binary arithmetic operators: +, -, *
    Integer& operator+(const Integer& integ);
    Integer& operator-(const Integer& integ);
    Integer& operator*(const Integer& integ);


    // The streaming insertion and extraction operators: << and >>
    std::ostream& operator<<(std::ostream& ostr, const Integer& integ);
	std::istream& operator>>(std::istream& istr, Integer& integ);

}
