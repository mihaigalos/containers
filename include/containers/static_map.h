#pragma once

#include <stdint.h>

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
        bool found{false};
        TKey i = get_key_reference(index, found);

        if (!found && size_ < MaxSize)
        {
            keys_[size_++] = index;
        }
        TKey index_in_keys = keys_[i];
        return values_[index_in_keys];
    }

    bool ContainsKey(TKey index)
    {
        bool found{false};
        get_key_reference(index, found);
        return found;
    }

protected:
    TKey keys_[MaxSize];
    TValue values_[MaxSize];
    TKey size_{};

private:
    TKey get_key_reference(TKey index, bool &found)
    {
        TKey i{};
        for (; i < size_ && !found; ++i)
        {
            if (keys_[i] == index)
            {
                found = true;
                break;
            }
        }
        return i;
    }
};

} // namespace containers