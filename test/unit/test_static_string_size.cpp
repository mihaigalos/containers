#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <type_traits>

#include "containers/static_string.h"

#include "test_common.h"

class Fixture : public ::testing::Test
{
};

TEST_F(Fixture, ValueTypeOfSizeUINT16Works_WhenTypical)
{
    constexpr uint16_t uint16_value{300};
    static_assert(std::is_same<containers::static_string<uint16_value>, containers::__static_string<uint16_t, uint16_value>>::value, "");
}

TEST_F(Fixture, ValueTypeOfSizeUINT8Works_WhenTypical)
{
    constexpr uint8_t uint8_value{255};
    static_assert(std::is_same<containers::static_string<uint8_value>, containers::__static_string<uint8_t, uint8_value>>::value, "");
}
