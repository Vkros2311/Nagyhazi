#include "encryption.h"
#include "coder.h"

/*Parameter Encryptor::getEncoder() const
{
    Parameter p(this, encoder);
    return p;
}

Parameter Encryptor::getDecoder() const
{
    Parameter p(this, decoder);
    return p;
}*/

Coder Encryptor::getEncoder() const
{
    Coder p(this, encoder);
    return p;
}

Coder Encryptor::getDecoder() const
{
    Coder p(this, decoder);
    return p;
}