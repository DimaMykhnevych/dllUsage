#include "pch.h"
#include "RSADLL.h"
#include <random>
#include <string>
#include <bitset>
using namespace std;

unsigned long long getPrime() {
	std::random_device rd;
	std::default_random_engine generator(rd());
	std::uniform_int_distribution<unsigned long long> distribution(3, 0xFFFFFFFF);

	unsigned long long number = distribution(generator);
	if (number % 2 == 0) number++;
	for (unsigned long long i = 3; i * i <= number; i += 2)
		if (number % i == 0) {
			number += 2;
			i = 1;
		}
	return number;
}

unsigned long long gcd(unsigned long long x, unsigned long long y) {
	while (y != 0) {
		unsigned long long r = x % y;
		x = y;
		y = r;
	}
	return x;
}

string convertToBinary(unsigned long long num) {
	string r;
	while (num != 0) 
	{ 
		r = (num % 2 == 0 ? "0" : "1") + r; 
		num /= 2; 
	}
	return r;
}

unsigned long long binaryPow(unsigned long long data, unsigned long long key, unsigned long long n) {
	string binary = convertToBinary(key);
	unsigned long long res = data;
	for (int i = 1; i < binary.size(); i++) {
		if (binary[i] == '0') {
			res = (res * res) % n;
		}
		else if (binary[i] == '1') {
			res = (res * res) * data % n;
		}
	}
	return res;
	//int count = 0;									
	//unsigned tempKey = key;

	//while (tempKey != 1) 
	//{
	//	tempKey /= 2;
	//	count++;
	//}

	//unsigned result = data;

	//for (int i = count - 1; i >= 0; i--)   
	//{
	//	result *= result;
	//	result %= n; 
	//	if ((key >> i) & 1)  
	//	{
	//		result *= data;
	//		result %= n;
	//	}
	//}

	//return result;
}

unsigned long long __stdcall generateKeys(unsigned long long& e, unsigned long long& d) {
	unsigned long long p = getPrime();
	unsigned long long q = getPrime();
	while (p == q)
	{
		p = getPrime();
	}
	unsigned long long n = p * q;
	unsigned long long fi = (p - 1) * (q - 1);

	e = 3;
	while (gcd(e, fi) != 1) {
		e += 2;
	}


	unsigned long long  k = 1;

	while (true)
	{
		k = k + fi;

		if (k % e == 0)
		{
			d = (k / e);
			break;
		}
	}

	return n;
}

bool __stdcall crypt(unsigned long long openMsg, unsigned long long e, 
	unsigned long long n, unsigned long long* cryptMsg) {
	if (openMsg > n) return false;
	*cryptMsg = binaryPow(openMsg, e, n);
	return true;
}

bool __stdcall decrypt(unsigned long long cryptMsg, unsigned long long d,
	unsigned long long n, unsigned long long* openMsg) {
	if (cryptMsg > n) return false;
	*openMsg = binaryPow(cryptMsg, d, n);
	return true;
}