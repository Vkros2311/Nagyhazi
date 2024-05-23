#pragma once
#include "encryption.h"
#include "string"

class Caesar : public Encryptor
{
    int shift;
    std::string forCoding(const char*, const int)const;
    public:
    Caesar(int a) : shift(a)
    {}
    std::string Encoder(const char*) const override;
    std::string Decoder(const char*) const override;
};