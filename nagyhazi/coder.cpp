#include "coder.h"

void Coder::setOs(std::ostream& out)
{
   os = &out;
}

role Coder::getRole() const
{
    return r;
}

std::ostream* Coder::getOs() const
{
    return os;
}

const Encryptor* Coder::getEncryptor() const
{
    return E;
}

const Coder& operator<<(std::ostream& out, Coder& c)
{
    c.setOs(out);
    return c;
}

std::ostream& operator<<(const Coder& c, const char* str)
{
    if(c.getOs() == nullptr) throw "output stream is not set";
    std::ostream& out = *c.getOs();
    if(c.getRole() == encoder)
    out << (c.getEncryptor()->Encoder(str));
    else
    out << (c.getEncryptor()->Decoder(str));
    return out;
}