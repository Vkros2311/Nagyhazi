#pragma once
#include <string>

class Coder;

typedef enum role{encoder, decoder} role;

class Encryptor
{
public:
    virtual std::string Encoder(const char*) const = 0;
    virtual std::string Decoder(const char*) const = 0;
    Coder getEncoder() const;
    Coder getDecoder() const;
};

