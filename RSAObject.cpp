//
// Created by Mixtape Armand on 11/24/21.
//

#include "RSAObject.h"

LongInt RSAGenerator::findNearestBigPrime(const LongInt &num, long double min_probability,
										  RSAGenerator::PrimalityTest test) {
	LongInt tmp(num);
	if (tmp.isEven())
		tmp += 1;
	testFunction isPrime;
	if (test == PrimalityTest::Fermat)
		isPrime = isPrimeFermatTest;
	if (test == PrimalityTest::MillerRabin)
		isPrime = isPrimeMillerRabinTest;
	if (test == PrimalityTest::SolovayStrassen)
		isPrime = isPrimeSolovayStrassenTest;
	unsigned parameter = std::ceil(-log2(1 - min_probability));
	while (not isPrime(tmp, parameter))
		tmp += 2;
	return tmp;
}

void RSAGenerator::generateNewKeys() {
	RandomLongIntGenerator gen;
	LongInt tmp  = gen.generate(first_bit_count);
	LongInt first_prime = findNearestBigPrime(tmp, min_probability, test);
	tmp  = gen.generate(second_bit_count);
	LongInt second_prime = findNearestBigPrime(tmp, min_probability, test);
	// first_prime  = LongInt("111111111149");
	// second_prime = LongInt("999999999989");
	n = first_prime * second_prime;
	LongInt phi_n = (first_prime - 1) * (second_prime - 1);
	e = gen.generate(10);
	// e = 11;
	while (gcd(e, phi_n) != 1)
		e += 1;
	auto pair = extentedgcd(e, phi_n);

	// solve e^-1 * e = 1 mod (phi_n)

	if ((((pair.first % phi_n + phi_n) % phi_n) * e) % phi_n == 1)
		d = (pair.first % phi_n + phi_n) % phi_n;
	else if ((((pair.second % phi_n + phi_n) % phi_n) * e) % phi_n == 1)
		d = (pair.second % phi_n + phi_n) % phi_n;
}

RSAGenerator &RSAGenerator::changeTest(RSAGenerator::PrimalityTest test) {
	this->test = test;
	return *this;
}

RSAGenerator &RSAGenerator::changeProbability(long double min_probability) {
	this->min_probability = min_probability;
	return *this;
}

RSAGenerator &RSAGenerator::changeFirstBitCount(unsigned int first_bit_count) {
	this->first_bit_count = first_bit_count;
	return *this;
}

RSAGenerator &RSAGenerator::changeSecondBitCount(unsigned int second_bit_count) {
	this->second_bit_count = second_bit_count;
	return *this;
}

std::pair<LongInt, LongInt> RSAGenerator::getPublicKey() {
	return {e, n};
}

std::pair<LongInt, LongInt> RSAGenerator::getPrivateKey() {
	return {d, n};
}

LongInt RSAEncoder::encode(const LongInt &m) {
	if (m >= n)
		throw RSAException("Message is number which less than n\n");
	return LongInt::pow(m, e, n);
}

LongInt RSADecoder::decode(const LongInt &m) {
	if (m >= n)
		throw RSAException("Message is number which less than n\n");
	return LongInt::pow(m, d, n);
}
