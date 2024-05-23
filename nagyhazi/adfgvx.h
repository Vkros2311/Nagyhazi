#pragma once
#include "encryption.h"

class Adfgvx : public Encryptor
{
    std::string matrix;
    std::string keyword;
    int keylen; //keyword hossza
        template <class T>
    void swap(T& a, T& b) const;//cserélő template
    int* abcOrder() const;//keylen hosszú int tömböt hoz létre, keyword betűrendje szerint rendezi a számokat
    int* abcReorder() const;//rendezi abcOrder() sorrendjét, hogy visszaálljon az eredeti sorrend
    bool controlMatrix(std::string&) const; //a konstruktorban ellenőrzi a mátrixot
    int scoreAlpha(std::string&) const; //megadja a bemenő sztring betűinek számát
    std::string assignCode(const char*) const; //a mátrix alapján helyettesíti az egyes betűket
    std::string& sortbyOrder(std::string&, bool) const;//keyword betűrendje szerint keveri a betűket
    std::string resetCode(std::string& str) const;//a sztringet bejárva origin()-nel dekódolja a visszarendezett sztringet
    char origin(const char*) const;
    char lineChar(int) const;//encodenál egy karaktert helyettesít a mátrix sorával
    char coloumnChar(int) const;//encodénál oszlop szerint helyettesít
    public:
    Adfgvx(const char*, const char*);
    std::string Encoder(const char*) const override;
    std::string Decoder(const char*) const override;
};

template <class T>
void Adfgvx::swap(T& a, T& b) const
{
    T temp = a;
    a = b;
    b = temp;
}