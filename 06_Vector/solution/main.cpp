#include <iostream>
#include <stdexcept>
#include "Vector.h"

int main(){
	Vector<int> a(4);
	for(int i = 0; i < a.size(); i++){
		a[i] = i;
		std::cout << a[i];
	}
	std::cout << std::endl;
	Vector<int> b = a;
	for(int i = 0; i < b.size(); i++){
		std::cout << b[i];
	}
	std::cout << "size of b: " << b.size() << std::endl;
	b.clear();
	std::cout << "after clear, size of b: " << b.size() << std::endl;
	std::cout << std::endl;
	std::cout << "size of a: " << a.size() << std::endl;
	a.push_back(5);
	for(int i = 0; i < a.size(); i++){
		std::cout << a[i];
	}
	std::cout << std::endl;
	std::cout << "size of a: " << a.size() << std::endl;
	try {
		std::cout << a.at(13) << std::endl;
	} catch (std::out_of_range orr){
		std::cerr << orr.what() << "FILE: " << __FILE__ << "LINE: " << __LINE__ << std::endl;
	}
	std::cout << "Test ends";
}