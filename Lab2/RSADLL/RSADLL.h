#ifndef _RSADLL_H_
#define _RSADLL_H_

#ifdef _USRDLL
#define PREF __declspec(dllexport)
#else
#define PREF __declspec(dllimport);
#endif
PREF unsigned long long __stdcall generateKeys(unsigned long long& e, unsigned long long& d);

PREF bool __stdcall crypt(unsigned long long openMsg, unsigned long long e, unsigned long long n, 
	unsigned long long* cryptMsg);

PREF bool __stdcall decrypt(unsigned long long cryptMsg, unsigned long long d,
	unsigned long long n, unsigned long long* openMsg);
#endif


