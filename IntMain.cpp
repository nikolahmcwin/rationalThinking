#include <iostream>
#include "Integer.h"

using namespace cosc326; 

/**
 * Main.cpp for E9 cosc326 testing purposes.
 * @author Finn Luxton and Nikolah Pearce
 */

int main() {

    Integer i15("-0");
    Integer i16("99");
    std::cout << "i15 is: " << i15 << std::endl;
    std::cout << "i16 is: " << i16 << std::endl;

    Integer i151("-2222");
    Integer i161("-4444");
    std::cout << "i151 is: " << i151 << std::endl;
    std::cout << "i161 is: " << i161 << std::endl;

    Integer i17("5675678765765867586785678567856758675865");
    Integer i18("9999999999999999999999999999999999999999");

    Integer i19("100703089");
    Integer i20("90301");

    Integer i21("10002030300209000202030004040580092010109200029302030209320039200029302002930202092039200");
    Integer i22("299302030003920390343040340003043032030401024012030230040234020503060700803506030602304034013040103");
    
   /* // Test the vector constructor works
    std::vector<int> s;
    s.push_back(0);
    s.push_back(9);
    s.push_back(1);
    Integer vecConstrucor(s);
    std::cout << "vecConstrucor is: " << vecConstrucor << std::endl;
*/
    //Multiplication
    Integer s1 = i15 * i16;
	std::cout << "The product of "<< i15 << " * " << i16 << " = " << s1 << std::endl;

    s1 = i151 * i161;
    std::cout << "The product of "<< i151 << " * " << i161 << " = " << s1 << std::endl;

    s1 = i17 * i18;
    std::cout << "The product of " << i17 << " * " << i18 << " = " << s1 << std::endl;

    s1 = i19 * i20;
    std::cout << "The product of " << i19 << " * " << i20 << " = " << s1 << std::endl;

    s1 = i21 * i22;
    std::cout << "The product of " << i21 << " * " << i22 << " = " << s1 << std::endl;
    /*
    // Test default constructor
    Integer i1("0456");
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
    */

/*
	std::cout << "Please enter new values for i1 and i2." << std::endl;
	std::cin >> i1 >> i2;
    std::cout << "Now, i1 = " << i1 << " and i2 = " << i2 << std::endl;

	std::cout << "New, i1 + i2 = " << i1 + i2 << std::endl;
	std::cout << "New, i1 * i2 = " << i1 * i2 << std::endl;
    */
    return 0;
}

