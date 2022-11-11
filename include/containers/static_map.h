#pragma once

#include <stdint.h>

#include "tuple.h"

namespace containers
{

using TFound = bool;

template <typename TKey, typename TValue, TKey MaxSize>
class static_map
{
public:
    auto size() const { return size_; }
    void clear() { size_ = {}; }

    TValue &operator[](TKey index)
    {
        auto [keypos, found]  = get_key_reference(index);

        if (!found)
        {
            if(size_ < MaxSize)
            {
                keys_[size_++] = index;
            } else {
                return out_of_bounds_value_;
            }
        }
        TKey index_in_keys = keys_[keypos];
        return values_[index_in_keys];
    }

    TFound ContainsKey(TKey index)
    {
        auto [_, found] = get_key_reference(index);
        return found;
    }

protected:
    TKey keys_[MaxSize];
    TValue values_[MaxSize];
    TValue out_of_bounds_value_{};
    TKey size_{};

private:
    tuple<TKey, TFound> get_key_reference(TKey index)
    {
        tuple<TKey, TFound> result{};
        for (; result.t1 < size_; ++result.t1)
        {
            if (keys_[result.t1] == index)
            {
                result.t2 = true;
                break;
            }
        }
        return result;
    }
};

} // namespace containers
