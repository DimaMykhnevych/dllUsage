#include <iostream>
#include "../RSADLL/RSADLL.h"

typedef unsigned long long ull;

using namespace std;

int main()
{
	ull d0;
	ull e0;
	ull n0 = generateKeys(e0, d0);
	ull d1;
	ull e1;
	ull n1 = generateKeys(e1, d1);
	ull t[] = { 242140520111, 125210215325, 23404342124, 298401225582, 129, 12415322214 };
	int t_size = sizeof(t) / sizeof(t[0]);
	cout << "E0: " << e0 << ", " << "D0: " << d0 << ", " << "N0: " << n0 << '\n';
	cout << "E1: " << e1 << ", " << "D1: " << d1 << ", " << "N1: " << n1 << '\n';
	cout << "\n\n";
	for (int i = 0; i < t_size; i++) {
		cout << "Original message: " << t[i] << '\n';
		ull elt;
		crypt(t[i], e1, n1, &elt);
		cout << "Crypted message with e1 and n1: " << elt << '\n';
		ull dlelt;
		decrypt(elt, d1, n1, &dlelt);
		cout << "Decrypted message with d1 and n1: " << dlelt << '\n';
		if (dlelt == t[i]) {
			cout << "Decrypted message (" << dlelt << ") equals original (" << t[i] << ")\n";
		}
		else {
			cout << "ERROR\n";
		}
		ull e0dlelt;
		crypt(dlelt, e0, n0, &e0dlelt);
		cout << "Crypted message with e0 and n0: " << e0dlelt << '\n';
		ull d0e0d1e1t;
		decrypt(e0dlelt, d0, n0, &d0e0d1e1t);
		cout << "Decrypted message with d0 and n0: " << d0e0d1e1t << '\n';
		if (d0e0d1e1t = t[i]) {
			cout << "Decrypted message (" << d0e0d1e1t << ") equals original (" << t[i] << ")\n";
		}
		else {
			cout << "ERROR\n";
		}
		cout << "\n\n";
	}
	return 0;
}
