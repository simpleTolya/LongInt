//
// Created by Mixtape Armand on 11/24/21.
//

#ifndef LONGNUM_RSAOBJECT_H
#define LONGNUM_RSAOBJECT_H

#include "LongInt.h"

class RSAException : public std::exception
{
private:
	std::string		error_text;
public:
	RSAException(const std::string & _error_text) {
		error_text = _error_text;
	}
	RSAException(std::string && _error_text) {
		error_text = _error_text;
	}
	const char * what() const noexcept override {
		return error_text.c_str();
	}
};

class RSAEncoder
{
public:
	RSAEncoder(const LongInt & e, const LongInt & n) : e(e), n(n) {}
	LongInt	encode(const LongInt &m);
private:
	LongInt e, n;
};

class RSADecoder
{
public:
	RSADecoder(const LongInt & d, const LongInt & n) : d(d), n(n) {}
	LongInt	decode(const LongInt &m);
private:
	LongInt d, n;
};

class RSAGenerator {
	using testFunction = bool (*)(const LongInt &, unsigned int);
public:
	enum class PrimalityTest
	{
		Fermat,
		SolovayStrassen,
		MillerRabin
	};
	explicit RSAGenerator(PrimalityTest test = PrimalityTest::MillerRabin, long double min_probability = 0.9999,
			  unsigned int first_bit_count = 1024, unsigned int second_bit_count = 1024)
	{
		this->test = test;
		this->min_probability = min_probability;
		this->first_bit_count = first_bit_count;
		this->second_bit_count = second_bit_count;
	}
	RSAGenerator &	changeTest(PrimalityTest test);
	RSAGenerator &	changeProbability(long double min_probability);
	RSAGenerator &	changeFirstBitCount(unsigned int first_bit_count);
	RSAGenerator &	changeSecondBitCount(unsigned int second_bit_count);
	void 	generateNewKeys();
	std::pair <LongInt, LongInt>	getPublicKey();
	std::pair <LongInt, LongInt>	getPrivateKey();
private:
	PrimalityTest	test;
	long double 	min_probability;
	unsigned int	first_bit_count;
	unsigned int	second_bit_count;
	LongInt			d, e, n;
	static LongInt findNearestBigPrime(const LongInt &num,
									   long double min_probability, PrimalityTest test);
};


#endif //LONGNUM_RSAOBJECT_H
