#include <iostream>

#include "Integer.h"
#include "Rational.h"

using namespace cosc326; 

/**
 * Main.cpp for E9 cosc326 testing purposes.
 * @author Finn Luxton and Nikolah Pearce
 */

int main() {
        /*
    // Test default constructor
    Rational r1("13/2");
    std::cout << "r1 is: " << r1 << std::endl; 
    
    // Test the Rational copy constructor
    Rational copyr1(r1);
    std::cout << "copyr1 is: " << r1 << std::endl;

    //Test the Integer constructors
    Integer a("1");
    Integer b("1");
    Integer c("11");
    std::cout << "a is: " << a << std::endl;
    std::cout << "b is: " << b << std::endl;
    std::cout << "c is: " << c << std::endl;

    Rational r20(a);
    std::cout << "r2 is: " << r20 << std::endl;    
    Rational r30(a, b);
    std::cout << "r3 is: " << r30 << std::endl;
    Rational r40(a, b, c);
    std::cout << "r4 is: " << r40 << std::endl;
    

    // Test the Rational copy constructor
    Rational copyr3(r30);
    std::cout << "copyr3 is: " << copyr3 << std::endl;
*/
    // Test the string constuctor
    Rational r2("-3");
    std::cout << "r21 is: " << r2 << std::endl; 
    Rational r3("-1/2");
    std::cout << "r31 is: " << r3 << std::endl;
    Rational r21("3/4");
    std::cout << "r21 is: " << r21 << std::endl; 
    Rational r31("-2/4");
    std::cout << "r31 is: " << r31 << std::endl;
    Rational r211("2.1/5");
    std::cout << "r21 is: " << r211 << std::endl; 
    Rational r311("1/3");
    std::cout << "r31 is: " << r311 << std::endl;
    //Rational r41("3/9");
    //std::cout << "r41 is: " << r41 << std::endl;

    //Addition
    
	Rational s = (r2 + r3);
    /*
    std::cout << "The +sum of " << r2 << " + " << r3 << " = " << s << std::endl;
    s = (r21 + r31);
    std::cout << "The +sum of " << r21 << " + " << r31 << " = " << s << std::endl;
    s = (r211 + r311);
    std::cout << "The +sum of " << r211 << " + " << r311 << " = " << s << std::endl;
    s = (r3 + r2);
    std::cout << "The +sum of " << r3 << " + " << r2 << " = " << s << std::endl;
    s = (r31 + r21);
    std::cout << "The +sum of " << r31 << " + " << r21 << " = " << s << std::endl;
    s = (r311 + r211);
    std::cout << "The +sum of " << r311 << " + " << r211 << " = " << s << std::endl;
    
    std::cout << "\n" << std::endl;
     
    // Subtraction
    s = (r2 - r3);
    std::cout << "The sum of " << r2 << " - " << r3 << " = " << s << std::endl;
    s = (r21 - r31);
    std::cout << "The sum of " << r21 << " - " << r31 << " = " << s << std::endl;
    */
    s = (r211 - r311);
    std::cout << "The sum of " << r211 << " - " << r311 << " = " << s << std::endl;
    /*s = (r3 - r2);
    std::cout << "The sum of " << r3 << " - " << r2 << " = " << s << std::endl;
    s = (r31 - r21);
    std::cout << "The sum of " << r31 << " - " << r21 << " = " << s << std::endl;
    s = (r311 - r211);
    std::cout << "The sum of " << r311 << " - " << r211 << " = " << s << std::endl;

    
    // Test the comparison operator ==
    bool t1 = (r1 == copyr1);
    std::cout << r1 << " == " << copyr1 << " gives: " << t1 << std::endl;

    bool t2 = (r2 == r3);
    std::cout << r2 << " == " << r3 << " gives: " << t2 << std::endl;  

    // Test the comparison operator !=
    bool t3 = (r1 != copyr1);
    std::cout << r1 << " != " << copyr1 << " gives: " << t3 << std::endl;

    bool t4 = (r2 != r3);
    std::cout << r2 << " != " << r3 << " gives: " << t4 << std::endl; 

    t1 = (r1 <= r2);
    std::cout << r1 << " <= " << r2 << " gives: " << t1 << std::endl;

    t2 = (r21 <= r31);
    std::cout << r21 << " <= " << r31 << " gives: " << t2 << std::endl;  
    t2 = (r21 < r31);
    std::cout << r21 << " < " << r31 << " gives: " << t2 << std::endl; 
    t2 = (r21 == r31);
    std::cout << r21 << " == " << r31 << " gives: " << t2 << std::endl; 
    t2 = (r21 >= r31);
    std::cout << r21 << " >= " << r31 << " gives: " << t2 << std::endl; 
    

    // Test the assignment operator =
    i1 = i2;
    std::cout << "i1 now = i2. i1: " << i1 << std::endl;

    // Test the unary operators + and -
    Integer ix;
    ix = +i2;
    std::cout << "positive i2: " << ix << std::endl;
    ix = +i3;
    std::cout << "positive i3: " << ix << std::endl;

    ix = -i2;
    std::cout << "negated i2: " << ix  << std::endl;
    ix = -i3;
    std::cout << "negated i3: " << ix << std::endl; 
    
   

    //Multiplication
	std::cout << "The product r1 * r2 = " << r1 * r2 << std::endl;

	std::cout << "Please enter new values for r1 and r2." << std::endl;
	std::cin >> r1 >> r2;
    std::cout << "Now, r1 = " << r1 << " and r2 = " << r2 << std::endl;

	std::cout << "New, r1 + r2 = " << r1 + r2 << std::endl;
	std::cout << "New, r1 * r2 = " << r1 * r2 << std::endl;
    */
    return 0;
}

