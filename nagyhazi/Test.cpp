#include <iostream>
#include "encryption.h"
#include "coder.h"
#include "caesar.h"
#include "vigenere.h"
#include "adfgvx.h"
#include "bmenu.h"
#include "enigma.h"
#include <limits>

std::string callCaesar(std::string& str, role r)
{
    std::cout << "Enter the code:" << std::endl;
    int i = getIn<int>();//paraméter(ek) beolvasása
    Caesar C(i);
    if(r == encoder) return C.Encoder(str.data());
    return C.Decoder(str.data());
}

std::string callVigenere(std::string& str, role r)
{
    std::cout << "Enter the code:" << std::endl;
    std::string code = getIn<std::string>();
    Vigenere V(code.data());
    if(r == encoder) return V.Encoder(str.data());
    return V.Decoder(str.data());
}

std::string callAdfgvx(std::string& str, role r)
{
    std::cout << "Enter the code:" << std::endl;
    std::string matrix = getIn<std::string>();
    std::string code = getIn<std::string>();
    Adfgvx A(matrix.data(), code.data());
    if(r == encoder) return A.Encoder(str.data());
    return A.Decoder(str.data());
}

std::string callEnigma(std::string str, role r)
{
    std::cout << "Enter the code:" << std::endl;
    int a = getIn<int>(); int b = getIn<int>(); int c = getIn<int>();
    Enigma E(a, b, c);
    if(r == encoder) return E.Encoder(str.data());
    return E.Decoder(str.data());
}

int main()
{
    //system("cls");
    std::string str;
    role r;
    bool menu;
    Mmenu M;
    method a;
    while(1){
    menu = true;
    std::string output;
    std::cout << "Enter the text you'd like to encrypt:" << std::endl;
    getline(std::cin, str);
    //system("cls");
    M.printMenu();
try{
    a = M.getInput(); //algoritmus választása
    //system("cls");
    M.printMode();
    r = M.getMode();//kódolás/dekódolás
    switch(a)
    {
    case CAESAR:
    output = callCaesar(str, r); break;
    case VIGENERE:
    output = callVigenere(str, r); break;
    case ADFGVX:
    output = callAdfgvx(str, r); break;
    case ENIGMA:
    output = callEnigma(str, r);
    }
    }
    catch(...) {std::cerr << "Invalid input" << std::endl; menu = false;}

    if(menu)
    {
        std::cout << "The coded text is:" << std::endl;
        std::cout << output << std::endl;
        //std::cin.ignore(10000, '\n'); //bemenetet letörlöm
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //bemenetet letörlöm
    }
    
    return 0;
}