#include <iostream>
#include "Integer.h"

using namespace cosc326; 

/**
 * Main.cpp for E9 cosc326 testing purposes.
 * @author Finn Luxton and Nikolah Pearce
 */

int main() {

    // Test default constructor
    Integer i1("0875807236408611277849349374");
    std::cout << "i1 is: " << i1 << std::endl; 
    
    // Test the integer constructor
    Integer copyi1(i1);
    std::cout << "copyi1 is: " << i1 << std::endl; 

    // Test the string constuctor

    Integer i11("100");
    std::cout << "i1 is: " << i1 << std::endl; 
    Integer i21("99");
    std::cout << "i1 is: " << i1 << std::endl; 
    Integer i111("-50");
    std::cout << "i1 is: " << i1 << std::endl; 
    Integer i211("27");
    std::cout << "i1 is: " << i1 << std::endl; 

    Integer i2("+23456788765234564");
    std::cout << "i2 is: " << i2 << std::endl; 

    Integer i3("1000");
    std::cout << "i3 is: " << i3 << std::endl;
    Integer i4("333");
    std::cout << "i4 is: " << i4 << std::endl;
    
    Integer i5("-20");
    std::cout << "i5 is: " << i5 << std::endl;
    Integer i6("-15");
    std::cout << "i6 is: " << i6 << std::endl;


    Integer i51("10");
    std::cout << "i5 is: " << i51 << std::endl;
    Integer i61("25");
    std::cout << "i6 is: " << i61 << std::endl;

    Integer i52("-10");
    std::cout << "i5 is: " << i52 << std::endl;
    Integer i62("-32");
    std::cout << "i6 is: " << i62 << std::endl;

    Integer i7("30");
    std::cout << "i7 is: " << i7 << std::endl;
    Integer i8("10");
    std::cout << "i8 is: " << i8 << std::endl;

    Integer i9("10000");
    std::cout << "i9 is: " << i9 << std::endl;
    Integer i10("2222");
    std::cout << "i10 is: " << i10 << std::endl;

    Integer i15("15");
    Integer i16("5");
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

    s = (i11 + i21);
    std::cout << "The sum of " << i11 << " + " << i21 << " = " << s << std::endl;

    s = (i111 + i211);
    std::cout << "The sum of " << i111 << " + " << i211 << " = " << s << std::endl;
    
    // Subtraction
    Integer s2 = (i3 - i4);
    std::cout << "The sum of "<< i3 << " - " << i4 << " = " << s2 << std::endl;

    s2 = (i5 - i6);
    std::cout << "The sum of "<< i5 << " - " << i6 << " = " << s2 << std::endl;
    s2 = (i51 - i61);
    std::cout << "The sum of "<< i51 << " - " << i61 << " = " << s2 << std::endl;
    s2 = (i52 - i62);
    std::cout << "The sum of "<< i52 << " - " << i62 << " = " << s2 << std::endl;

    s2 = (i7 - i8);
    std::cout << "The sum of "<< i7 << " - " << i8 << " = " << s2 << std::endl;

    s2 = (i9 - i10);
    std::cout << "The sum of "<< i9 << " - " << i10 << " = " << s2 << std::endl;


    //Multiplication
	std::cout << "The product of "<< i15 << " * " << i16 << " = " << i15 * i16 << std::endl;
/*
	std::cout << "Please enter new values for i1 and i2." << std::endl;
	std::cin >> i1 >> i2;
    std::cout << "Now, i1 = " << i1 << " and i2 = " << i2 << std::endl;

	std::cout << "New, i1 + i2 = " << i1 + i2 << std::endl;
	std::cout << "New, i1 * i2 = " << i1 * i2 << std::endl;
    */
    return 0;
}

