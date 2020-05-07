#pragma once

#include <cstdint>

namespace containers
{

template <typename T, typename TSize>
class map
{
public:
    map(TSize size) : size_{size}
    {
        keys_ = new TSize[size];
        values_ = new T[size];
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
        for (; i < size_; ++i)
        {
            if (keys_[i] == index)
            {
                break;
            }
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