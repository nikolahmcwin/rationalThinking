#include <iostream>

#include "Complex.h"

int main() {

	cosc326::Complex c1(1, 3);  // 1+3i
	cosc326::Complex c2("-2-1i");

	std::cout << "This program demonstrates simple complex numbers." << std::endl;
	std::cout << "If c1 = " << c1 << " and c2 = " << c2 << " then:" << std::endl;
	cosc326::Complex sum = c1 + c2;
	std::cout << "The sum c1 + c2 = " << sum << std::endl;
	std::cout << "The product c1 * c2 = " << c1 * c2 << std::endl;

	std::cout << "Please new values for c1 and c2 in the form a+bi." << std::endl;
	std::cin >> c1 >> c2;

	std::cout << "c1 + c2 = " << c1 + c2 << std::endl;
	std::cout << "c1 * c2 = " << c1 * c2 << std::endl;

    return 0;
}

