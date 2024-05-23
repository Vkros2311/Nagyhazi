#include "adfgvx.h"
#include <list>
#include <vector>
#include <string.h>
#include <iostream>

Adfgvx::Adfgvx(const char* str, const char* code)
{
    keyword = code;
    keylen = keyword.length();
    for(size_t i = 0; i < strlen(code); i++) {if(!isalpha(code[i])) throw "Invalid keyword in constructor";}
    for(int i = 0; i < int(keyword.length()); i++)//nagybetűssé alakítva tárolom
    keyword[i] = toupper(keyword[i]); //nagybetűssé alakítom a kódot
    matrix = str;
    if(matrix.length() != 36) throw "Invalid matrix in constructor";
    matrix = str;
    for(size_t i = 0; i < strlen(str); i++)
    matrix[i] = toupper(matrix[i]);
    if(!controlMatrix(matrix)) throw "Invalid matrix in constructor";
}

bool Adfgvx::controlMatrix(std::string& str) const
{
    bool marker = false;
    std::string alphabet = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for(int i = 0; i < 36; i++)
    {
    for(int j = 0; j < 36; j++)
    {
        if(str[j] == alphabet[0])// alphabet tömbből lépésenként törölve ellenőrizzük, hogy teljes-e a mátrix
        {
            alphabet.erase(alphabet.begin());
            marker = true;
            break;
        }
    }
    if(marker == false) return false;
    marker = false;
    }
    return true;
}

char Adfgvx::coloumnChar(int a) const
{
    a %= 6;
    std::string adfgvx = "ADFGVX";
    return adfgvx[a];
}


char Adfgvx::lineChar(int a) const
{
    a = (a - (a % 6))/6;
    std::string adfgvx = "ADFGVX";
    return adfgvx[a];
}

char Adfgvx::origin(const char* chars) const
{
    std::string adfgvx = "ADFGVX";
    int place[2];
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            if(toupper(chars[i]) == adfgvx[j]) place[i] = j;//megkeresi a betű sor- és oszlopszámát, place tömbbe teszi őket
        }
    }
    if(islower(chars[0])) return tolower(matrix[place[0]*6 + place[1]]); //a kis- és nagybetűket is figyelembeveszi
    else return matrix[place[0]*6 + place[1]];
}





std::string Adfgvx::assignCode(const char* str) const
{
    std::string newstring;
    for(int i = 0; i < int(strlen(str)); i++)//inputot bejárja
    {

        for(int j = 0; j < 36; j++)//megkeresi a mátrixban az indexet, majd hozzárendel linecharral és coloumncharral
        {
            if(!isalnum(str[i])) {newstring += str[i]; break;}//nem alfanumerikus-> nem változtat
            if(toupper(str[i]) == matrix[j])
            {
                if(islower(str[i]))//kis- nagybetűket külön kezeli
            {
                newstring += tolower(lineChar(j));
                newstring += tolower(coloumnChar(j));
            }
            else
            {
                newstring += lineChar(j);
                newstring += coloumnChar(j);
            }        
            }
        }
    }
    return newstring;
}

int* Adfgvx::abcOrder() const
{
    int* order = new int[keylen]; //a keyword betűrendjét fogja mutatni
    std::string orderdkey = keyword;
    for(int i = 0; i < keylen; i++)
    order[i] = i; //növekvő számokkal töltöm fel a listát, amit a betűrend szerint cserélgetek majd
    for(int i = 1; i < keylen; i++)
    {
        for(int j = i; j > 0 && orderdkey[j - 1] > orderdkey[j]; j--) //betűrendbe rendezem a sorrend listáját
        {
            swap<int>(order[j-1], order[j]);
            swap<char>(orderdkey[j-1], orderdkey[j]);
        }
    }
    return order;
}

int* Adfgvx::abcReorder() const
{
    int* order = abcOrder();
    int* neworder = new int[keylen];
    for(int i = 0; i < keylen; i++)
    {
        for(int j = 0; j < keylen; j++) //megkeressük, hogy hol van az i. indexű elem, a helyét írjuk neworderbe
        {
            if(order[j] == i)
            neworder[i] = j;
        }
    }
    delete[] order;
    return neworder;
}

int Adfgvx::scoreAlpha(std::string& str) const
{
    int slen = 0;
    for(int i = 0; i < int(str.length()); i++) //a betűket összeszámoljuk
    {
        if(isalpha(str[i])) slen++;
    }
    return slen;
}

std::string& Adfgvx::sortbyOrder(std::string& str, bool encoder) const
{
    int* order;
    if(encoder) order = abcOrder();
    else order = abcReorder();
    
    std::string newstr = str;
    int slen = scoreAlpha(str);
    slen = slen - (slen % keylen); //az utolsó, keywordnél rövidebb szakaszt nem keverjük
    int* indexes = new int[keylen];
    for(int i = 0, k = 0; i < int(str.length()); i++)
    {
    if(isalpha(newstr[i]) && k < slen)
    {
        indexes[k % keylen] = i; //ha betű, és még keverjük, az indexét feljegyezzük
        k++;
        if (k % keylen == 0) //ha megtelik a tömb, keverve beszúrjuk az elemeket
        {
            for(int j = 0; j < keylen; j++)
            {
                str[indexes[j]] = newstr[indexes[order[j]]]; //azért jó strbe visszaírni, mert így a betűn kívülieket nem kell külön másolni
            }

        }
    }
    }
    delete[] order;
    delete[] indexes;
    return str;
}


std::string Adfgvx::Encoder(const char* str) const
{
    std::string code_str = assignCode(str);
    sortbyOrder(code_str, true);
    return code_str;
}

std::string Adfgvx::resetCode(std::string& str) const
{
    if(scoreAlpha(str) % 2 != 0) throw "The string you want to decode is invalid";
    char chars[2];
    std::string newstring;
    for(int i = 0, k = 0; i < int(str.length()); i++)
    {
        if(!isalpha(str[i])) newstring += str[i];
        if((k%2 == 1 && !isalpha(str[i]))) throw "The string you want to decode is invalid";
        if(isalpha(str[i]))
        {
            chars[k%2] = str[i];
            k++;
            if(k%2 == 0) newstring +=  origin(chars);
        }
    }
    return newstring;
}

std::string Adfgvx::Decoder(const char* str) const
{
    std::string coded_str = str;
    std::string Adfgvx = "ADFGVX";
    bool stat;
    for(int i = 0; i < int(coded_str.length()); i++)
    {
        if(isalnum(coded_str[i]))
        {;
            stat = false;
            for(int j = 0; j < 6; j++)
            {
                if(toupper(str[i]) == Adfgvx[j]) stat = true;
            }
            if(!stat) throw "Invalid input";
        }
    }
    sortbyOrder(coded_str, false);
    coded_str = resetCode(coded_str);
    return coded_str;
}