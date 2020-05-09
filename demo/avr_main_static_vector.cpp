#include "../include/containers/static_vector.h"

#include <avr/io.h>

struct DemoStructure
{
    uint8_t i;
    uint8_t j;
};

containers::static_vector<DemoStructure> sut_;

int main()
{
    sut_.push_back(DemoStructure{1, 2});
    auto actual = sut_[0];

    if (actual.i & 0x55)
    {
        PORTB |= (1 << 5);
    }
}
