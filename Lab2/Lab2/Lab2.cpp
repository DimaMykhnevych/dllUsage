#include <iostream>
#include "../RSADLL/RSADLL.h"
using namespace std;




int main()
{
	unsigned long long e;
	unsigned long long d;
	unsigned long long n = generateKeys(e, d);
	unsigned long long openMsg, cryptMsg, afterDecryptMsg;
	/*crypt(123, e, n, &cryptMsg);
	decrypt(cryptMsg, d, n, &afterDecryptMsg);*/

	
	
	for (int i = 0; i < 10; i++) {
		openMsg = rand() % n;
		crypt(openMsg, e, n, &cryptMsg);
		decrypt(cryptMsg, d, n, &afterDecryptMsg);
		if (openMsg == afterDecryptMsg)
			printf("OpenMsg = %u CryptMsg = %u AfterDecryptMsg = %u - OK\n", openMsg, cryptMsg, afterDecryptMsg);
		else
			printf("OpenMsg = %u CryptMsg = %u AfterDecryptMsg = %u - Error\n", openMsg, cryptMsg, afterDecryptMsg);
	}
	return 0;
}
//#include <iostream>
//#include <math.h>
//using namespace std;
//
//
//int gcd(int a, int b)
//{
//    int t;
//    while (1)
//    {
//        t = a % b;
//        if (t == 0)
//            return b;
//        a = b;
//        b = t;
//    }
//}
//
//int main()
//{
//    //2 random prime numbers
//    double p = 1000859;
//    double q = 1000999;
//    double n = p * q; //calculate n
//    double track;
//    double phi = (p - 1) * (q - 1); //calculate phi
//
//    //public key
//    //e stands for encrypt
//    double e = 7;
//
//    //for checking that 1 < e < phi(n) and gcd(e, phi(n)) = 1; i.e., e and phi(n) are coprime.
//    while (e < phi)
//    {
//        track = gcd(e, phi);
//        if (track == 1)
//            break;
//        else
//            e++;
//    }
//
//    //private key
//    //d stands for decrypt
//    //choosing d such that it satisfies d*e = 1 mod phi
//    double d1 = 1 / e;
//    double d = fmod(d1, phi);
//    double message = 99;
//    double c = pow(message, e); //encrypt the message
//    double m = pow(c, d);
//
//    c = fmod(c, n);
//    m = fmod(m, n);
//
//    cout << "Original Message = " << message;
//    cout << "\n"
//        << "p = " << p;
//    cout << "\n"
//        << "q = " << q;
//    cout << "\n"
//        << "n = pq = " << n;
//    cout << "\n"
//        << "phi = " << phi;
//    cout << "\n"
//        << "e = " << e;
//    cout << "\n"
//        << "d = " << d;
//    cout << "\n"
//        << "Encrypted message = " << c;
//    cout << "\n"
//        << "Decrypted message = " << m;
//
//    return 0;
//}