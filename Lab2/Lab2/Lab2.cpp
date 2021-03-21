#include <iostream>
#include "../RSADLL/RSADLL.h"

typedef unsigned long long ull;

using namespace std;

int main()
{
	ull e;
	ull d;
	ull openMsg, cryptMsg, afterDecryptMsg;

	ull error = 0, FOR_COUNT = 10;

	for (ull i = 0; i < FOR_COUNT; i++) {
		ull n = generateKeys(e, d);
		openMsg = rand() % n;

		cout << "n: " << n << " e: " << e << " d:" << d << "\n";

		crypt(openMsg, e, n, &cryptMsg);
		decrypt(cryptMsg, d, n, &afterDecryptMsg);
		if (openMsg == afterDecryptMsg)
			printf("OpenMsg = %u CryptMsg = %u AfterDecryptMsg = %u - OK\n", (int)openMsg, (int)cryptMsg, (int)afterDecryptMsg);
		else {
			printf("OpenMsg = %u CryptMsg = %u AfterDecryptMsg = %u - Error\n", (int)openMsg, (int)cryptMsg, (int)afterDecryptMsg);
			++error;
		}
	}
	cout << "Error count: " << error << "/" << FOR_COUNT << "\n";
	return 0;
}
