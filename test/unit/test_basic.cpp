#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "containers/map.h"

struct DemoStructure
{
    uint16_t i;
    uint16_t j;
    bool operator==(const DemoStructure &rhs)
    {
        return i == rhs.i && j == rhs.j;
    }
};

class Fixture : public ::testing::Test
{
public:
protected:
    virtual void SetUp() override
    {
        sut_.clear();
    }

    uint16_t expected_size{10};
    containers::map<DemoStructure, decltype(expected_size)> sut_{expected_size};
};

TEST_F(Fixture, ConstructWorks_WhenTypical)
{
    ASSERT_EQ(sut_.size(), 0);
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

TEST_F(Fixture, AddMultiple_WhenTypical)
{

    sut_[0] = DemoStructure{1, 2};
    sut_[1] = DemoStructure{3, 4};

    ASSERT_EQ(sut_[0].i, 1);
    ASSERT_EQ(sut_[0].j, 2);
    ASSERT_EQ(sut_[1].i, 3);
    ASSERT_EQ(sut_[1].j, 4);
}
