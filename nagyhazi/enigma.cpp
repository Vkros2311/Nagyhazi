#include "enigma.h"
#include "caesar.h"

std::string Enigma::Encoder(const char* in) const
{
    std::string str = in;
    std::string newstr;
    int a = sh1, b = sh2, c = sh3;
    for(int i = 0; i < int(str.length()); i++, a++)
    {
        std::string letter(1, str[i]);
        Caesar A(a);
        Caesar B(b);
        Caesar C(c);
        newstr += C.Encoder((B.Encoder((A.Encoder(letter.data())).data())).data());
        if(i%26 == 0) b++;
        if(i%676 == 0) c++;
    }
    return newstr;
}

std::string Enigma::Decoder(const char* in) const
{
    std::string str = in;
        std::string newstr;
    int a = -sh1, b = -sh2, c = -sh3;
    for(int i = 0; i < int(str.length()); i++, a--)
    {
        std::string letter(1, str[i]);
        Caesar A(a);
        Caesar B(b);
        Caesar C(c);
        newstr += C.Encoder((B.Encoder((A.Encoder(letter.data())).data())).data());
        if(i%26 == 0) b--;
        if(i%676 == 0) c--;
    }
    return newstr;
}