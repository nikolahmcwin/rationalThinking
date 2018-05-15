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
    /*
    //Test the rational constructor
    Integer i5("100");
    std::cout << "i5 Rational is: " << i5 << std::endl;

    //Doesnt work yet? No idea why
    Rational r2(i5);
    std::cout << "r2 Rational is: " << r2 << std::endl;
    */
    /*
    // Test the Rational constructor
    //Rational copyr1(r1);
    //std::cout << "copyr1 is: " << r1 << std::endl; 

    // Test the string constuctor
    Rational r2("+65");
    std::cout << "r2 is: " << r2 << std::endl; 

    Rational r3("-13");
    std::cout << "r3 is: " << r3 << std::endl;
    Rational r4("-12");
    std::cout << "r4 is: " << r3 << std::endl;

    
    /*/
   

/*
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

