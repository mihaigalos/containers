#pragma once

#include "utilities.h"

namespace containers
{

template <typename T1, typename T2>
struct tuple
{
    T1 t1;
    T2 t2;

    tuple():t1{}, t2{} {}

    template <typename Tr1, typename Tr2>
    tuple(Tr1 &&first, Tr2 &&second) : t1(forward<Tr1>(first)), t2(forward<Tr2>(second)) {}

    template <typename Tr1, typename Tr2>
    tuple<T1, T2> &operator=(const tuple<Tr1, Tr2> &other)
    {
        t1 = other.t1;
        t2 = other.t2;
        return *this;
    }
};

template <typename T1, typename T2>
tuple<T1 &, T2 &> tie(T1 &first, T2 &second)
{
    return tuple<T1 &, T2 &>(first, second);
}

} // namespace containers

