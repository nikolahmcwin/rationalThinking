#include <iostream>
#include <string>
#include "Rational.h"
#include "Integer.h"
/**
 * Rational.cpp for E9 COSC326
 * @author Finn Luxton and Nikolah Pearce
 */
 
namespace cosc326 {

    /*
    Rational::Rational(){}
    }
    Rational::Rational(const Rational& rat) {
    }
    */

// DOESNT WORK YET
    // Takes in a single Integer input to create a Rational interpretation (a/1)
    Rational::Rational(const Integer& a){
        numerator = a;
        denominator = Integer::Integer("1");
        positive = a.isPositive();
    }
    
    // Takes in two Integers to create a Rationak interpretation (a/b)
    Rational::Rational(const Integer& a, const Integer& b){
        numerator = a;
        denominator = b;
        positive = true;
    }

    /*
    Rational::Rational(const Integer& a, const Integer& b, const Integer& c){
    }
    Rational::Rational(const std::string& str){
    }
    */

    // Deconstructor
    Rational::~Rational() {
    }

    /* Rational& Rational::operator=(const Rational& rat){
    }

    Rational& Rational::operator+(){
    }
    Rational& Rational::operator-(){
    }

    Rational& Rational::operator/(const Rational& rat){
    }
    Rational& Rational::operator%(const Rational& rat){     
    }

    Rational& Rational::operator+=(const Rational& rat){      
    }
    Rational& Rational::operator-=(const Rational& rat){       
    }
    Rational& Rational::operator*=(const Rational& rat){        
    }
    Rational& Rational::operator/=(const Rational& rat){        
    }
    Rational& Rational::operator%=(const Rational& rat){        
    }


    bool Rational::operator==(const Rational& rat){       
    }
    bool Rational::operator!=(const Rational& rat){     
    }
    bool Rational::operator<(const Rational& rat){ 
    }
    bool Rational::operator<=(const Rational& rat){  
    }
    bool Rational::operator>(const Rational& rat){
    }
    bool Rational::operator>=(const Rational& rat){
    }*/

}