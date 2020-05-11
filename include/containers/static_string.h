#pragma once

#include <stdint.h>
#include <stdlib.h>
#include <iostream>

#include "static_vector.h"

namespace containers
{

template <typename TSize = uint8_t, TSize MaxSize = 10>
class static_string : public static_vector<TSize, unsigned char, MaxSize>
{
public:
    static_string() = default;
    static_string(const char *in)
    {
        copyData(in);
    }

    static_string(const static_string &other)
    {
        copyData(other.c_str());
    }

    static_string(static_string &&other)
    {
        copyData(other.c_str());
    }

    static_string &operator=(const static_string &other)
    {
        copyData(other.c_str());
        return *this;
    }

    static_string &operator=(static_string &&other)
    {
        copyData(other.c_str());
        return *this;
    }

    const char *c_str()
    {
        return reinterpret_cast<char *>((*this)[0]);
    }

    bool operator==(const static_string &rhs) const
    {
        bool result{true};

        if (this->size_ == rhs.size_)
        {
            for (TSize i = 0; i < rhs.size_; ++i)
            {
                if ((*this)[i] != rhs[i])
                {
                    result = false;
                    break;
                }
            }
        }
        else
        {
            result = false;
        }

        return result;
    }

    bool operator!=(const static_string &rhs) const
    {
        return !operator==(rhs);
    }

private:
    void copyData(const char *in)
    {
        for (TSize i = 0; i < MaxSize && in[i] != 0; ++i)
        {
            this->push_back(*in);
        }
    }
};

} // namespace containers
