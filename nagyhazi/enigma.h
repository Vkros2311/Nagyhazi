#pragma once
#include "encryption.h"

class Enigma : public Encryptor
{
    int sh1;
    int sh2;
    int sh3;
    public:
    Enigma(int sh1, int sh2, int sh3): sh1(sh1), sh2(sh2), sh3(sh3) {} //a kezdeti eltolásokat kell beállítani
    std::string Encoder(const char*) const override;
    std::string Decoder(const char*) const override;
};