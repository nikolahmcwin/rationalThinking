#include <iostream>
#include "Integer.h"

using namespace cosc326; 

/**
 * Main.cpp for E9 cosc326 testing purposes.
 * @author Finn Luxton and Nikolah Pearce
 */

int main() {

    Integer i15("99");
    Integer i16("1");
    std::cout << "i15 is: " << i15 << std::endl;
    std::cout << "i16 is: " << i16 << std::endl;

    Integer i151("-0");
    Integer i161("-2222");
    std::cout << "i151 is: " << i151 << std::endl;
    std::cout << "i161 is: " << i161 << std::endl;

    Integer i17("5675678765765867586785678567856758675865");
    Integer i18("9999999999999999999999999999999999999999");

    Integer i19("100703089");
    Integer i20("90301");

    Integer i2111("10002030300209000202030004040580092010109200029302030209320039200029302002930202092039200");
    Integer i22("299302030003920390343040340003043032030401024012030230040234020503060700803506030602304034013040103");

    Integer i23("-20210391293238");
    Integer i24("1002932384293923823");

    Integer i25("992930239230000303040000302302302032039393882000203020302020323230023020399434034030430400003943949342000239");
    Integer i26("9328737627848209301823102490090030403040020301023002302302030003020405052323");
    
   /* // Test the vector constructor works
    std::vector<int> s;
    s.push_back(0);
    s.push_back(9);
    s.push_back(1);
    Integer vecConstrucor(s);
    std::cout << "vecConstrucor is: " << vecConstrucor << std::endl;
*/
    
    
    // Test default constructor
    Integer i1("123456789");
    std::cout << "i1 is: " << i1 << std::endl;
    Integer i2("555444333");
    std::cout << "i2 is: " << i2 << std::endl;  
    
    // Test the string constuctor
    Integer i11("-99");
    std::cout << "i1 is: " << i11 << std::endl; 
    Integer i21("33");
    std::cout << "i21 is: " << i21 << std::endl; 
    Integer i111("-120");
    std::cout << "i111 is: " << i111 << std::endl; 
    Integer i211("-12");
    std::cout << "i211 is: " << i211 << std::endl; 


     int t = (1/10);
    std::cout << "The t is ------> "<< t << std::endl;

    // DIVISION LOL 
    Integer s1 = i1 / i2;
	std::cout << "The product of "<< i1 << " / " << i2 << " = " << s1 << std::endl;

    s1 = i1 % i2;
	std::cout << "The mod remainded  of "<< i1 << " % " << i2 << " = " << s1 << std::endl;
    s1 = gcd(i1, i2);
	std::cout << "The gcd of "<< i1 << " & " << i2 << " = " << s1 << std::endl;


    s1 = i11 / i21;
	std::cout << "The product of "<< i11 << " / " << i21 << " = " << s1 << std::endl;

    s1 = i111 / i211;
	std::cout << "The product of "<< i111 << " / " << i211 << " = " << s1 << std::endl;

    s1 = i21 / i11;
	std::cout << "The product of "<< i21 << " / " << i11 << " = " << s1 << std::endl;
    s1 = i211 / i111;
	std::cout << "The product of "<< i211 << " / " << i111 << " = " << s1 << std::endl;
    s1 = i2 / i1;
	std::cout << "The product of "<< i2 << " / " << i1 << " = " << s1 << std::endl;
   
/*
      // Test the integer constructor
    Integer copyi1(i1);
    std::cout << "copyi1 is: " << i1 << std::endl; 

    Integer i3("1000");
    std::cout << "i3 is: " << i3 << std::endl;
    Integer i4("333");
    std::cout << "i4 is: " << i4 << std::endl;
    
    Integer i5("-20");
    std::cout << "i5 is: " << i5 << std::endl;
    Integer i6("-15");
    std::cout << "i6 is: " << i6 << std::endl;

 // Addition
	Integer s = (i1 + i2);
    std::cout << "The sum of " << i1 << " + " << i2 << " = " << s << std::endl;

    s = (i11 + i21);
    std::cout << "The sum of " << i11 << " + " << i21 << " = " << s << std::endl;

    s = (i111 + i211);
    std::cout << "The sum of " << i111 << " + " << i211 << " = " << s << std::endl;


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

    //Multiplication
    Integer s1 = i1 * i2;
	std::cout << "The product of "<< i1<< " * " << i2 << " = " << s1 << std::endl;

    s1 = i21 * i11;
    std::cout << "The product of "<< i21<< " * " << i11 << " = " << s1 << std::endl;


    s1 = i211 * i111;
    std::cout << "The product of " << i211 << " * " << i111 << " = " << s1 << std::endl;

    
    s1 = i23 - i24;
    std::cout << "The product of " << i23 << " - " << i24 << " = " << s1 << std::endl;
    
    s1 = i25 - i26;
    std::cout << "The product of " << i25 << " - " << i26 << " = " << s1 << std::endl;


    s1 = i17 * i18;
    std::cout << "The product of " << i17 << " * " << i18 << " = " << s1 << std::endl;

    s1 = i19 * i20;
    std::cout << "The product of " << i19 << " * " << i20 << " = " << s1 << std::endl;
    

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
    t1 = (i1 <= i2);
    std::cout << i1 << " <= " << i2 << " gives: " << t1 << std::endl;

    t2 = (i3 <= i4);
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
    


	std::cout << "Please enter new values for i1 and i2." << std::endl;
	std::cin >> i1 >> i2;
    std::cout << "Now, i1 = " << i1 << " and i2 = " << i2 << std::endl;

	std::cout << "New, i1 + i2 = " << i1 + i2 << std::endl;
	std::cout << "New, i1 * i2 = " << i1 * i2 << std::endl;
    */
   
    return 0;

}

