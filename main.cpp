#include <iostream>
#include "LongInt.h"
#include "RSAObject.h"


void do_test()
{
	std::cout << 1 << " " <<
		(LongInt("0", 10) == (LongInt("100", 10) - LongInt("100", 10)))
		<< "\n";
	std::cout << 2 << " " <<
			  (LongInt("0", 10) == (LongInt("-100", 10) + LongInt("100", 10)))
			  << "\n";
	std::cout << 3 << " " <<
			  (LongInt("0", 10) == (LongInt("100", 10) + LongInt("-100", 10)))
			  << "\n";
	std::cout << 4 << " " <<
			  (LongInt("0", 10) == (LongInt("-100", 10) - LongInt("-100", 10)))
			  << "\n";
	std::cout << 5 << " " <<
			  (LongInt("0", 10) == (LongInt("0", 10) - LongInt("0", 10)))
			  << "\n";
	std::cout << 6 << " " <<
			  (LongInt("0", 10) == (LongInt("0", 10) + LongInt("0", 10)))
			  << "\n";
	std::cout << 7 << " " <<
			  (LongInt("1", 10) == (LongInt("1", 10) - LongInt("0", 10)))
			  << "\n";
	std::cout << 8 << " " <<
			  (LongInt("1", 10) == (LongInt("0", 10) + LongInt("1", 10)))
			  << "\n";
	std::cout << 9 << " " <<
			  (LongInt("2000", 10) == (LongInt("1000", 10) + LongInt("1000", 10)))
			  << "\n";
	std::cout << 10 << " " <<
			  (LongInt("1", 10) == (LongInt("1000000000000001", 10) - LongInt("1000000000000000", 10)))
			  << "\n";
	std::cout << 11 << " " <<
			  (LongInt("-1", 10) == (LongInt("-1000000000000001", 10) + LongInt("1000000000000000", 10)))
			  << "\n";
	std::cout << 12 << " " <<
			  (LongInt("1", 10) == (LongInt("1000000000000001", 10) + LongInt("-1000000000000000", 10)))
			  << "\n";
	std::cout << 13 << " " <<
			  (LongInt("1461501637330902918203684832697836275582222991360", 10) ==
			  (LongInt("1461501637330902918203684832716283019655932542976", 10)
			  	- LongInt("18446744073709551616", 10)))
			  << "\n";
	std::cout << 14 << " " <<
			  (LongInt("-1461501637330902918203684832697836275582222991360", 10) ==
			   (LongInt("18446744073709551616", 10)
				- LongInt("1461501637330902918203684832716283019655932542976", 10)))
			  << "\n";
	std::cout << 15 << " " <<
			  (LongInt("100000001000000010000000000000000000000000000000000000000000000000000000", 10)
			  == (LongInt("100000001000000010000000100000001000000010000000100000001000000010000000", 10) -
			  LongInt("100000001000000010000000100000001000000010000000", 10)))
			  << "\n";
	std::cout << 16 << " " <<
			  (LongInt("18446744073709551616", 10) == (LongInt("18446744073709551615", 10) - LongInt("-1", 10)))
			  << "\n";
	std::cout << 17 << " " <<
			  (LongInt("4294967296", 10) == (LongInt("4294967295", 10) + LongInt("1", 10)))
			  << "\n";
	std::cout << 18 << " " <<
	(LongInt("99", 10) == (LongInt("100", 10) - (LongInt("1", 10))))
			  << "\n";
	std::cout << 19 << " " <<
	(LongInt("100", 10) == (LongInt("99", 10) + (LongInt("1", 10))))
			  << "\n";
	// multiplicate simple
	std::cout << "multiple simple" << "\n";
	std::cout << 20 << " " <<
			  (LongInt("10100", 10) == LongInt::multiplicateSimple(
					  LongInt("100", 10),
					  LongInt("101", 10)))
			  << "\n";
	std::cout << 21 << " " <<
			  (LongInt("-10100", 10) == LongInt::multiplicateSimple(
					  LongInt("-100", 10),
					  LongInt("101", 10)))
			  << "\n";
	std::cout << 22 << " " <<
			  (LongInt("10100", 10) == LongInt::multiplicateSimple(
					  LongInt("-100", 10),
					  LongInt("-101", 10)))
			  << "\n";
	std::cout << 23 << " " <<
			  (LongInt("1", 10) == LongInt::multiplicateSimple(
					  LongInt("1", 10),
					  LongInt("1", 10)))
			  << "\n";
	std::cout << 24 << " " <<
			  (LongInt("0", 10) == LongInt::multiplicateSimple(
					  LongInt("0", 10),
					  LongInt("1", 10)))
			  << "\n";
	std::cout << 25 << " " <<
			  (LongInt("0", 10) == LongInt::multiplicateSimple(
					  LongInt("-1", 10),
					  LongInt("0", 10)))
			  << "\n";
	std::cout << 26 << " " <<
			  (LongInt("152415787745770505849729945752528577907942", 10) == LongInt::multiplicateSimple(
					  LongInt("1234567890987654345678", 10),
					  LongInt("123456789098765456789", 10)))
			  << "\n";
	std::cout << 27 << " " <<
			  (LongInt("13703703589962965703592703703589962965703592703703589962965703579", 10) ==
			  LongInt::multiplicateSimple(
					  LongInt("123456789098765456789123456789098765456789123456789098765456789", 10),
					  LongInt("111", 10)))
			  << "\n";
	std::cout << 28 << " " <<
			  (LongInt("18446744073709551616", 10) == LongInt::multiplicateSimple(
					  LongInt("4294967296", 10),
					  LongInt("4294967296", 10)))
			  << "\n";
	std::cout << 29 << " " <<
			  (LongInt("79228162514264337593543950336", 10) == LongInt::multiplicateSimple(
					  LongInt("18446744073709551616", 10),
					  LongInt("4294967296", 10)))
			  << "\n";
	std::string a30 = std::string("7922816252218715384655494734579813811052317613066374404682580802787869506712546384294450752693782") +
					  "669605610228103204398753682759486794709708033866004403386600439546378418811994465937837126982357278" +
					  "9388021046977659461321822583812570831947497649571553650692817770733049815930661605649703840953543950336";
	std::string b30 = std::string("429496729642949672964294967296429496729642949672964294967296429496729642949672964"
								  "29496729642949672964294967296429496729642949672964294967296");
	std::string c30 = std::string("1844674407370955161618446744073709551616184467440737095516161844674407370955161618446744073"
								  "709551616184467440737095516161844674407370955161618446744073709551616");
	std::cout << 30 << " " <<
			  (LongInt(a30, 10) == LongInt::multiplicateSimple(
					  LongInt(b30, 10),
					  LongInt(c30, 10)))
			  << "\n";
	// multiplicate karatsuba
	std::cout << "multiple karatsuba" << "\n";
	std::cout << 31 << " " <<
			  (LongInt("10100", 10) == LongInt::multiplicateKaratsuba(
					  LongInt("100", 10),
					  LongInt("101", 10)))
			  << "\n";
	std::cout << 32 << " " <<
			  (LongInt("-10100", 10) == LongInt::multiplicateKaratsuba(
					  LongInt("-100", 10),
					  LongInt("101", 10)))
			  << "\n";
	std::cout << 33 << " " <<
			  (LongInt("10100", 10) == LongInt::multiplicateKaratsuba(
					  LongInt("-100", 10),
					  LongInt("-101", 10)))
			  << "\n";
	std::cout << 34 << " " <<
			  (LongInt("1", 10) == LongInt::multiplicateKaratsuba(
					  LongInt("1", 10),
					  LongInt("1", 10)))
			  << "\n";
	std::cout << 35 << " " <<
			  (LongInt("0", 10) == LongInt::multiplicateKaratsuba(
					  LongInt("0", 10),
					  LongInt("1", 10)))
			  << "\n";
	std::cout << 36 << " " <<
			  (LongInt("0", 10) == LongInt::multiplicateKaratsuba(
					  LongInt("-1", 10),
					  LongInt("0", 10)))
			  << "\n";
	std::cout << 37 << " " <<
			  (LongInt("152415787745770505849729945752528577907942", 10) == LongInt::multiplicateKaratsuba(
					  LongInt("1234567890987654345678", 10),
					  LongInt("123456789098765456789", 10)))
			  << "\n";
	std::cout << 38 << " " <<
			  (LongInt("13703703589962965703592703703589962965703592703703589962965703579", 10) ==
			   LongInt::multiplicateKaratsuba(
					   LongInt("123456789098765456789123456789098765456789123456789098765456789", 10),
					   LongInt("111", 10)))
			  << "\n";
	std::cout << 39 << " " <<
			  (LongInt("18446744073709551616", 10) == LongInt::multiplicateKaratsuba(
					  LongInt("4294967296", 10),
					  LongInt("4294967296", 10)))
			  << "\n";
	std::cout << 40 << " " <<
			  (LongInt("79228162514264337593543950336", 10) == LongInt::multiplicateKaratsuba(
					  LongInt("18446744073709551616", 10),
					  LongInt("4294967296", 10)))
			  << "\n";
	std::cout << 41 << " " <<
			  (LongInt(a30, 10) == LongInt::multiplicateKaratsuba(
					  LongInt(b30, 10),
					  LongInt(c30, 10)))
			  << "\n";
	a30 = std::string("39402006196394479212279040100143613805079739270465446667948293404245721771497210611414266254884915640806627990306816");
	b30 = std::string("6277101735386680763835789423207666416102355444464034512896");
	c30 = std::string("6277101735386680763835789423207666416102355444464034512896");
	std::cout << 42 << " " <<
			  (LongInt(a30, 10) == LongInt::multiplicateKaratsuba(
					  LongInt(b30, 10),
					  LongInt(c30, 10)))
			  << "\n";
	a30 = std::string("6277101735386680763835789423207666416102355444464034512896");
	b30 = std::string("79228162514264337593543950336");
	c30 = std::string("79228162514264337593543950336");
	std::cout << 43 << " " <<
			  (LongInt(a30, 10) == LongInt::multiplicateKaratsuba(
					  LongInt(b30, 10),
					  LongInt(c30, 10)))
			  << "\n";
	a30 = std::string("7922816252218715384655494734579813811052317613066374404682580802787869506712546384294450752693782") +
					  "669605610228103204398753682759486794709708033866004403386600439546378418811994465937837126982357278" +
					  "9388021046977659461321822583812570831947497649571553650692817770733049815930661605649703840953543950336";
	b30 = std::string("429496729642949672964294967296429496729642949672964294967296429496729642949672964"
								  "29496729642949672964294967296429496729642949672964294967296");
	c30 = std::string("1844674407370955161618446744073709551616184467440737095516161844674407370955161618446744073"
								  "709551616184467440737095516161844674407370955161618446744073709551616");
	std::cout << "43.5" << " " <<
			  (LongInt(a30, 10) == LongInt::multiplicateKaratsuba(
					  LongInt(b30, 10),
					  LongInt(c30, 10)))
			  << "\n";
	// multiplicate Futje
	std::cout << "multiple Furje" << "\n";
	std::cout << 44 << " " <<
			  (LongInt("10100", 10) == LongInt::multiplicateFourier(
					  LongInt("100", 10),
					  LongInt("101", 10)))
			  << "\n";
	std::cout << 45 << " " <<
			  (LongInt("-10100", 10) == LongInt::multiplicateFourier(
					  LongInt("-100", 10),
					  LongInt("101", 10)))
			  << "\n";
	std::cout << 46 << " " <<
			  (LongInt("10100", 10) == LongInt::multiplicateFourier(
					  LongInt("-100", 10),
					  LongInt("-101", 10)))
			  << "\n";
	std::cout << 47 << " " <<
			  (LongInt("1", 10) == LongInt::multiplicateFourier(
					  LongInt("1", 10),
					  LongInt("1", 10)))
			  << "\n";
	std::cout << 48 << " " <<
			  (LongInt("0", 10) == LongInt::multiplicateFourier(
					  LongInt("0", 10),
					  LongInt("1", 10)))
			  << "\n";
	std::cout << 49 << " " <<
			  (LongInt("0", 10) == LongInt::multiplicateFourier(
					  LongInt("-1", 10),
					  LongInt("0", 10)))
			  << "\n";
	std::cout << 50 << " " <<
			  (LongInt("152415787745770505849729945752528577907942", 10) == LongInt::multiplicateFourier(
					  LongInt("1234567890987654345678", 10),
					  LongInt("123456789098765456789", 10)))
			  << "\n";
	std::cout << 51 << " " <<
			  (LongInt("13703703589962965703592703703589962965703592703703589962965703579", 10) ==
			   LongInt::multiplicateFourier(
					   LongInt("123456789098765456789123456789098765456789123456789098765456789", 10),
					   LongInt("111", 10)))
			  << "\n";
	std::cout << 52 << " " <<
			  (LongInt("18446744073709551616", 10) == LongInt::multiplicateFourier(
					  LongInt("4294967296", 10),
					  LongInt("4294967296", 10)))
			  << "\n";
	std::cout << 53 << " " <<
			  (LongInt("79228162514264337593543950336", 10) == LongInt::multiplicateFourier(
					  LongInt("18446744073709551616", 10),
					  LongInt("4294967296", 10)))
			  << "\n";
	a30 = std::string("39402006196394479212279040100143613805079739270465446667948293404245721771497210611414266254884915640806627990306816");
	b30 = std::string("6277101735386680763835789423207666416102355444464034512896");
	c30 = std::string("6277101735386680763835789423207666416102355444464034512896");
	std::cout << 54 << " " <<
			  (LongInt(a30, 10) == LongInt::multiplicateFourier(
					  LongInt(b30, 10),
					  LongInt(c30, 10)))
			  << "\n";
	a30 = std::string("6277101735386680763835789423207666416102355444464034512896");
	b30 = std::string("79228162514264337593543950336");
	c30 = std::string("79228162514264337593543950336");
	std::cout << 55 << " " <<
			  (LongInt(a30, 10) == LongInt::multiplicateFourier(
					  LongInt(b30, 10),
					  LongInt(c30, 10)))
			  << "\n";
	a30 = std::string("7922816252218715384655494734579813811052317613066374404682580802787869506712546384294450752693782") +
		  "669605610228103204398753682759486794709708033866004403386600439546378418811994465937837126982357278" +
		  "9388021046977659461321822583812570831947497649571553650692817770733049815930661605649703840953543950336";
	b30 = std::string("429496729642949672964294967296429496729642949672964294967296429496729642949672964"
					  "29496729642949672964294967296429496729642949672964294967296");
	c30 = std::string("1844674407370955161618446744073709551616184467440737095516161844674407370955161618446744073"
					  "709551616184467440737095516161844674407370955161618446744073709551616");
	std::cout << 56 << " " <<
			  (LongInt(a30, 10) == LongInt::multiplicateFourier(
					  LongInt(b30, 10),
					  LongInt(c30, 10)))
			  << "\n";

	std::cout << "long test" << "\n";
	LongInt longtest1;
	LongInt longtest2;
	std::ifstream longtest("longtest");
	longtest >> longtest1;
	longtest >> longtest2;

	auto start_time = std::chrono::steady_clock::now();
	LongInt res1 = LongInt::multiplicateSimple(longtest1, longtest2);
	auto end_time = std::chrono::steady_clock::now();
	auto elapsed_ns = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
	std::cout << "simple: " << elapsed_ns.count() << " ms\n";

	start_time = std::chrono::steady_clock::now();
	LongInt res2 = LongInt::multiplicateKaratsuba(longtest1, longtest2);
	end_time = std::chrono::steady_clock::now();
	elapsed_ns = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
	std::cout << "karatsuba: " << elapsed_ns.count() << " ms\n";

	 start_time = std::chrono::steady_clock::now();
	LongInt res3 = LongInt::multiplicateFourier(longtest1, longtest2);
	 end_time = std::chrono::steady_clock::now();
	 elapsed_ns = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
	std::cout << "Fourier: " << elapsed_ns.count() << " ms\n";


	std::cout << (res1 == res2) << "\n";
	std::cout << (res2 == res3) << "\n";



	// division
	std::cout << "division\n";
	std::cout << 57 << " " <<
			  (LongInt("50", 10) == (
					  LongInt("100", 10) /
					  LongInt("2", 10))
			  )
			  << "\n";
	std::cout << 58 << " " <<
			  (LongInt("12", 10) == (
					  LongInt("25", 10) /
					  LongInt("2", 10))
			  )
			  << "\n";
	std::cout << 59 << " " <<
			  (LongInt("1001001001", 10) == (
					  LongInt("123123123123", 10) /
					  LongInt("123", 10))
			  )
			  << "\n";
	std::cout << 60 << " " <<
			  (LongInt("9999", 10) == (
					  LongInt("99999", 10) /
					  LongInt("10", 10))
			  )
			  << "\n";
	std::cout << 61 << " " <<
			  (LongInt("4294967296", 10) == (
					  LongInt("18446744073709551616", 10) /
					  LongInt("4294967296", 10))
					  )
			  << "\n";
	std::cout << 62 << " " <<
			  (LongInt("100", 10) == (
					  LongInt("100", 10) /
					  LongInt("1", 10))
			  )
			  << "\n";
	std::cout << 63 << " " <<
			  (LongInt("100", 10) == (
					  LongInt("100", 10) /
					  LongInt("1", 10))
			  )
			  << "\n";
	std::cout << 64 << " " <<
			  (LongInt("1397098121365201834127992295009883740076153160116808277484", 10) == (
					  LongInt("17248124812487124981284712841724918247284728472847248274120102841092412412804124", 10) /
					  LongInt("12345678910249182419240", 10))
			  )
			  << "\n";
	std::cout << 65 << " " <<
			  (LongInt("1397098121365201834245936818319", 10) == (
					  LongInt("17248124812487124982741201028410924124128041241284712841724918247284728472847248", 10) /
					  LongInt("12345678910249182419240274120102841092412412804124", 10))
			  )
			  << "\n";
	std::cout << 66 << " " <<
			  (LongInt("0", 10) == (
					  LongInt("11111111111111111111111111111111111", 10) /
					  LongInt("11111111111111111111111111111111112", 10))
			  )
			  << "\n";
	std::cout << 67 << " " <<
			  (LongInt("1", 10) == (
					  LongInt("11111111111111111111111111111111111", 10) /
					  LongInt("11111111111111111111111111111111110", 10))
			  )
			  << "\n";
	std::cout << 68 << " " <<
			  (LongInt("1", 10) == (
					  LongInt("11111111111111111111111111111111111", 10) /
					  LongInt("11111111111111111111111111111111111", 10))
			  )
			  << "\n";
	std::cout << 69 << " " <<
			  (LongInt("0", 10) == (
					  LongInt("11111111111111111111111111111111111", 10) /
					  LongInt("-11111111111111111111111111111111112", 10))
			  )
			  << "\n";
	std::cout << 70 << " " <<
			  (LongInt("0", 10) == (
					  LongInt("-11111111111111111111111111111111111", 10) /
					  LongInt("11111111111111111111111111111111112", 10))
			  )
			  << "\n";
	std::cout << 71 << " " <<
			  (LongInt("0", 10) == (
					  LongInt("-11111111111111111111111111111111111", 10) /
					  LongInt("-11111111111111111111111111111111112", 10))
			  )
			  << "\n";
	std::cout << 72 << " " <<
			  (LongInt("-1", 10) == (
					  LongInt("-11111111111111111111111111111111111", 10) /
					  LongInt("11111111111111111111111111111111111", 10))
			  )
			  << "\n";
	a30 = std::string("7922816252218715384655494734579813811052317613066374404682580802787869506712546384294450752693782") +
		  "669605610228103204398753682759486794709708033866004403386600439546378418811994465937837126982357278" +
		  "9388021046977659461321822583812570831947497649571553650692817770733049815930661605649703840953543950336";
	b30 = std::string("429496729642949672964294967296429496729642949672964294967296429496729642949672964"
					  "29496729642949672964294967296429496729642949672964294967296");
	c30 = std::string("1844674407370955161618446744073709551616184467440737095516161844674407370955161618446744073"
					  "709551616184467440737095516161844674407370955161618446744073709551616");
	std::cout << 73 << " " <<
			  (LongInt(c30) == (
					  LongInt(a30) /
					  LongInt(b30))
			  )
			  << "\n";
	std::cout << 74 << " " <<
			  (LongInt(b30) == (
					  LongInt(a30) /
					  LongInt(c30))
			  )
			  << "\n";
	std::cout << "LongDivsionTEST\n";
	start_time = std::chrono::steady_clock::now();

	std::cout << 75 << " " <<
			  (longtest1 == (
					  res2 /
					  longtest2)
			  )
			  << "\n";

	end_time = std::chrono::steady_clock::now();
	elapsed_ns = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
	std::cout << "division long test: " << elapsed_ns.count() << " ms\n";

	// pow
	std::cout << "pow\n";
	std::cout << 77 << " " <<
			  (LongInt("170141183460469231731687303715884105728", 10) == LongInt::pow(
					  LongInt("2", 10),
					  127))
			  << "\n";
	std::cout << 78 << " " <<
			  (LongInt("115792089237316195423570985008687907853269984665640564039457584007913129639936", 10) == LongInt::pow(
					  LongInt("2", 10),
					  256))
			  << "\n";
	std::cout << 79 << " " <<
			  (LongInt("2322024177496180833848934078908522826853580952397926610269505134034535119786833728294958291762395333875710249", 10) == LongInt::pow(
					  LongInt("147", 10),
					  50))
			  << "\n";
	std::cout << 80 << " " <<
			  (LongInt("1", 10) == LongInt::pow(
					  LongInt("1", 10),
					  400000))
			  << "\n";
	std::cout << 81 << " " <<
			  (LongInt("3", 10) == LongInt::pow(
					  LongInt("3", 10),
					  1))
			  << "\n";
	std::cout << 82 << " " <<
			  (LongInt("27", 10) == LongInt::pow(
					  LongInt("3", 10),
					  3))
			  << "\n";

	std::cout << 83 << " " <<
			  (LongInt("0", 10) == LongInt::pow(
					  LongInt("2", 10),
					  127,
					  LongInt("170141183460469231731687303715884105728")))
			  << "\n";
	std::cout << 84 << " " <<
			  (LongInt("0", 10) == LongInt::pow(
					  LongInt("2", 10),
					  LongInt("170141183460469231731687303715884105728"),
					  LongInt("2")))
			  << "\n";
	std::cout << 85 << " " <<
			  (LongInt("0", 10) == LongInt::pow(
					  LongInt("2", 10),
					  LongInt("170141183460469231731687303715884105728"),
					  LongInt("1")))
			  << "\n";
	std::cout << 86 << " " <<
			  (LongInt("17884254340812360911539089422284559595199904908796604336785140580300091508890500863191154688001", 10) == LongInt::pow(
					  LongInt("2322024177496180833848934078908522826853580952397926610269505134034535119786833728294958291762395333875710249", 10),
					  LongInt("170141183460469231731687303715884105728"),
					  LongInt("100000000000000000000000000000001000000000000000000000000000000010000000000000000000000000000000")))
			  << "\n";




	// legendre
	std::cout << "legendre\n";
	std::cout << "All must be 1: ";
	/*  1 */ std::cout << legendreSymbol(LongInt("1"), LongInt("3")) << " ";
	/*  2 */ std::cout << legendreSymbol(LongInt("4"), LongInt("7")) << " ";
	/*  3 */ std::cout << legendreSymbol(LongInt("4"), LongInt("127")) << " ";
	/*  4 */ std::cout << legendreSymbol(LongInt("15"), LongInt("17")) << " ";
	/*  5 */ std::cout << legendreSymbol(LongInt("22"), LongInt("3")) << " ";
	/*  6 */ std::cout << legendreSymbol(LongInt("29"), LongInt("7")) << " ";
	/*  7 */ std::cout << legendreSymbol(LongInt("30"), LongInt("127")) << " ";
	/*  8 */ std::cout << legendreSymbol(LongInt("10001"), LongInt("1117")) << " ";
	/*  9 */ std::cout << legendreSymbol(LongInt("100011000110001"), LongInt("1117")) << " ";
	/* 10 */ std::cout << legendreSymbol(LongInt("100011000110001"), LongInt("10000019")) << " ";
	/* 11 */ std::cout << legendreSymbol(LongInt("1000110001100011"), LongInt("10000019")) << " ";
	/* 12 */ std::cout << legendreSymbol(LongInt("222"), LongInt("10000019")) << " ";
	/* 13 */ std::cout << legendreSymbol(LongInt("1000000"), LongInt("10000019")) << " ";
	/* 14 */ std::cout << legendreSymbol(LongInt("10000020"), LongInt("10000019")) << " ";
	/* 15 */ std::cout << legendreSymbol(LongInt("10000020"), LongInt("100000000003")) << " ";
	/* 16 */ std::cout << legendreSymbol(LongInt("99900020111"), LongInt("100000000003")) << " ";
	std::cout << "\nAll must be 0: ";
	/*  1 */ std::cout << legendreSymbol(LongInt("3"), LongInt("3")) << " ";
	/*  2 */ std::cout << legendreSymbol(LongInt("25"), LongInt("5")) << " ";
	/*  3 */ std::cout << legendreSymbol(LongInt("127000000000000000000000"), LongInt("127")) << " ";
	/*  4 */ std::cout << legendreSymbol(LongInt("126481724731"), LongInt("126481724731")) << " ";
	/*  5 */ std::cout << legendreSymbol(LongInt("1264817247310"), LongInt("126481724731")) << " ";
	/*  6 */ std::cout << legendreSymbol(LongInt("160098409"), LongInt("12653")) << " ";

	std::cout << "\nAll must be -1: ";
	/*  1 */ std::cout << legendreSymbol(LongInt("2"), LongInt("3")) << " ";
	/*  2 */ std::cout << legendreSymbol(LongInt("3"), LongInt("19")) << " ";
	/*  3 */ std::cout << legendreSymbol(LongInt("29"), LongInt("3")) << " ";
	/*  4 */ std::cout << legendreSymbol(LongInt("15"), LongInt("41")) << " ";
	/*  5 */ std::cout << legendreSymbol(LongInt("14"), LongInt("3")) << " ";
	/*  6 */ std::cout << legendreSymbol(LongInt("29"), LongInt("127")) << " ";
	/*  7 */ std::cout << legendreSymbol(LongInt("3"), LongInt("127")) << " ";
	/*  8 */ std::cout << legendreSymbol(LongInt("10002"), LongInt("1117")) << " ";
	/*  9 */ std::cout << legendreSymbol(LongInt("990011000110001111"), LongInt("10000019")) << " ";
	/* 10 */ std::cout << legendreSymbol(LongInt("2222"), LongInt("10000019")) << " ";
	/* 11 */ std::cout << legendreSymbol(LongInt("99999999999999"), LongInt("10000019")) << " ";
	/* 12 */ std::cout << legendreSymbol(LongInt("11111110000"), LongInt("10000019")) << " ";
	/* 13 */ std::cout << legendreSymbol(LongInt("1111111"), LongInt("100000000003")) << " ";
	/* 14 */ std::cout << legendreSymbol(LongInt("200000000005"), LongInt("100000000003")) << " ";


	std::cout << "\njacobi\n";
	std::cout << "All must be 1: ";
	/*  1 */ std::cout << jacobySymbol(LongInt("1"), LongInt("3")) << " ";
	/*  2 */ std::cout << jacobySymbol(LongInt("4"), LongInt("7")) << " ";
	/*  3 */ std::cout << jacobySymbol(LongInt("4"), LongInt("127")) << " ";
	/*  4 */ std::cout << jacobySymbol(LongInt("15"), LongInt("17")) << " ";
	/*  5 */ std::cout << jacobySymbol(LongInt("22"), LongInt("3")) << " ";
	/*  6 */ std::cout << jacobySymbol(LongInt("29"), LongInt("7")) << " ";
	/*  7 */ std::cout << jacobySymbol(LongInt("30"), LongInt("127")) << " ";
	/*  8 */ std::cout << jacobySymbol(LongInt("10001"), LongInt("1117")) << " ";
	/*  9 */ std::cout << jacobySymbol(LongInt("100011000110001"), LongInt("1117")) << " ";
	/* 10 */ std::cout << jacobySymbol(LongInt("100011000110001"), LongInt("10000019")) << " ";
	/* 11 */ std::cout << jacobySymbol(LongInt("1000110001100011"), LongInt("10000019")) << " ";
	/* 12 */ std::cout << jacobySymbol(LongInt("222"), LongInt("10000019")) << " ";
	/* 13 */ std::cout << jacobySymbol(LongInt("1000000"), LongInt("10000019")) << " ";
	/* 14 */ std::cout << jacobySymbol(LongInt("10000020"), LongInt("10000019")) << " ";
	/* 15 */ std::cout << jacobySymbol(LongInt("10000020"), LongInt("100000000003")) << " ";
	/* 16 */ std::cout << jacobySymbol(LongInt("99900020111"), LongInt("100000000003")) << " ";
	/* 17 */ std::cout << jacobySymbol(LongInt("1111111"), LongInt("1111113")) << " ";
	std::cout << "\nAll must be 0: ";
	/*  1 */ std::cout << jacobySymbol(LongInt("3"), LongInt("3")) << " ";
	/*  2 */ std::cout << jacobySymbol(LongInt("25"), LongInt("5")) << " ";
	/*  3 */ std::cout << jacobySymbol(LongInt("127000000000000000000000"), LongInt("127")) << " ";
	/*  4 */ std::cout << jacobySymbol(LongInt("126481724731"), LongInt("126481724731")) << " ";
	/*  5 */ std::cout << jacobySymbol(LongInt("1264817247310"), LongInt("126481724731")) << " ";
	/*  6 */ std::cout << jacobySymbol(LongInt("160098409"), LongInt("12653")) << " ";

	std::cout << "\nAll must be -1: ";
	/*  1 */ std::cout << legendreSymbol(LongInt("2"), LongInt("3")) << " ";
	/*  2 */ std::cout << legendreSymbol(LongInt("3"), LongInt("19")) << " ";
	/*  3 */ std::cout << legendreSymbol(LongInt("29"), LongInt("3")) << " ";
	/*  4 */ std::cout << legendreSymbol(LongInt("15"), LongInt("41")) << " ";
	/*  5 */ std::cout << legendreSymbol(LongInt("14"), LongInt("3")) << " ";
	/*  6 */ std::cout << legendreSymbol(LongInt("29"), LongInt("127")) << " ";
	/*  7 */ std::cout << legendreSymbol(LongInt("3"), LongInt("127")) << " ";
	/*  8 */ std::cout << legendreSymbol(LongInt("10002"), LongInt("1117")) << " ";
	/*  9 */ std::cout << legendreSymbol(LongInt("990011000110001111"), LongInt("10000019")) << " ";
	/* 10 */ std::cout << legendreSymbol(LongInt("2222"), LongInt("10000019")) << " ";
	/* 11 */ std::cout << legendreSymbol(LongInt("99999999999999"), LongInt("10000019")) << " ";
	/* 12 */ std::cout << legendreSymbol(LongInt("11111110000"), LongInt("10000019")) << " ";
	/* 13 */ std::cout << legendreSymbol(LongInt("1111111"), LongInt("100000000003")) << " ";
	/* 14 */ std::cout << legendreSymbol(LongInt("200000000005"), LongInt("100000000003")) << " ";
	/* 15 */ std::cout << jacobySymbol(LongInt("1111111"), LongInt("1111115")) << " ";
	std::cout << "\n";


	// is prime tests
	std::cout << "prime tests\n";
	std::cout << "Fermat\n";
	for (LongInt i=3; i < 100; i+= 2)
	{
		std::cout << i << " " << (isPrimeFermatTest(i) ? "is maybe prime" : "is not prime") << "\n";
	}
	std::cout << LongInt("200560490131") << " " << (isPrimeFermatTest(LongInt("200560490131")) ? "is maybe prime" : "is not prime") << "\n";

	std::cout << "Solovey-Strassen\n";
	for (LongInt i=3; i < 100; i+= 2)
	{
		std::cout << i << " " << (isPrimeSolovayStrassenTest(i) ? "is maybe prime" : "is not prime") << "\n";
	}
	std::cout << LongInt("200560490131") << " " << (isPrimeSolovayStrassenTest(LongInt("200560490131")) ? "is maybe prime" : "is not prime") << "\n";

	std::cout << "Miller-Rabin\n";
	for (LongInt i=3; i < 100; i+= 2)
	{
		std::cout << i << " " << (isPrimeMillerRabinTest(i) ? "is maybe prime" : "is not prime") << "\n";
	}
	std::cout << LongInt("200560490131") << " " << (isPrimeMillerRabinTest(LongInt("200560490131")) ? "is maybe prime" : "is not prime") << "\n";



	// RSA
	RSAGenerator	gen;
	gen.changeFirstBitCount(128).changeSecondBitCount(128);
	gen.generateNewKeys();
	auto public_key = gen.getPublicKey();
	auto private_key = gen.getPrivateKey();
	RSAEncoder	encoder(public_key.first, public_key.second);
	RSADecoder	decoder(private_key.first, private_key.second);

	LongInt message("42");
	std::cout << "message is number " << message << "\n";
	LongInt encoded_message(encoder.encode(message));
	std::cout << "encoded message: " << encoded_message << "\n";
	LongInt decoded_message(decoder.decode(encoded_message));
	std::cout << "decoded message: " << decoded_message << "\n";
}

int main()
{
	do_test();
	return 0;
}
