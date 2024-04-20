#include "bytes.h"
#include "otp.h"
#include "TOTP.h"

#if defined(_WIN32) || defined(WIN32)
#include <windows.h>
#endif

#include <iostream>
#include <string>
#include <random>
using namespace CppTotp;

std::string TOTP::normalizedBase32String(const std::string& unnorm)
{
	std::string ret;

	for (char c : unnorm)
	{
		if (c == ' ' || c == '\n' || c == '-')
		{
			// skip separators
		}
		else if (std::islower(c))
		{
			// make uppercase
			char u = std::toupper(c);
			ret.push_back(u);
		}
		else
		{
			ret.push_back(c);
		}
	}

	return ret;
}

uint32_t TOTP::getOTP(std::string key) {

	std::string normalizedKey = normalizedBase32String(key);
	Bytes::ByteString qui = Bytes::fromUnpaddedBase32(normalizedKey);

	uint32_t p = totp(qui, time(NULL), 0, 30, 6);
	return p;
}

std::string TOTP::generateSecret() {
	const std::string charset = "ABCDEFGHIJKLMNOPQRSTUVWXYZ234567";

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, charset.length() - 1);

	std::string randomString;
	for (int i = 0; i < 16; ++i) {
		randomString += charset[dis(gen)];
	}
	return randomString;
}
