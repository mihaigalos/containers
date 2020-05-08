#include "../include/containers/static_map.h"

#include <avr/io.h>

struct DemoStructure
{
    uint8_t i;
    uint8_t j;
};

uint16_t expected_size{10};
containers::static_map<DemoStructure, uint16_t, 10> sut_;

int main()
{

    sut_[0] = DemoStructure{1, 2};
    auto actual = sut_[0];

    if (actual.i & 0x55)
    {
        PORTB |= (1 << 5);
    }
}
