#pragma once

#include <stdint.h>

#include "static_vector.h"
#include "size_wrapper.h"

namespace containers
{

template <typename TSize = uint8_t, TSize MaxSize = 15>
class __static_string : public static_vector<TSize, unsigned char, MaxSize>
{
public:
  __static_string() = default;
  __static_string(const char *in)
  {
    this->size_ = 0;
    append(in);
  }

  __static_string(__static_string &other)
  {
    this->size_ = 0;
    append(other.c_str());
  }

  __static_string(__static_string &&other)
  {
    this->size_ = 0;
    append(other.c_str());
  }

  __static_string &operator=(__static_string &other)
  {

    if (*this == other)
    { // assignment to self
      return *this;
    }
    this->size_ = 0;
    append(other.c_str());

    return *this;
  }

  __static_string &operator=(__static_string &&other)
  {
    this->size_ = 0;
    append(other.c_str());
    return *this;
  }

  const char *c_str() { return reinterpret_cast<const char *>(&(*this)[0]); }

  bool operator==(const __static_string &rhs) const
  {
    bool result{true};

    if (this->size_ == rhs.size_)
    {
      for (TSize i = 0; i < rhs.size_; ++i)
      {
        // TODO: implement static_map::const operator[](const) const
        if ((*const_cast<__static_string *>(this))[i] !=
            (*const_cast<__static_string *>(&rhs))[i])
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

  bool operator!=(const __static_string &rhs) const { return !operator==(rhs); }

  __static_string &operator+(const char *in)
  {
    remove_end();
    append(in);
    return *this;
  }

  __static_string &operator+=(const char *in)
  {
    return operator+(in);
  }

  __static_string &operator+(const char in)
  {
    remove_end();
    this->push_back(in);
    add_end(this->size_);
    return *this;
  }

  __static_string &operator+=(const char in)
  {
    return operator+(in);
  }

private:
  void remove_end()
  {
    if (this->size_ && (*this)[this->size_ - 1] == '\0')
    {
      --this->size_;
    }
  }
  void add_end(TSize position)
  {
    if (position < MaxSize)
    {
      this->push_back('\0');
    }
  }

  void append(const char *in)
  {
    TSize i{};
    for (; i < MaxSize && in[i] != 0; ++i)
    {
      this->push_back(in[i]);
    }

    add_end(i);
  }
};

template <unsigned MaxSize = 15>
using static_string = __static_string<Size_t_impl<MaxSize>, MaxSize>;

} // namespace containers
