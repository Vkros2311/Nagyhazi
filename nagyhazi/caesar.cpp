#include "caesar.h"
#include <cstring>

std::string Caesar::forCoding(const char* in, const int code) const
{
    if(in == nullptr) throw "input char* is nullpointer";
    std::string out = "";
    for(size_t i = 0; i < strlen(in); i++)
    {
        if(isupper(in[i])) //nagybetűkre
        {
            int s = in[i] + code - 'A';
            while(s < 0) s += 26;
            out += char(s % 26 + 'A');
        }

        else if(islower(in[i])) //kisbetűkre
        {
            int s = in[i] + code - 'a';
            while(s < 0) s += 26;
            out += char(s % 26 + 'a');
        }

        else out += in[i]; //ha nem betű, nem változtat
    }

    return out;
}


std::string Caesar::Encoder(const char* in) const
{
    std::string out = forCoding(in, shift);
    return out;
}

std::string Caesar::Decoder(const char* in) const
{
    std::string out = forCoding(in, -shift);
    return out;
}