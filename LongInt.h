//
// Created by Mixtape Armand on 11/10/21.
//

#ifndef LONGNUM_LONGINT_H
#define LONGNUM_LONGINT_H

#include <climits>
#include <list>
#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <complex>
#include <vector>
#include <cmath>
#include <exception>
#include <random>

class LongInt;

class RandomGenerator
{
public:
	virtual LongInt	generate(unsigned int bit_count) = 0;
	virtual ~RandomGenerator() = default;
};

class RandomLongIntGenerator : public RandomGenerator
{
private:
	std::random_device rd;
	std::mt19937 gen;
	std::uniform_int_distribution<> dist;
public:
	RandomLongIntGenerator() : gen(rd()), dist(0, 1) {}
	virtual LongInt	generate(unsigned int bit_count);
};

class LongInt {
	std::list<unsigned int>	digits;
	bool 	is_positive;
	static const unsigned long long	BASE = 100000; // 4294967296;
	static const unsigned long long MIN_SIMPLE_LEN = 20;
	static const unsigned long long MIN_KARATSUBA_LEN = 250;

	using ListIter = std::list<unsigned int>::iterator;
	using ull  = unsigned long long;
	using uint = unsigned int;
	using base = std::complex<long double>;
private:
	static unsigned long long toDecimal(char sym, unsigned base);
	bool		absGreater(const LongInt & num) const;
	LongInt		multiplicateDigit(unsigned int digit) const;
	LongInt &	_multiplicateKaratsuba(LongInt & other);
	void 		fft(std::vector<base> & a, bool invert);
	static void _extentedGCD(const LongInt &first, const LongInt &second,
					  LongInt &_x, LongInt &_y);
	void		clearZeros();
public:

	class Exception : public std::exception {
	private:
		std::string		error_text;
	public:
		Exception(const std::string & _error_text) {
			error_text = _error_text;
		}
		Exception(std::string && _error_text) {
			error_text = _error_text;
		}
		const char * what() const noexcept override {
			return error_text.c_str();
		}
	};

	~LongInt() = default;
	LongInt() {is_positive = true;};
	LongInt(unsigned int num);
	LongInt(int num);
	LongInt(__int128 num);
	LongInt(const LongInt &) = default;
	LongInt(LongInt &&) = default;
	LongInt &	operator=(const LongInt & ) = default;
	LongInt &	operator=(LongInt && ) = default;
	LongInt(const std::string & string, unsigned base = 10);
	LongInt &	operator+=(const LongInt & other);
	LongInt &	operator-=(const LongInt & other);
	LongInt &	multiplicateKaratsuba(const LongInt & other);
	LongInt &	multiplicateSimple(const LongInt & other);
	LongInt &	multiplicateFourier(const LongInt & other);
	LongInt &	operator*=(const LongInt & other);
	LongInt &	operator/=(const LongInt &other);
	LongInt &	operator%=(const LongInt &other);
	LongInt &	pow(unsigned long long degree);
	LongInt &	pow(const LongInt &degree, const LongInt & mod);
	LongInt &	operator<<=(unsigned int shift);
	LongInt &	operator>>=(unsigned int shift);
	bool		operator>=(const LongInt &num) const;
	bool 		operator==(const LongInt &num) const;
	bool		operator<=(const LongInt &num) const;
	bool 		operator!=(const LongInt &num) const;
	bool		operator>(const LongInt &num)  const;
	bool 		operator<(const LongInt &num)  const;
	bool		isEven() const;

	static LongInt	multiplicateKaratsuba(const LongInt &first, const LongInt & second);
	static LongInt	multiplicateSimple(const LongInt &first, const LongInt & second);
	static LongInt	multiplicateFourier(const LongInt &first, const LongInt & second);
	static LongInt	pow(const LongInt &num, unsigned long long degree);
	static LongInt	pow(const LongInt &num, const LongInt & degree, const LongInt & mod);

	// friend
	friend LongInt	operator+(const LongInt &first, const LongInt & second);
	friend LongInt	operator-(const LongInt &first, const LongInt & second);
	friend LongInt  operator*(const LongInt &first, const LongInt & second);
	friend LongInt	operator/(const LongInt &first, const LongInt & second);
	friend LongInt  operator%(const LongInt &first, const LongInt & second);
	friend LongInt	operator<<(const LongInt &num, unsigned int shift);
	friend LongInt	operator>>(const LongInt &num, unsigned int shift);
	friend LongInt	operator+(const LongInt &num);
	friend LongInt	operator-(const LongInt &num);
	friend LongInt gcd(const LongInt &first, const LongInt & second);
	friend LongInt binarygcd(const LongInt &first, const LongInt & second);
	friend std::pair<LongInt, LongInt>
					extentedgcd(const LongInt &first, const LongInt &second);
	friend int	legendreSymbol(const LongInt &a, const LongInt & p);
	friend int  jacobySymbol(const LongInt &a, const LongInt &p);
	friend bool	isPrimeFermatTest(const LongInt &num, unsigned int parameter);
	friend bool	isPrimeSolovayStrassenTest(const LongInt &num, unsigned int parameter);
	friend bool isPrimeMillerRabinTest(const LongInt &num, unsigned int parameter);
	friend LongInt sqrt(const LongInt & num);
	friend std::ostream &operator<<(std::ostream &stream, const LongInt &num);
	friend std::istream &operator>>(std::istream &stream, LongInt &num);
};


bool	isPrimeFermatTest(const LongInt &num, unsigned int parameter = 10);
bool	isPrimeSolovayStrassenTest(const LongInt &num, unsigned int parameter = 10);
bool	isPrimeMillerRabinTest(const LongInt &num, unsigned int parameter = 10);
LongInt sqrt(const LongInt & num);
int 	jacobySymbol(const LongInt &a, const LongInt &p);
int		legendreSymbol(const LongInt &a, const LongInt & p);
std::pair<LongInt, LongInt> extentedgcd(const LongInt &first, const LongInt &second);
LongInt binarygcd(const LongInt &first, const LongInt & second);
LongInt gcd(const LongInt &first, const LongInt & second);
LongInt operator*(const LongInt &first, const LongInt & second);
LongInt	operator/(const LongInt &first, const LongInt & second);
LongInt operator%(const LongInt &first, const LongInt & second);
LongInt operator<<(const LongInt &num, unsigned int shift);
LongInt operator>>(const LongInt &num, unsigned int shift);
LongInt operator+(const LongInt &num);
LongInt operator-(const LongInt &num);
LongInt	operator+(const LongInt &first, const LongInt & second);
LongInt	operator-(const LongInt &first, const LongInt & second);


#endif //LONGNUM_LONGINT_H
