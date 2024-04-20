#include "pch.h"
#include "TOTPLib.h"
#include "TOTP.h"

std::string TOTPLib::generateSecret() {
    return TOTP::generateSecret();
}

uint32_t TOTPLib::getOTP(std::string key) {
    return TOTP::getOTP(key);
}