#pragma once
#include "bytes.h"


class TOTP
{
public:
	static std::string generateSecret();
	static uint32_t getOTP(std::string key);
private:
	static std::string normalizedBase32String(const std::string& unnorm);
};