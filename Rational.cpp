
#include "Rational.h"
#include "Integer.h"
/**
 * Rational.cpp for E9 COSC326
 * @author Finn Luxton and Nikolah Pearce
 */
 
namespace cosc326 {

    // Creates rational with value of 0
    Rational::Rational(){

    }

    // Creates rational that duplicates the provided rational
    Rational::Rational(const Rational& rat) {

    }
    
    // Takes in a single Integer input to create a Rational interpretation (a/1)
    Rational::Rational(const Integer& a){
        //numerator = a;
        //Integer("1");
        //denominator = tmp;
        //positive = a.isPositive();
    }
    
    // Takes in two Integers to create a Rationak interpretation (a/b)
    Rational::Rational(const Integer& a, const Integer& b){
        numerator = a;
        denominator = b;
        positive = true;
    }

    
    Rational::Rational(const Integer& a, const Integer& b, const Integer& c){
    
    }

    Rational::Rational(const std::string& str){

    }
    

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

    // The equal-either-way binary arithmetic operators: +, -, *
    Rational operator+(const Rational& rat1, const Rational& rat2) {
        return rat1;
    }
    Rational operator-(const Rational& rat1, const Rational& rat2) {
        return rat1;
    }
    Rational operator*(const Rational& rat1, const Rational& rat2) {
        return rat1;
    }


    // The streaming insertion and extraction operators: << and >>
    std::ostream& operator<<(std::ostream& ostr, const Rational& rat) {
        std::string numString;
        
        numString +=  "test print";

        ostr << numString;
        return ostr;
    }
	std::istream& operator>>(std::istream& istr, Rational& rat) {
        std::string strValue;
		istr >> strValue;
		rat = Rational(strValue);
        return istr;
    }
}