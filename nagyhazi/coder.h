#pragma once
#include "encryption.h"
#include <iostream>

class Coder
{
    const Encryptor*  E;
    role r;
    std::ostream* os;
    public:
    Coder(const Encryptor* E, role r) : E(E), r(r) {}
    void setOs(std::ostream&);
    const Encryptor* getEncryptor() const;
    role getRole() const;
    std::ostream* getOs() const;
};

const Coder& operator<<(std::ostream&, Coder&);

std::ostream& operator<<(const Coder&, const char*);