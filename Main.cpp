#include <iostream>

#include "Integer.h"
//#include "Rational.h"

using namespace cosc326; 

/**
 * Main.cpp for E9 cosc326 testing purposes.
 * @author Finn Luxton and Nikolah Pearce
 */

int main() {

    // Test default constructor
    Integer i1;
    std::cout << "i1 is: " << i1 << std::endl; 
    
    // Test the integer constructor
    Integer copyi1(i1);
    std::cout << "copyi1 is: " << i1 << std::endl; 

    // Test the string constuctor
    Integer i2("-202");
    std::cout << "i2 is: " << i2 << std::endl; 
    Integer i3("+123456789");
    std::cout << "i3 is: " << i3 << std::endl;

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
  

    /*
    // Prove it was input correctly
	std::cout << "This program demonstrates Integer numbers." << std::endl;
    std::cout << "If i1 = " << i1 << " and i2 = " << i2 << " then:" << std::endl;
    
    // Addition
	Integer sum = i1 + i2;
    std::cout << "The sum i1 + i2 = " << sum << std::endl;
    
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

