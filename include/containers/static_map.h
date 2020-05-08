#pragma once

#include <stdint.h>
#include <stdlib.h>

namespace containers
{

template <typename TValue, typename TKey, TKey MaxSize>
class static_map
{
public:
    TKey size() const { return size_; }
    void clear()
    {
        size_ = {};
    }

    TValue &operator[](TKey index)
    {
        TKey i{};
        bool found{false};
        for (; i < size_ && !found; ++i)
        {

            if (keys_[i] == index)
            {
                found = true;
                break;
            }
        }

        if (!found)
        {
            keys_[size_++] = index;
        }
        TKey index_in_keys = keys_[i];
        return values_[index_in_keys];
    }

private:
    TKey keys_[MaxSize];
    TValue values_[MaxSize];
    TKey size_{};
};

} // namespace containers