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
        TKey i = get_key_reference(index);
        bool found{i != size_};

        if (!found && size_ < MaxSize)
        {
            keys_[size_++] = index;
        }
        TKey index_in_keys = keys_[i];
        return values_[index_in_keys];
    }

    bool ContainsKey(TKey index)
    {
        auto i = get_key_reference(index);
        bool found{i != size_};
        return found;
    }

protected:
    TKey keys_[MaxSize];
    TValue values_[MaxSize];
    TKey size_{};

private:
    TKey get_key_reference(TKey index)
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
        return i;
    }
};

} // namespace containers