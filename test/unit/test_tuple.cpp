#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "containers/tuple.h"

#include "test_common.h"

class Fixture : public ::testing::Test
{
};

TEST_F(Fixture, TupleWorks_WhenTypical)
{
    int first, second;

    containers::tie(first, second) = containers::tuple<int, int>(3, 5);

    ASSERT_EQ(first, 3);
    ASSERT_EQ(second, 5);
}

