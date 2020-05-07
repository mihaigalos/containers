#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "containers/map.h"

struct DemoStructure
{
    uint8_t i;
    uint16_t j;
};

class Fixture : public ::testing::Test
{
public:
protected:
    virtual void SetUp() override {}

    uint16_t expected_size{10};
    containers::map<DemoStructure, decltype(expected_size)> sut_{expected_size};
};

TEST_F(Fixture, ConstructWorks_WhenTypical)
{

    ASSERT_EQ(sut_.size(), expected_size);
}

TEST_F(Fixture, ClearWorks_WhenTypical)
{
    sut_.clear();

    ASSERT_EQ(sut_.size(), 0);
}

TEST_F(Fixture, AddWorks_WhenTypical)
{
    sut_[0] = DemoStructure{1, 2};
    auto actual = sut_[0];

    ASSERT_EQ(actual.i, 1);
    ASSERT_EQ(actual.j, 2);
}
