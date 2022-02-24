//
// Created by Mixtape Armand on 11/10/21.
//

#include "LongInt.h"

LongInt operator*(const LongInt &first, const LongInt & second)
{
	LongInt	res(first);
	res *= second;
	return res;
}

LongInt operator%(const LongInt &first, const LongInt &second) {
	LongInt	res(first);
	res %= second;
	return res;
}

LongInt	LongInt::multiplicateKaratsuba(const LongInt &first, const LongInt & second)
{
	LongInt	res(first);
	res.multiplicateKaratsuba(second);
	return res;
}

LongInt	LongInt::multiplicateSimple(const LongInt &first, const LongInt & second)
{
	LongInt	res(first);
	res.multiplicateSimple(second);
	return res;
}

LongInt	LongInt::multiplicateFourier(const LongInt &first, const LongInt & second)
{
	LongInt	res(first);
	res.multiplicateFourier(second);
	return res;
}

LongInt LongInt::pow(const LongInt &num, unsigned long long degree)
{
	LongInt	res(num);
	res.pow(degree);
	return res;
}

LongInt LongInt::pow(const LongInt &num, const LongInt & degree, const LongInt & mod)
{
	LongInt	res(num);
	res.pow(degree, mod);
	return res;
}

LongInt	operator/(const LongInt &first, const LongInt & second)
{
	LongInt	res(first);
	res /= second;
	return res;
}

LongInt operator<<(const LongInt &num, unsigned int shift)
{
	LongInt res(num);
	res <<= shift;
	return res;
}

LongInt operator>>(const LongInt &num, unsigned int shift)
{
	LongInt res(num);
	res >>= shift;
	return res;
}

LongInt operator+(const LongInt &num)
{
	return LongInt(num);
}

LongInt operator-(const LongInt &num)
{
	LongInt res;
	res.is_positive = !res.is_positive;
	return res;
}

LongInt	operator+(const LongInt &first, const LongInt & second)
{
	LongInt res(first);
	res += second;
	return res;
}

LongInt	operator-(const LongInt &first, const LongInt & second)
{
	LongInt res(first);
	res -= second;
	return res;
}

LongInt::LongInt(__int128 num)
{
	is_positive = true;
	while (num) {
		digits.push_back(num % BASE);
		num /= BASE;
	}
}

LongInt::LongInt(unsigned int num)
{
	is_positive = true;
	while (num)
	{
		digits.push_back(num % BASE);
		num /= BASE;
	}
}

LongInt::LongInt(int num)
{
	is_positive = true;
	long long _num = num;
	if (num < 0) {
		is_positive = false;
		_num *= -1;
	}
	while (_num)
	{
		digits.push_back(_num % BASE);
		_num /= BASE;
	}
}

bool	LongInt::operator<=(const LongInt &num) const
{
	return num >= *this;
}

bool 	LongInt::operator!=(const LongInt &num) const
{
	return !(*this == num);
}

bool	LongInt::operator>(const LongInt &num) const
{
	return !(*this <= num);
}

bool 	LongInt::operator<(const LongInt &num) const
{
	return !(*this >= num);
}