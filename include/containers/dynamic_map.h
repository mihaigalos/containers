#pragma once

#include <stdint.h>
#include <stdlib.h>

namespace containers
{

template <typename TValue, typename TKey>
class dynamic_map
{
public:
    dynamic_map(TKey allocated_size)
    {
        keys_ = static_cast<TKey *>(malloc(allocated_size));
        values_ = static_cast<TValue *>(malloc(allocated_size));
    }
    virtual ~dynamic_map()
    {
        clear();
        free(keys_);
        free(values_);
    }

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
    TKey *keys_; // these members are intentionally raw pointers instead of smart ones, for embdeded architectures with no STL.
    TValue *values_;
    TKey size_{};
};

} // namespace containers