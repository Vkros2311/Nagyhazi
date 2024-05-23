#include "vigenere.h"
#include <cstring>

std::string Vigenere::Encoder(const char* in) const
{
    std::string out;
    
    for(size_t i = 0, k = 0; i < strlen(in); i++)
    {
        if(isalpha(in[i]))
        {
            Caesar C(toupper(code[k % strlen(code)]) - 'A'); //Caesar segítségével külön-külön valósítom meg a betűk eltolását
            std::string letter(1, in[i]); //C.Encoder const char*-ot vár
            out += C.Encoder(letter.data());
            k++; //mutatja, hol vagyunk a kódban
        }

        else out += in[i]; //ha nem betű, nem változtat
    }

    return out;
}


std::string Vigenere::Decoder(const char* in) const
{
    std::string out = "";
    
    for(size_t i = 0, k = 0; i < strlen(in); i++)
    {
        if(isalpha(in[i]))
        {
            Caesar C(toupper(code[k % strlen(code)]) - 'A');
            std::string letter(1, in[i]);
            out += C.Decoder(letter.data());
            k++;
        }

        else out += in[i]; //ha nem betű, nem változtat
    }

    return out;
}