#pragma once
#include "caesar.h"
#include <cstring>

class Vigenere : public Encryptor
{
    const char* code;
    public:
    Vigenere(const char* code) : code(code)
    {
        for(size_t i = 0; i < strlen(code); i++)
        {if(!isalpha(code[i])) throw "Invalid input in constructor";}
    }
    std::string Encoder(const char*) const override;
    std::string Decoder(const char*) const override;
};