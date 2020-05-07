#pragma once

#include <cstdint>
#include <iostream>
namespace containers
{

template <typename T, typename TSize>
class map
{
public:
    map(TSize allocated_size)
    {
        keys_ = new TSize[allocated_size];
        values_ = new T[allocated_size];
    }
    virtual ~map()
    {
        clear();
        delete[] keys_;
        delete[] values_;
    }

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
    TSize *keys_; // these members are intentionally raw pointers instead of smart ones, for embdeded architectures with no STL.
    T *values_;
    TSize size_{};
};

} // namespace containers