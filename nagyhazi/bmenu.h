#pragma once
#include <iostream>
#include <limits>
#include "coder.h"
typedef enum method{CAESAR, VIGENERE, ADFGVX, ENIGMA} method;
class Mmenu
{
    int input;
    public:
    void printMenu() const;
    method getInput();
    role getMode();
    void printMode() const;
};

template<class T>
    T getIn()
    {
        T a;
        while(!(std::cin >> a))
        {
            std::cin.clear();
            //system("cls");
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Try again:" << std::endl;
        }
        return a;
    };