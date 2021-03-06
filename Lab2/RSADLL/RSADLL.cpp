#include "pch.h"
#include "RSADLL.h"
#include <random>
#include <string>
#include <bitset>
#include <iostream>

typedef unsigned long long ull;
typedef long double ld;

using namespace std;

ull getPrime() {
	std::random_device rd;
	std::default_random_engine generator(rd());
	std::uniform_int_distribution<ull> distribution(3, 0xFFFFFFF);

	ull number = distribution(generator);
	if (number % 2 == 0) number++;
	for (ull i = 3; i <= (ull)sqrt(number); i += 2)
		if (number % i == 0) {
			number += 2;
			i = 1;
		}
	return number;
}

ull gcd(ull x, ull y) {
	while (y != 0) {
		ull r = x % y;
		x = y;
		y = r;
	}
	return x;
}

string convertToBinary(ull num) {
	string r;
	while (num != 0) 
	{ 
		r = (num % 2 == 0 ? "0" : "1") + r; 
		num /= 2; 
	}
	return r;
}


ull mul_mod(ull a, ull b, ull m) {
	if (m == 0) return a * b;

	ull r = ull();

	while (a > 0) {
		if (a & 1)
			if ((r += b) > m) r %= m;
		a >>= 1;
		if ((b <<= 1) > m) b %= m;
	}
	return r;
}

ull binaryPow(ull data, ull n, ull mod) {
	ull r = 1;

	while (n) {
		if (n & 1)
			r = mul_mod(r, data, mod);
		data = mul_mod(data, data, mod);
		n >>= 1;
	}
	return r;
}

ull phi(ull n) {
	ull result = n;
	for (ull i = 2; i <= (ull)sqrt(n); ++i)
		if (n % i == 0) {
			while (n % i == 0)
				n /= i;
			result -= result / i;
		}
	if (n > 1)
		result -= result / n;
	return result;
}

ull __stdcall generateKeys(ull& e, ull& d) {
	ull p = getPrime();
	ull q = getPrime();
	while (p == q)
	{
		p = getPrime();
	}
	ull n = p * q;
	ull fi = (p - 1) * (q - 1);

	e = 3;
	while (gcd(e, fi) != 1) {
		e += 2;
	}

	ull  k = 1;

	ull fi_phi = phi(fi);
	d = binaryPow(e, fi_phi - 1, fi);

	return n;
}

bool __stdcall crypt(ull openMsg, ull e, 
	ull n, ull* cryptMsg) {
	if (openMsg > n) return false;
	*cryptMsg = binaryPow(openMsg, e, n);
	return true;
}

bool __stdcall decrypt(ull cryptMsg, ull d,
	ull n, ull* openMsg) {
	if (cryptMsg > n) return false;
	*openMsg = binaryPow(cryptMsg, d, n);
	return true;
}
