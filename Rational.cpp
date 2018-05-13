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
    Rational::Rational(const Integer& a){
    }
    Rational::Rational(const Integer& a, const Integer& b){
    }
    Rational::Rational(const Integer& a, const Integer& b, const Integer& c){
    }
    Rational::Rational(const std::string& str){
    }
    */

    // Deconstructor
    Rational::~Rational() {
    }

    Rational& Rational::operator=(const Rational& rat){
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
    }

}