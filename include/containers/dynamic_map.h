#pragma once

#include <stdint.h>
#include <stdlib.h>
namespace containers
{

template <typename TKey, typename TValue, TKey MaxSize>
class dynamic_map
{
public:
    dynamic_map() : max_size_{MaxSize}
    {
        keys_ = static_cast<TKey *>(malloc(MaxSize));
        values_ = static_cast<TValue *>(malloc(MaxSize));
    }
    virtual ~dynamic_map()
    {
        clear();
        free(keys_);
        free(values_);
    }

    TKey size() const { return size_; }
    TKey max_size() const { return max_size_; }
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
            keys_ = static_cast<TKey *>(realloc(keys_, 2 * MaxSize));
            values_ = static_cast<TValue *>(realloc(values_, 2 * MaxSize));
            max_size_ = 2 * max_size_;
        }
    }

    TKey *keys_; // these members are intentionally raw pointers instead of smart ones, for embedded architectures with no STL.
    TValue *values_;
    TKey size_{};
    TKey max_size_{};
};

} // namespace containers