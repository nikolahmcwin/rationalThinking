#include <iostream>

#include "Integer.h"

using namespace cosc326; 

/**
 * Main.cpp for E9 cosc326 testing purposes.
 * @author Finn Luxton and Nikolah Pearce
 */

int main() {

    // Test default constructor
    Integer i1("-10");
    std::cout << "i1 is: " << i1 << std::endl; 
    
    // Test the integer constructor
    Integer copyi1(i1);
    std::cout << "copyi1 is: " << i1 << std::endl; 

    // Test the string constuctor
    Integer i2("+33");
    std::cout << "i2 is: " << i2 << std::endl; 

    Integer i3("-20");
    std::cout << "i3 is: " << i3 << std::endl;
    Integer i4("-15");
    std::cout << "i4 is: " << i3 << std::endl;
    
    /*

    // Test the assignment operator =
    i1 = i2;
    std::cout << "i1 now = i2. i1: " << i1 << std::endl;

    // Test the unary operators + and -
    +i2;
    std::cout << "positive i2: " << i2 << std::endl;
    +i3;
    std::cout << "positive i3: " << i3 << std::endl;

    -i2;
    std::cout << "negated i2: " << i2  << std::endl;
    -i3;
    std::cout << "negated i3: " << i3 << std::endl;
    
    // Test the comparison operator ==
    bool t1 = (i1 == copyi1);
    std::cout << i1 << " == " << copyi1 << " gives: " << t1 << std::endl;

    bool t2 = (i2 == i3);
    std::cout << i2 << " == " << i3 << " gives: " << t2 << std::endl;  
    
   
    // Test the comparison operator !=
    bool t3 = (i1 != copyi1);
    std::cout << i1 << " != " << copyi1 << " gives: " << t3 << std::endl;

    bool t4 = (i2 != i3);
    std::cout << i2 << " != " << i3 << " gives: " << t4 << std::endl; 

    // Test <= operator
    bool t1 = (i1 <= i2);
    std::cout << i1 << " <= " << i2 << " gives: " << t1 << std::endl;

    bool t2 = (i3 <= i4);
    std::cout << i3 << " <= " << i4 << " gives: " << t2 << std::endl;  
    
    // Test < operator
    t1 = (i1 < i2);
    std::cout << i1 << " < " << i2 << " gives: " << t1 << std::endl;

    t2 = (i3 < i4);
    std::cout << i3 << " < " << i4 << " gives: " << t2 << std::endl; 

    // Test >= operator
    t1 = (i1 >= i2);
    std::cout << i1 << " >= " << i2 << " gives: " << t1 << std::endl;

    t2 = (i3 >= i4);
    std::cout << i3 << " >= " << i4 << " gives: " << t2 << std::endl;  
    
    // Test > operator
    t1 = (i1 > i2);
    std::cout << i1 << " > " << i2 << " gives: " << t1 << std::endl;

    t2 = (i3 > i4);
    std::cout << i3 << " > " << i4 << " gives: " << t2 << std::endl;
    */
    // Addition
	Integer s = (i1 + i2);
    std::cout << "The sum of " << i1 << " + " << i2 << " = " << s << std::endl;
    
    // Subtraction
    std::cout << "i3 is " << i3 << " i4 is " << i4 << std::endl;

    Integer s2 = (i3 - i4);
    std::cout << "The sum of "<< i3 << " - " << i4 << " = " << s2 << std::endl;
/*
    //Multiplication
	std::cout << "The product i1 * i2 = " << i1 * i2 << std::endl;

	std::cout << "Please enter new values for i1 and i2." << std::endl;
	std::cin >> i1 >> i2;
    std::cout << "Now, i1 = " << i1 << " and i2 = " << i2 << std::endl;

	std::cout << "New, i1 + i2 = " << i1 + i2 << std::endl;
	std::cout << "New, i1 * i2 = " << i1 * i2 << std::endl;
    */
    return 0;
}

