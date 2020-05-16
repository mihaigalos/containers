#pragma once

#include <stdint.h>

#include "static_map.h"

namespace containers
{

template <typename TValue, typename TSize = uint8_t, TSize MaxSize = 10>
class static_vector : public static_map<TSize, TValue, MaxSize>
{
public:
    void push_back(TValue &data) { (*this)[this->size_] = data; }
    void push_back(TValue &&data) { (*this)[this->size_] = data; }
    TValue &pop_back() { return (*this)[--this->size_]; }
};
} // namespace containers
