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
        return reinterpret_cast<const char *>(&(*this)[0]);
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
        TSize i{};
        for (; i < MaxSize && in[i] != 0; ++i)
        {
            std::cout << static_cast<int>(in[i]) << std::endl;
            this->push_back(in[i]);
        }

        if (i < MaxSize && in[i] == '\0')
        {
            this->push_back('\0');
        }
    }
};

} // namespace containers