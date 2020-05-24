#pragma once

#include <stdint.h>

#include "static_map.h"
#include "size_wrapper.h"

namespace containers
{

template <typename TValue, typename TSize = uint8_t, TSize MaxSize = 15>
class __static_vector : public static_map<TSize, TValue, MaxSize>
{
public:
    void push_back(TValue &data) { (*this)[this->size_] = data; }
    void push_back(TValue &&data) { (*this)[this->size_] = data; }
    TValue &pop_back() { return (*this)[--this->size_]; }
};

template <typename TValue, unsigned MaxSize = 15>
using static_vector = __static_vector<TValue, Size_t_impl<MaxSize>, MaxSize>;

} // namespace containers
