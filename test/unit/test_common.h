#pragma once

#include <cstdint>

struct DemoStructure
{
    uint16_t i{0xFFFF};
    uint16_t j{0xFFFF};
    bool operator==(const DemoStructure &rhs) const
    {
        return i == rhs.i && j == rhs.j;
    }
};