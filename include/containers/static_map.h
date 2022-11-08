#pragma once

#include <stdint.h>

namespace containers
{


template <typename TKey>
struct TKeyRefResult {
    TKey keypos_{};
    bool found_{false};
};

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
    TKeyRefResult<TKey> get_key_reference(TKey index)
    {
        TKeyRefResult<TKey> result{};
        for (; result.keypos_ < size_; ++result.keypos_)
        {
            if (keys_[result.keypos_] == index)
            {
                result.found_ = true;
                break;
            }
        }
        return result;
    }
};

} // namespace containers
