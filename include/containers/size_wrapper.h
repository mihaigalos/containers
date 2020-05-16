#pragma once

#include <stdint.h>

template <bool B, typename T, typename>
struct conditional
{
    using type = T;
};

template <typename T, typename F>
struct conditional<false, T, F>
{
    using type = F;
};

template <unsigned value>
using Size_t_impl = typename conditional<(value > 255), uint16_t, uint8_t>::type;
