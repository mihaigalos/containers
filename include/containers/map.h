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
        keys_ = new T[size];
        values_ = new TSize[size];
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

private:
    T *keys_; // these members are intentionally raw pointers instead of smart ones, for embdeded architectures with no STL.
    TSize *values_;
    TSize size_{};
};

} // namespace containers