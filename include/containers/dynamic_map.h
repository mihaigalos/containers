#pragma once

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

namespace containers
{

template <typename TKey, typename TValue, TKey InitialMaxSize>
class dynamic_map
{
public:
    dynamic_map() : max_size_{InitialMaxSize}
    {
        keys_ = static_cast<TKey *>(malloc(InitialMaxSize));
        values_ = static_cast<TValue *>(malloc(InitialMaxSize));
    }
    virtual ~dynamic_map()
    {
        clear();
        free(keys_);
        free(values_);
    }

    auto size() const { return size_; }
    auto max_size() const { return max_size_; }
    void clear() { size_ = {}; }

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
            increase_capacity();
            keys_[size_++] = index;
        }
        TKey index_in_keys = keys_[i];
        return values_[index_in_keys];
    }

private:
    void increase_capacity()
    {
        if (size_ == max_size_)
        {
            auto old_keys = keys_;
            auto old_values = values_;
            keys_ = static_cast<TKey *>(realloc(keys_, 2 * max_size_));
            values_ = static_cast<TValue *>(realloc(values_, 2 * max_size_));

            memcpy(keys_, old_keys, max_size_);
            memcpy(values_, old_values, max_size_);

            max_size_ = 2 * max_size_;
        }
    }

    TKey *keys_; // these members are intentionally raw pointers instead of smart ones, for embedded architectures with no STL.
    TValue *values_;
    TKey size_{};
    TKey max_size_{};
};

} // namespace containers