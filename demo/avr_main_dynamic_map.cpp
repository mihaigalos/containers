#include "../include/containers/dynamic_map.h"

#include <avr/io.h>

void operator delete(void *ptr, unsigned int foo)
{
    free(ptr);
}

struct DemoStructure
{
    uint8_t i;
    uint8_t j;
};

containers::dynamic_map<uint16_t, DemoStructure, 10> sut_;

int main()
{
    sut_[0] = DemoStructure{1, 2};
    auto actual = sut_[0];

    if (actual.i & 0x55)
    {
        PORTB |= (1 << 5);
    }
}
