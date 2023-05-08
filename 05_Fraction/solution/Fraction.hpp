#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <cstddef>
#include <numeric>
#include <iostream>
#include <sstream>
#include <string>
class Fraction{
	private:
	int denominator;
	int numerator;
	public:
	// Empty Ctor;
	Fraction() {}
	// Default Ctor;
	Fraction(int den, int num) : denominator(den), numerator(num) 
		{ if(denominator == 0) std::cerr << "Divisor cannot be ZERO!" << std::endl;}
	// Copy Ctor;
	Fraction(Fraction& a) : denominator(a.Denominator()), numerator(a.Numerator()) {}
	// From finite float Ctor;
	Fraction(std::string a){
		int pos = a.find('.');
		int times = a.length() - 1 - pos;
		int num = std::stoi(a.substr(0, pos)+a.substr(pos+1, a.size()));
		denominator = pow(10, times);
		numerator = num;
	}
	const int Denominator() { return denominator; }
	const int Numerator() { return numerator; }
	void Simplify(){
		int div = std::gcd(denominator, numerator);
		denominator = denominator/div;
		numerator = numerator/div;
	}
	// Typecast operators' overloading.
	operator double(){ return (double)numerator / (double)denominator; }
	operator std::string(){ return std::to_string(numerator)+"/"+std::to_string(denominator); }
	// Relational operators' overloading.
	inline Fraction operator+(Fraction another);
	inline Fraction operator-(Fraction another);
	inline Fraction operator*(Fraction another);
	inline Fraction operator/(Fraction another);
	inline const bool operator<(Fraction another);
	inline const bool operator>(Fraction another);
	inline const bool operator>=(Fraction another);
	inline const bool operator<=(Fraction another);
	inline const bool operator==(Fraction another);
	inline const bool operator!=(Fraction another);

	// Friend function to overload stream in operator;
	friend std::istream &operator>>(std::istream &in, Fraction &f){
		char divLine;
		int num, den;
		in >> num >> divLine >> den;
		if(!den){
			std::cerr << "Error! Divisor cannot be ZERO!" << std::endl;
			exit(0);
		}
		f.denominator = den;
		f.numerator = num;
		return in;
	}
	// Friend function to overload stream out operator;
	friend std::ostream &operator<<(std::ostream &out, Fraction &f){
		if(f.numerator){
			out << f.numerator << "/" << f.denominator;
		}else if(f.denominator == f.numerator){
			out << 1;
		}else{
			out << 0;
		}
		return out;
	}
};
inline Fraction Fraction::operator*(Fraction another){
	int den = this->Denominator() * another.Denominator();
	int num = this->Numerator() * another.Numerator();
	Fraction res(den, num);
	res.Simplify();
	return res;
}
inline Fraction Fraction::operator/(Fraction another){
	int den = this->Denominator() * another.Numerator();
	int num = this->Numerator() * another.Denominator();
	Fraction res(den, num);
	res.Simplify();
	return res;
}
inline Fraction Fraction::operator+(Fraction another){
	int aDen = denominator;
	int bDen = another.Denominator();
	int fDen = aDen * bDen;
	int fNum = aDen * another.numerator + bDen * numerator;
	Fraction res(fDen, fNum);
	res.Simplify();
	return res;
}
inline Fraction Fraction::operator-(Fraction another){
	int aDen = denominator;
	int bDen = another.Denominator();
	int fDen = aDen * bDen;
	int fNum = aDen * another.numerator - bDen * numerator;
	Fraction res(fDen, fNum);
	res.Simplify();
	return res;
}
inline const bool Fraction::operator>(Fraction another){
	return double(*this) > double(another);
}
inline const bool Fraction::operator<(Fraction another){
	return double(*this) < double(another);
}
inline const bool Fraction::operator>=(Fraction another){
	return double(*this) >= double(another);
}
inline const bool Fraction::operator<=(Fraction another){
	return double(*this) <= double(another);
}
inline const bool Fraction::operator==(Fraction another){
	this->Simplify();
	another.Simplify();
	return
		(this->numerator == another.numerator)&&
		(this->denominator == another.denominator);
}
inline const bool Fraction::operator!=(Fraction another){
	this->Simplify();
	another.Simplify();
	return
		!((this->numerator == another.numerator)&&
		(this->denominator == another.denominator));
}

#endif