#include <iostream>
#include <string>

namespace e9 {

    Class Rational {

        // Constructors
        Rational();
        Rational(const Rational& rat)
        Rational(const std::string& str);

        // Destructor
        ~Rational();

        // Assignment operator =
        Rational& operator=(const Rational& rat);

        // The unary operators: + and -
            //WHAT?!

        // The inequal binary arithmetic operators /, and %
        Rational& operator/(const Rational& rat);
        Rational& operator%(const Rational& rat);

        // The compound assignment operators: +=, -=, *=, /=, and %=
        Rational& operator+=(const Rational& rat);
        Rational& operator-=(const Rational& rat);
        Rational& operator*=(const Rational& rat);
        Rational& operator/=(const Rational& rat);
        Rational& operator%=(const Rational& rat);

        // The comparison operators: ==, !=,<,<=,>, and >=
        Rational& operator==(const Rational& rat);
        Rational& operator!=(const Rational& rat);
        Rational& operator<(const Rational& rat);
        Rational& operator<=(const Rational& rat);
        Rational& operator>(const Rational& rat);
        Rational& operator>=(const Rational& rat);


    }

    // The equal-either-way binary arithmetic operators: +, -, *
    Rational& operator+(const Rational& rat);
    Rational& operator-(const Rational& rat);
    Rational& operator*(const Rational& rat);


    // The streaming insertion and extraction operators: << and >>
    std::ostream& operator<<(std::ostream& ostr, const Rational& rat);
	std::istream& operator>>(std::istream& istr, Rational& rat);

}
