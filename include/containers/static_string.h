#pragma once

#include "static_vector.h"
#include <stdint.h>

namespace containers {

template <typename TSize = uint8_t, TSize MaxSize = 15>
class static_string : public static_vector<TSize, unsigned char, MaxSize> {
public:
  static_string() = default;
  static_string(const char *in) {
    this->size_ = 0;
    append(in);
  }

  static_string(static_string &other) {
    this->size_ = 0;
    append(other.c_str());
  }

  static_string(static_string &&other) {
    this->size_ = 0;
    append(other.c_str());
  }

  static_string &operator=(static_string &other) {

    if (*this == other) { // assignment to self
      return *this;
    }
    this->size_ = 0;
    append(other.c_str());

    return *this;
  }

  static_string &operator=(static_string &&other) {
    this->size_ = 0;
    append(other.c_str());
    return *this;
  }

  const char *c_str() { return reinterpret_cast<const char *>(&(*this)[0]); }

  bool operator==(const static_string &rhs) const {
    bool result{true};

    if (this->size_ == rhs.size_) {
      for (TSize i = 0; i < rhs.size_; ++i) {
        // TODO: implement static_map::const operator[](const) const
        if ((*const_cast<static_string *>(this))[i] !=
            (*const_cast<static_string *>(&rhs))[i]) {
          result = false;
          break;
        }
      }
    } else {
      result = false;
    }

    return result;
  }

  bool operator!=(const static_string &rhs) const { return !operator==(rhs); }

  static_string &operator+(const char *in) {
    if (this->size_ && (*this)[this->size_ - 1] == '\0') {
      --this->size_;
    }

    append(in);
    return *this;
  }

private:
  void append(const char *in) {

    TSize i{};
    for (; i < MaxSize && in[i] != 0; ++i) {
      this->push_back(in[i]);
    }

    if (i < MaxSize && in[i] == '\0') {
      this->push_back('\0');
    }
  }
};

} // namespace containers
