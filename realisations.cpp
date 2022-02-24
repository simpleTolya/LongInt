//
// Created by Mixtape Armand on 11/11/21.
//

#include "LongInt.h"

unsigned long long LongInt::toDecimal(char sym, unsigned base)
{
	unsigned long long	res = -1;
	if ((sym >= '0') and (sym <= '9'))
		res = (sym - '0');
	else if ((sym >= 'a') and (sym <= 'z'))
		res = (sym - 'a' + 10);
	if (res >= base)
		throw Exception("Not correct base system\n");
	if (res == ULLONG_MAX)
		throw Exception("Symbol isn't digit\n");
	return (res);
}

LongInt::LongInt(const std::string & string, unsigned base)
{
	if (base < 2 or base > 32)
		throw Exception("Base not supported\n");

	unsigned int index = 0;
	while (string[index] ==  ' ')
		index++;

	is_positive = true;
	if (string[index] ==  '-')
	{
		is_positive = false;
		index++;
	}

	std::string	dividend = string.substr(index);
	std::string new_dividend;

	while (not dividend.empty()) {
		index = 0;
		ull current_digit = 0;
		while (index < dividend.length()) {
			current_digit *= base;
			current_digit += toDecimal(dividend[index], base);
			new_dividend.push_back(static_cast<char>(current_digit / BASE + '0'));
			current_digit %= LongInt::BASE;
			index++;
		}
		this->digits.push_back(current_digit);
		index = 0;
		for (; index < new_dividend.length(); ++index) {
			if (new_dividend[index] != '0')
				break;
		}
		if (index < new_dividend.length())
			dividend = new_dividend.substr(index);
		else
			dividend.clear();
		new_dividend.clear();
	}
	this->clearZeros();
}

LongInt &	LongInt::operator+=(const LongInt & other)
{
	auto first  = this->digits.begin();
	auto second = other.digits.cbegin();

	if (is_positive != other.is_positive) {
		if (this->absGreater(other)) {
			bool flag = false;
			while (flag or second != other.digits.cend()) {
				if (first == this->digits.end()) {
					break ;
				} else {
					ull res = static_cast<ull>(*first) + BASE - flag;
					if (second != other.digits.cend())
						res -= static_cast<ull>(*second);
					flag = res < BASE;
					(*first) = res % BASE;
				}
				++first;
				if (second != other.digits.cend())
					++second;
			}
		}
		else
		{
			this->is_positive = !this->is_positive;
			*this = other - *this;
		}
		this->clearZeros();
		if (this->digits.empty())
			this->is_positive = true;
		return *this;
	}

	bool flag = false;
	while (flag or second != other.digits.cend())
	{
		if (first == this->digits.end()) {
			ull	res = flag;
			if (second != other.digits.cend())
				res += static_cast<ull>(*second);
			flag = res >= BASE;
			this->digits.push_back(res % BASE);
			first = this->digits.end();
		} else {
			ull	res = flag + static_cast<ull>(*first);
			if (second != other.digits.cend())
				res += static_cast<ull>(*second);
			flag = res >= BASE;
			(*first) = res % BASE;
			++first;
		}
		if (second != other.digits.cend())
			++second;
	}
	this->clearZeros();
	return *this;
}

LongInt &	LongInt::operator-=(const LongInt & other)
{
	this->is_positive = !this->is_positive;
	*this += other;
	this->is_positive = !this->is_positive;
	if (this->digits.empty())
		this->is_positive = true;
	return *this;
}

LongInt &	LongInt::multiplicateKaratsuba(const LongInt & other)
{
	LongInt	_other(other);

	bool sign = this->is_positive == other.is_positive;
	_multiplicateKaratsuba(_other);
	this->is_positive = sign;
	if (this->digits.empty())
		is_positive = true;
	return *this;
}

LongInt &	LongInt::_multiplicateKaratsuba(LongInt & other)
{
	if (this->digits.size() < 3 or other.digits.size() < 3)
		return multiplicateSimple(other);

	while (this->digits.size() > other.digits.size())
		other.digits.push_back(0);
	while (this->digits.size() < other.digits.size())
		this->digits.push_back(0);

	unsigned int size = this->digits.size();

	LongInt first_left_part;
	LongInt first_right_part;

	ListIter middle = this->digits.begin();
	unsigned int middle_count = size / 2;
	for (unsigned i = 0; i < middle_count; ++i)
		++middle;

	first_right_part.digits.splice(first_right_part.digits.cbegin(),
								   this->digits, middle,
								   this->digits.end());
	first_left_part.digits.splice(first_left_part.digits.cbegin(),
								   this->digits, this->digits.begin(),
								   this->digits.end());

	LongInt second_left_part;
	LongInt second_right_part;

	middle = other.digits.begin();
	for (unsigned i = 0; i < middle_count; ++i)
		++middle;

	second_right_part.digits.splice(second_right_part.digits.cbegin(),
									other.digits, middle,
									other.digits.end());
	second_left_part.digits.splice(second_left_part.digits.cbegin(),
								   other.digits, other.digits.begin(),
								   other.digits.end());

	// (a1 + a2)(b1 + b2)
	LongInt first_sums  = (first_left_part + first_right_part);
	LongInt second_sums = (second_left_part + second_right_part);
	first_sums._multiplicateKaratsuba(second_sums);

	// a1b1
	first_left_part._multiplicateKaratsuba(second_left_part);

	// a2b2
	first_right_part._multiplicateKaratsuba(second_right_part);

	*this = (first_right_part << (middle_count * 2)) +
			 ((first_sums - first_left_part - first_right_part) << (middle_count)) +
			   first_left_part;
	this->clearZeros();
	return *this;
}

LongInt &	LongInt::multiplicateSimple(const LongInt & other)
{
	LongInt res;
	unsigned int shift = 0;
	for (auto digit : other.digits)
	{
		res += ((this->multiplicateDigit(digit)) << shift);
		shift++;
	}
	res.is_positive = this->is_positive == other.is_positive;
	*this = res;
	if (this->digits.empty())
		is_positive = true;
	return *this;
}

void LongInt::fft(std::vector<base> & a, bool invert) {
	auto size = a.size();
	if (size == 1)  return;

	std::vector<base> a0 (size / 2);
	std::vector<base> a1 (size / 2);
	for (unsigned i = 0, j = 0; i < size; i +=2 , ++j) {
		a0[j] = a[i];
		a1[j] = a[i + 1];
	}
	fft (a0, invert);
	fft (a1, invert);

	double ang = 2 * M_PI / static_cast<double>(size) * (invert ? -1 : 1);
	base w (1),  wn (cos(ang), sin(ang));
	for (unsigned int i = 0; i < size / 2; ++i) {
		a[i] = a0[i] + w * a1[i];
		a[i + size / 2] = a0[i] - w * a1[i];
		if (invert)
			a[i] /= 2,  a[i + size / 2] /= 2;
		w *= wn;
	}
}

LongInt &	LongInt::multiplicateFourier(const LongInt & other)
{
	LongInt res;

	res.is_positive = this->is_positive == other.is_positive;

	std::vector <base> fa(this->digits.begin(), this->digits.end());
	std::vector <base> fb(other.digits.begin(), other.digits.end());

	size_t size = 1;
	while (size < std::max(this->digits.size(), other.digits.size()))  size <<= 1;
	size <<= 1;
	fa.resize(size);
	fb.resize(size);

	fft (fa, false);
	fft (fb, false);
	for (size_t i = 0; i < size; ++i)
		fa[i] *= fb[i];
	fft (fa, true);

	__int128 count = 0;
	for (auto elem : fa) {
		__int128 tmp  = static_cast<__int128>(elem.real() + 0.5) + (count);
		count = 0;
		if (tmp < 0)
		{
			count = -1 + ((tmp + 1) / BASE);
			tmp -= BASE * count;
		}
		if (tmp >= BASE)
		{
			count = (tmp / BASE);
			tmp -= BASE * count;
		}
		res.digits.push_back(tmp % BASE);
	}
	this->digits.push_back(count);
	*this = res;
	this->clearZeros();
	if (this->digits.empty())
		this->is_positive = true;
	return *this;
}


LongInt &	LongInt::operator/=(const LongInt &other)
{
	if (other.digits.empty())
		throw Exception("Division by zero");

	if (this->digits.size() < other.digits.size())
		return (*this) = LongInt(0);

	LongInt _other(other);
	bool sign = this->is_positive == other.is_positive;
	this->is_positive = true;
	_other.is_positive = true;

	int iter_count = 0;
	if (this->digits.size() - other.digits.size() > 1)
		iter_count = std::ceil(log2(this->digits.size() - other.digits.size()));
	iter_count += 1;

	// optimisation
	__int128 _tmp = BASE * BASE * BASE;
	__int128 _tmp2 = BASE * (*--other.digits.cend());
	if (other.digits.size() > 1)
		_tmp2 += (*----other.digits.cend());
	_tmp /= _tmp2;

	LongInt x(_tmp);

	unsigned long long n = other.digits.size() + 1;
	for (int i = 0; i != iter_count; i++)
	{
		x = ((LongInt(2) << n) - (_other * x)) * x;
		n *= 2;
		unsigned int best_n = std::pow(2, i) + other.digits.size() + 1;
		x >>= (n - best_n);
		n = best_n;
	}

	x *= *this;
	x >>= n;

	if ((x + 1) * _other <= *this)
		x += 1;
	*this = x;
	this->is_positive = sign;
	this->clearZeros();
	if (this->digits.empty())
		this->is_positive = true;
	return *this;
}

LongInt &	LongInt::pow(unsigned long long degree)
{
	if (degree == 0)
		return ((*this) = 1);
	degree--;
	LongInt res(*this);
	while (degree)
	{
		if (degree % 2 == 0)
		{
			(*this) *= (*this);
			degree /= 2;
		}
		else
		{
			(res) *= *this;
			degree--;
		}
	}
	*this = res;
	return (*this);
}

LongInt &	LongInt::pow(const LongInt &degree, const LongInt & mod)
{
	if (mod == 0)
		throw Exception("Mod by zero");
	if (degree == 0) {
		(*this) = 1;
		if (mod == 1)
			(*this) = 0;
		return (*this);
	}
	LongInt _degree(degree);
	_degree -= 1;
	(*this) %= mod;
	LongInt res(*this);
	while (_degree != 0)
	{
		if (_degree.isEven())
		{
			(*this) *= (*this);
			*this %= mod;
			_degree /= 2;
		}
		else
		{
			(res) *= *this;
			res %= mod;
			_degree -= 1;
		}
	}
	*this = res;
	return (*this);
}

LongInt &	LongInt::operator<<=(unsigned int shift)
{
	for (unsigned _shift = 0; _shift != shift and (not this->digits.empty()); ++_shift)
		this->digits.push_front(0);
	return *this;
}

LongInt &	LongInt::operator>>=(unsigned int shift)
{
	for (unsigned _shift = 0; _shift != shift and (not this->digits.empty()); ++_shift)
		this->digits.pop_front();
	return *this;
}

std::istream &operator>>(std::istream &stream, LongInt &num)
{
	std::string	str;
	stream >> str;
	num = LongInt(str, 10);
	return stream;
}

std::ostream &operator<<(std::ostream &stream, const LongInt &num) {
	std::string res = "0";
	std::string start;

	if (num.digits.empty())
	{
		stream << "0";
		return stream;
	}
	for (auto it = num.digits.crbegin(); it != num.digits.crend(); ++it) {
		LongInt::ull ost = *it;
		start = "";
		for (uint i = res.length() - 1; ; --i) {
			LongInt::ull _digit = res[i] - '0';
			ost += _digit * LongInt::BASE;
			if (i == 0)
				start.insert(0, std::to_string(ost));
			else
				start.insert(0, std::to_string(ost % 10));
			ost /= 10;
			if (i == 0)
				break;
		}
		res = start;
	}
	if (not num.is_positive) {
		stream << "-";
	}
	stream << start;
	return stream;
}

bool LongInt::operator>=(const LongInt &num) const {
	if (this->is_positive != num.is_positive)
	{
		if (this->is_positive)
			return true;
		return false;
	}
	return absGreater(num);
}



bool LongInt::operator==(const LongInt &num) const {
	if (this->is_positive != num.is_positive)
		return false;
	if (this->digits.size() != num.digits.size())
		return false;
	auto	first = this->digits.begin();
	auto	second = num.digits.cbegin();
	while (first != this->digits.end() and second != num.digits.cend())
	{
		if (*first != *second)
			return false;
		++first;
		++second;
	}
	return true;
}

bool LongInt::absGreater(const LongInt &num) const {
	if (this->digits.size() != num.digits.size())
		return this->digits.size() > num.digits.size();
	auto	first = this->digits.rbegin();
	auto	second = num.digits.crbegin();
	while (first != this->digits.rend() and second != num.digits.crend())
	{
		if (*first < *second)
			return false;
		else if (*first > *second)
			return true;
		++first;
		++second;
	}
	return true;
}

void LongInt::clearZeros() {
	while (not this->digits.empty() and this->digits.back() == 0)
		this->digits.pop_back();
}

LongInt LongInt::multiplicateDigit(unsigned int digit) const {
	LongInt res;
	res.is_positive = is_positive;

	ull remainder = 0;
	for (auto _digit : this->digits)
	{
		ull tmp = (remainder + static_cast<ull>(_digit) * digit);
		res.digits.push_back(tmp % BASE);
		remainder = tmp / BASE;
	}
	if (remainder)
		res.digits.push_back(remainder);
	return res;
}

LongInt &LongInt::operator*=(const LongInt &other) {
	if (std::max(this->digits.size(), other.digits.size()) < MIN_SIMPLE_LEN)
		return multiplicateSimple(other);
	if (std::max(this->digits.size(), other.digits.size()) < MIN_KARATSUBA_LEN)
		return multiplicateKaratsuba(other);
	return multiplicateFourier(other);
}

LongInt &LongInt::operator%=(const LongInt &other) {
	if (other.digits.empty())
		throw Exception("Mod by zero");
	LongInt div = *this / other;
	div *= other;
	*this -= div;
	return *this;
}

LongInt gcd(const LongInt &first, const LongInt &second) {
	LongInt _first(first); // n
	LongInt _second(second); // m

	while (true)
	{
		if (_first == LongInt(0))
			return _second;
		if (_second == LongInt(0))
			return _first;
		if (_first >= _second)
			_first %= _second;
		else
			_second %= _first;
	}
}

LongInt binarygcd(const LongInt &first, const LongInt &second) {
	LongInt _first(first);
	LongInt _second(second);

	LongInt mul(1);
	while (true)
	{
		if (_first == LongInt(0))
			return mul * _second;
		if (_second == LongInt(0))
			return mul * _first;
		bool firstIsEven = _first.isEven();
		bool secondIsEven = _second.isEven();
		if (firstIsEven and secondIsEven)
		{
			mul *= 2;
			_first /= 2;
			_second /= 2;
		}
		else if (firstIsEven and not secondIsEven)
		{
			_first /= 2;
		}
		else if (not firstIsEven and secondIsEven)
		{
			_second /= 2;
		}
		else
		{
			if (_first > _second)
			{
				_first -= _first;
				_first /= 2;
			}
			else
			{
				_second -= _first;
				_second /= 2;
			}
		}
	}
}

bool LongInt::isEven() const {
	//if (BASE % 2 == 0)
	{
		if (this->digits.empty())
			return true;
		if ((*(this->digits.begin())) % 2 == 0)
			return true;
		return false;
	} /*
	else
	{
		return (*this) == 0;
 	}
	*/
}

std::pair<LongInt, LongInt> extentedgcd(const LongInt &first, const LongInt &second) {
	std::pair<LongInt, LongInt>	res;
	LongInt::_extentedGCD(first, second, res.first, res.second);
	return res;
}

void LongInt::_extentedGCD(const LongInt &first, const LongInt &second,
						   LongInt &x_mul, LongInt &y_mul) {
	if (first == 0) {
		x_mul = 0; y_mul = 1;
		return ;
	}
	LongInt x1, y1;
	_extentedGCD(second % first, first, x1, y1);
	x_mul = y1 - (second / first) * x1;
	y_mul = x1;
}

int legendreSymbol(const LongInt &a, const LongInt &p)
{
	// if p is prime
	if (a % p == 0)
		return (0);
	if (LongInt::pow(a, (p - 1) / 2, p) == 1)
		return (1);
	return (-1);
}

int jacobySymbol(const LongInt &a, const LongInt &p)
{
	int res = 1;
	LongInt _a(a);
	LongInt _p(p);
	if (not _a.is_positive)
	{
		_a.is_positive = true;
		LongInt tmp = _p - 1;
		static_assert(LongInt::BASE % 4 == 0, "The number system must be "
											  "divisible by 4 in the current algorithm\n");
		if ((*tmp.digits.cbegin()) % 4 != 0)
			res = -1;
	}
	while (true)
	{
		while (_a.isEven())
		{
			_a /= 2;
			LongInt tmp(_p);
			tmp *= tmp;
			tmp -= 1;
			static_assert(LongInt::BASE % 16 == 0, "The number system must be "
												  "divisible by 16 in the current algorithm\n");
			if ((*tmp.digits.cbegin()) % 16 != 0)
				res *= -1;
		}
		if (_a == 1)
			return res;
		if (_a < _p)
		{
			LongInt tmp = (_a - 1) * (_p - 1);
			static_assert(LongInt::BASE % 8 == 0, "The number system must be "
												   "divisible by 8 in the current algorithm\n");
			if ((*tmp.digits.cbegin()) % 8 != 0)
				res *= -1;
			std::swap(_a, _p);
		}
		_a %= _p;
		if (_a == 0)
			return (0);
	}
	// NOT OPTIMAL ALGORITHM
//	if (p.isEven())
//		throw LongInt::Exception("p number must not be even\n");
//	LongInt _p(p);
//
//	std::map<LongInt, unsigned int> factor;
//	while (_p.isEven())
//	{
//		auto it = factor.find(LongInt("2"));
//		if (it == factor.end())
//			factor[LongInt("2")] = 1;
//		else
//			(*it).second += 1;
//		_p /= 2;
//	}
//	LongInt sqrt_p = sqrt(_p);
//	sqrt_p += 1;
//	for (LongInt num = 3; num < sqrt_p; num += 2)
//	{
//		bool flag = false;
//		while (_p % num == 0)
//		{
//			auto it = factor.find(num);
//			if (it == factor.end())
//				factor[num] = 1;
//			else
//				(*it).second += 1;
//			_p /= num;
//			flag = true;
//		}
//		if (flag)
//			sqrt_p = sqrt(_p);
//	}
//	auto it = factor.find(_p);
//	if (it == factor.end())
//		factor[_p] = 1;
//	else
//		(*it).second += 1;
//	int res = 1;
//	for (const auto & elem : factor)
//	{
//		int legendreSym = legendreSymbol(a, elem.first);
//		if (legendreSym == 0)
//			return 0;
//		res *= std::pow(legendreSym, elem.second);
//	}
//	return res;
}

LongInt sqrt(const LongInt &num) {
	if (num == 0)
		return (0);
	LongInt x = 1;
	// optimisation
	x <<= ((num.digits.size() - 1) / 2);
	LongInt last_x;
	// x_n+1 = (x + num / x) / 2
	while (true)
	{
		last_x = x;
		x = (x + num / x) / 2;
		if (x == last_x)
			break ;
	}
	return (x);
}

bool isPrimeFermatTest(const LongInt &num, unsigned int parameter) {
	// a^(n - 1) mod n == 1    if a % num != 0
	if (num.isEven())
		return false;
	if (num > 12) {
		LongInt tmp(num - 2);
		for (unsigned int i = 0; i < parameter; i++) {
			if (LongInt::pow(tmp, num - 1, num) != 1)
				return false;
			tmp -= 1;
			if (tmp <= 2)
				return true;
		}
	}
	else
	{
		if (num == 2 or num == 3 or num == 5 or num == 7 or num == 11)
			return true;
		return false;
	}
	return true;
}

bool isPrimeSolovayStrassenTest(const LongInt &num, unsigned int parameter) {
	if (num.isEven())
		return false;
	LongInt _parameter;
	if (LongInt(parameter) <= (num - 2))
		_parameter = parameter;
	else
		_parameter = num - 2;
	LongInt a = 2;
	for (LongInt i = 0; i < _parameter; i += 1, a += 1)
	{
		if (gcd(a, num) > 1)
			return false;
		LongInt left  = LongInt::pow(a, (num - 1)/2, num);
		LongInt right = jacobySymbol(a, num);
		if (right == -1)
			right = num - 1;
		if (left != right)
			return false;
	}
	return true;
}

bool isPrimeMillerRabinTest(const LongInt &num, unsigned int parameter) {
	if (num.isEven())
		return false;
	LongInt t = num - 1;
	LongInt s = 0;
	// n - 1 -> 2^s * t
	while (t.isEven())
	{
		t /= 2;
		s += 1;
	}
	LongInt _parameter;
	if (LongInt(parameter) <= (num - 2))
		_parameter = parameter;
	else
		_parameter = num - 2;
	LongInt a = 2;
	for (LongInt i = 0; i < _parameter; a += 1, i += 1)
	{
		LongInt x = LongInt::pow(a, t, num);
		if (x == 1 or x == num - 1)
			continue ;
		bool flag = false ;
		for (LongInt j = 1; j < s; j += 1)
		{
			x.pow(2, num);
			if (x == 1)
				return false;
			if (x == num - 1)
			{
				flag = true;
				break ;
			}
		}
		if (flag)
			continue ;
		return false;
	}
	return true ;
}

LongInt		RandomLongIntGenerator::generate(unsigned int bit_count)
{
	LongInt random_num;
	for (unsigned int i = 0; i < bit_count; i++)
	{
		random_num *= 2;
		random_num += dist(gen);
	}
	return random_num;
}


