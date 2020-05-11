#include "../include/containers/static_string.h"

#include <avr/io.h>

containers::static_string<> sut_{"FooBar"};

int main()
{

    auto actual = sut_[0];

    if (actual & 0x55)
    {
        PORTB |= sut_[3];
    }
}
