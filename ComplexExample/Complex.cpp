#include "Complex.h"

namespace cosc326 {

	Complex::Complex() : real_(0), imag_(0) {

	}

	Complex::Complex(double real) : real_(real), imag_(0) {

	}

	Complex::Complex(double real, double imag) : real_(real), imag_(imag) {

	}

	Complex::Complex(const std::string& str) : real_(0), imag_(0) {
		// Note - NO ERROR CHECKING. Be careful out there!

		// Check if there's an imaginary part
		if (str.back() == 'i') {
			// check for an internal + or -
			if (str.find('+', 1) != std::string::npos) {
				// real+imag
				size_t cutPoint = str.find('+', 1);
				std::string realStr = str.substr(0, cutPoint);
				std::string imagStr = str.substr(cutPoint, -1); // drop trailing i
				real_ = std::atof(realStr.c_str());
				imag_ = std::atof(imagStr.c_str());
			} else if (str.find('-', 1) != std::string::npos) {
				// real-imag
				size_t cutPoint = str.find('-', 1);
				std::string realStr = str.substr(0, cutPoint);
				std::string imagStr = str.substr(cutPoint, -1); // drop trailing i
				real_ = std::atof(realStr.c_str());
				imag_ = std::atof(imagStr.c_str());
			} else {
				// just an imaginary value
				imag_ = std::atof(str.c_str());
			}
		} else {
			// Just a real part
			real_ = std::atof(str.c_str());
		}
	}

	Complex::Complex(const Complex& comp) : real_(comp.real_), imag_(comp.imag_) {

	}

	Complex::~Complex() {

	}

	Complex& Complex::operator=(const Complex& comp) {
		// Check you aren't yourself cos if a=a just return, you're done
		if (this != &comp) {
			// Not self-assignment
			real_ = comp.real_;
			imag_ = comp.imag_;
		}
		// Return the actual object not the reference?????
		return *this;
	}

	Complex& Complex::operator+=(const Complex& comp) {
		real_ += comp.real_;
		imag_ += comp.imag_;
		return *this;
	}

	Complex& Complex::operator*=(const Complex& comp) {
		double r1 = real_;
		double i1 = imag_;
		double r2 = comp.real_;
		double i2 = comp.imag_;
		real_ = r1*r2 - i1*i2;
		imag_ = r1*i2 + r2*i1;
		return *this;
	}

	double Complex::getRealPart() const {
		return real_;
	}

	double Complex::getImagPart() const {
		return imag_;
	}

// Copy constructor, make a c1 not a reference to. 
	Complex operator+(const Complex& c1, const Complex& c2) {
		Complex sum(c1);
		sum += c2;
		return sum;
	}

	Complex operator*(const Complex& c1, const Complex& c2) {
		Complex product(c1);
		product *= c2;
		return product;
	}

// Streaming operators. Return a copy of the string passed in
// input string not const cos we are writing to it
	std::ostream& operator<<(std::ostream& ostr, const Complex& comp) {
		if (comp.getImagPart() < 0) {
			ostr << comp.getRealPart() << comp.getImagPart() << 'i';
		} else {
			ostr << comp.getRealPart() << "+" << comp.getImagPart() << 'i';
		}
		return ostr;
	}

	std::istream& operator>>(std::istream& istr, Complex& comp) {
		/* not the most efficient or general, but good enough */
		std::string value;
		istr >> value;
		comp = Complex(value);
		return istr;
	}

}