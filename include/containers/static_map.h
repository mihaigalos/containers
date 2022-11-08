#pragma once

#include <stdint.h>

#include "tuple.h"

namespace containers
{

template <typename TKey, typename TValue, TKey MaxSize>
class static_map
{
public:
    auto size() const { return size_; }
    void clear() { size_ = {}; }

    TValue &operator[](TKey index)
    {
        auto [keypos, found]  = get_key_reference(index);

        if (!found && size_ < MaxSize)
        {
            keys_[size_++] = index;
        }
        TKey index_in_keys = keys_[keypos];
        return values_[index_in_keys];
    }

    bool ContainsKey(TKey index)
    {
        auto [_, found] = get_key_reference(index);
        return found;
    }

protected:
    TKey keys_[MaxSize];
    TValue values_[MaxSize];
    TKey size_{};

private:
    containers::tuple<TKey, bool> get_key_reference(TKey index)
    {
        containers::tuple<TKey, bool> result{};
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
