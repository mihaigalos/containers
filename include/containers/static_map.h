#pragma once

#include <stdint.h>
#include <stdlib.h>

namespace containers
{

template <typename T, typename TSize, TSize MaxSize>
class static_map
{
public:
    TSize size() const { return size_; }
    void clear()
    {
        size_ = {};
    }

    T &operator[](TSize index)
    {
        TSize i{};
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
        TSize index_in_keys = keys_[i];
        return values_[index_in_keys];
    }

private:
    TSize keys_[MaxSize];
    T values_[MaxSize];
    TSize size_{};
};

} // namespace containers