#include <iostream>

#include "Integer.h"
#include "Rational.h"

using namespace cosc326; 

/**
 * Main.cpp for E9 cosc326 testing purposes.
 * @author Finn Luxton and Nikolah Pearce
 */

int main() {
        
    // Test default constructor
    Rational r1;
    std::cout << "r1 is: " << r1 << std::endl; 
    
    // Test the Rational copy constructor
    Rational copyr1(r1);
    std::cout << "copyr1 is: " << r1 << std::endl;

    //Test the Integer constructors
    Integer a("2");
    Integer b("4");
    Integer c("11");
    std::cout << "a is: " << a << std::endl;
    std::cout << "b is: " << b << std::endl;
    std::cout << "c is: " << c << std::endl;

    Rational r2(a);
    std::cout << "r2 is: " << r2 << std::endl;    
    Rational r3(a, b);
    std::cout << "r3 is: " << r3 << std::endl;
    Rational r4(a, b, c);
    std::cout << "r4 is: " << r4 << std::endl;
    

    // Test the Rational copy constructor
    Rational copyr3(r3);
    std::cout << "copyr3 is: " << copyr3 << std::endl;

    // Test the string constuctor
    Rational r21("5.1/3");
    std::cout << "r21 is: " << r21 << std::endl; 
    Rational r31("1.2/3");
    std::cout << "r31 is: " << r31 << std::endl;
    //Rational r41("3/9");
    //std::cout << "r41 is: " << r41 << std::endl;

    /*

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

  

    

    // Test the assignment operator =
    r1 = r2;
    std::cout << "r1 now = r2. r1: " << r1 << std::endl;

    // Test the unary operators + and -
    +r2;
    std::cout << "positive r2: " << r2 << std::endl;
    +r3;
    std::cout << "positive r3: " << r3 << std::endl;

    -r2;
    std::cout << "negated r2: " << r2  << std::endl;
    -r3;
    std::cout << "negated r3: " << r3 << std::endl;
    
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

    bool t1 = (r1 <= r2);
    std::cout << r1 << " <= " << r2 << " gives: " << t1 << std::endl;

    bool t2 = (r3 <= r4);
    std::cout << r3 << " <= " << r4 << " gives: " << t2 << std::endl;  
    
 
    // Addition
	Rational s = (r1 + r2);
    std::cout << "The sum of " << r1 << " + " << r2 << " = " << s << std::endl;
    
    // Subtraction
    //Rational s2 = r1 - r2;
    //std::cout << "The sum "<< r1 << " - " << r2 << " = " << s2 << std::endl;

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

