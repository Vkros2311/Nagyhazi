#include "bmenu.h"
#include <stdlib.h>
#include <iostream>
#include "coder.h"

class Context;
void Mmenu::printMenu() const
{
    //system("cls");
    std::cout << "Choose the encryption method" << std::endl;
    std::cout << "1. Caesar" << std::endl;
    std::cout << "2. Vigenere" << std::endl;
    std::cout << "3. ADFGVX" << std::endl;
    std::cout << "4. Enigma" << std::endl;
}

void Mmenu::printMode() const
{
    //system("cls");
    std::cout<<"Would you like to encode or decode the test?"<< std::endl;
    std::cout << "1. Encode" << std::endl;
    std::cout << "2. Decode" << std::endl;
}

method Mmenu::getInput()
{
    std::cout << "Enter the number of the method:" << std::endl;
    input = getIn<int>();
    while(input > 4 || input < 1)
    {
        std::cout << "Invalid input. Try again:" << std::endl;
        input = getIn<int>();
    }
    return method(input - 1);
}

role Mmenu::getMode()
{
    std::cout << "Enter the serial number of the mode:" << std::endl;
    input = getIn<int>();
    while(input > 2 || input < 1)
    {
        std::cout << "Invalid input. Try again:" << std::endl;
        input = getIn<int>();
    }
    if(input == 1) return encoder;
    return decoder;
}

