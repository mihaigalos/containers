#include "../include/containers/static_map.h"

#include <avr/io.h>

struct DemoStructure
{
    uint8_t i;
    uint8_t j;
};

containers::static_map<uint16_t, DemoStructure, 10> sut_;

int main()
{
    sut_[0] = DemoStructure{1, 2};
    auto actual = sut_[0];

    if (actual.i & 0x55)
    {
        PORTB |= (1 << 5);
    }
}
