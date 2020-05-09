#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "containers/dynamic_map.h"
#include "containers/static_map.h"

struct DemoStructure
{
    uint16_t i{0xFFFF};
    uint16_t j{0xFFFF};
};

class Fixture : public ::testing::Test
{
public:
protected:
    virtual void SetUp() override
    {
        sut_.clear();
    }

    containers::dynamic_map<uint16_t, DemoStructure, 2> sut_;
};

TEST_F(Fixture, CapacityIncreased_WhenMoreAsInitial)
{

    sut_[0] = DemoStructure{1, 2};
    sut_[2] = DemoStructure{5, 6};
    sut_[1] = DemoStructure{3, 4};

    ASSERT_EQ(sut_.max_size(), 4);
}

TEST_F(Fixture, AddMultiple_WhenRandom)
{

    sut_[0] = DemoStructure{1, 2};
    sut_[2] = DemoStructure{5, 6};
    sut_[1] = DemoStructure{3, 4};

    ASSERT_EQ(sut_[0].i, 1);
    ASSERT_EQ(sut_[0].j, 2);
    ASSERT_EQ(sut_[1].i, 3);
    ASSERT_EQ(sut_[1].j, 4);
    ASSERT_EQ(sut_[2].i, 5);
    ASSERT_EQ(sut_[2].j, 6);
}

TEST_F(Fixture, CapacityIncreasedTwice_WhenMoreAsInitial)
{

    sut_[0] = DemoStructure{1, 2};
    sut_[2] = DemoStructure{5, 6};
    sut_[4] = DemoStructure{9, 10};
    sut_[1] = DemoStructure{3, 4};
    sut_[2] = DemoStructure{};
    sut_[3] = DemoStructure{7, 8};

    ASSERT_EQ(sut_.max_size(), 8);
}

TEST_F(Fixture, AddMultipleDeleteOne_WhenRandom)
{

    sut_[0] = DemoStructure{1, 2};
    sut_[2] = DemoStructure{5, 6};
    sut_[4] = DemoStructure{9, 10};
    sut_[1] = DemoStructure{3, 4};
    sut_[2] = DemoStructure{};
    sut_[3] = DemoStructure{7, 8};

    ASSERT_EQ(sut_[0].i, 1);
    ASSERT_EQ(sut_[0].j, 2);
    ASSERT_EQ(sut_[1].i, 3);
    ASSERT_EQ(sut_[1].j, 4);
    ASSERT_EQ(sut_[2].i, 0xFFFF);
    ASSERT_EQ(sut_[2].j, 0xFFFF);
    ASSERT_EQ(sut_[3].i, 7);
    ASSERT_EQ(sut_[3].j, 8);
    ASSERT_EQ(sut_[4].i, 9);
    ASSERT_EQ(sut_[4].j, 10);
}