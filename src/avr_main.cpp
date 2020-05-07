#include "../include/containers/map.h"

#include <avr/io.h>

void operator delete(void *ptr, unsigned int foo)
{
    delete ptr;
}

void operator delete(void *ptr)
{
    delete ptr;
}

struct DemoStructure
{
    uint8_t i;
    uint8_t j;
};

uint16_t expected_size{10};
containers::map<DemoStructure, decltype(expected_size)> sut_{expected_size};

int main()
{

    sut_[0] = DemoStructure{1, 2};
    auto actual = sut_[0];

    if (actual.i & 0x55)
    {
        PORTB |= (1 << 5);
    }
}
