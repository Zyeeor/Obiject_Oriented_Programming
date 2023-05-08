#include <iostream>
#include "Fraction.hpp"

int main(){
	// Default Ctor;
	Fraction a(4, 1);
	// Stream output operator;
	std::cout << "a= " << a << std::endl;
	// Copying Ctor;
	Fraction b = a;
	// Numerical operators;
	std::cout << "b= " << b << std::endl;
	// Typecast double operator;
	std::cout << "(double)a= " << (double)a << std::endl;
	std::cout << "a+b= " << a + b << std::endl;
	std::cout << "a-b= " << a - b << std::endl;
	std::cout << "a/b= " << a / b << std::endl;
	std::cout << "a*b= " << a * b << std::endl;
	std::cout << "a>b= " << (a > b) << std::endl;
	std::cout << "a<b= " << (a < b) << std::endl;
	std::cout << "a>=b= " << (a >= b) << std::endl;
	std::cout << "a<=b= " << (a <= b) << std::endl;
	// Stream input operator;
	std::cout << "Please input a fraction c: " << std::endl;
	Fraction c;
	std::cin >> c;
	std::cout << "c= " << c << std::endl;
	// Transform from double;
	std::cout << "Please input a float c: " << std::endl;
	std::string C;
	std::cin >> C;
	std::cout << "c= " << Fraction(C) << std::endl;
	return 0;
}