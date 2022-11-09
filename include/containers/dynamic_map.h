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
        keys_ = static_cast<TKey *>(malloc(InitialMaxSize * sizeof(TKey)));
        values_ = static_cast<TValue *>(malloc(InitialMaxSize * sizeof(TValue)));
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
        TKey i = get_key_reference(index);
        bool found{i != size_};

        if (!found)
        {
            if (size_ == max_size_ || index == max_size_)
            {
                increase_capacity();
            }
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

private:
    void increase_capacity()
    {
        max_size_ = 2 * max_size_;

        keys_ = static_cast<TKey *>(realloc(keys_, max_size_ * sizeof(TKey)));
        values_ = static_cast<TValue *>(realloc(values_, max_size_ * sizeof(TValue)));
    }

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

    TKey *keys_; // these members are intentionally raw pointers instead of smart ones, for embedded architectures with no STL.
    TValue *values_;
    TKey size_{};
    TKey max_size_{};
};

} // namespace containers
