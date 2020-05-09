#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "containers/static_vector.h"

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

    containers::static_vector<DemoStructure> sut_;
};

TEST_F(Fixture, PushBack_WhenTypicalOneElement)
{
    DemoStructure data{1, 2};

    sut_.push_back(data);

    ASSERT_EQ(sut_[0].i, 1);
    ASSERT_EQ(sut_[0].j, 2);
}

TEST_F(Fixture, PushBackRValue_WhenTypicalOneElement)
{
    sut_.push_back(DemoStructure{1, 2});

    ASSERT_EQ(sut_[0].i, 1);
    ASSERT_EQ(sut_[0].j, 2);
}

TEST_F(Fixture, PushBack_WhenTypicalTwoElement)
{
    DemoStructure data{1, 2};
    DemoStructure data1{3, 4};

    sut_.push_back(data);
    sut_.push_back(data1);

    ASSERT_EQ(sut_[1].i, 3);
    ASSERT_EQ(sut_[1].j, 4);
}

TEST_F(Fixture, PushBack_WhenTypicalThreeElement)
{
    DemoStructure data{1, 2};
    DemoStructure data1{3, 4};
    DemoStructure data2{5, 6};

    sut_.push_back(data);
    sut_.push_back(data2);
    sut_.push_back(data1);

    ASSERT_EQ(sut_[2].i, 3);
    ASSERT_EQ(sut_[2].j, 4);
}

TEST_F(Fixture, PopBack_WhenTypical)
{
    DemoStructure data{1, 2};
    DemoStructure data1{3, 4};
    DemoStructure data2{5, 6};

    sut_.push_back(data);
    sut_.push_back(data1);
    sut_.push_back(data2);
    auto actual = sut_.pop_back();

    ASSERT_EQ(actual.i, 5);
    ASSERT_EQ(actual.j, 6);
}

TEST_F(Fixture, PopPush_WhenTypical)
{
    DemoStructure data{1, 2};
    DemoStructure data1{3, 4};
    DemoStructure data2{5, 6};
    DemoStructure data3{7, 8};

    sut_.push_back(data);
    sut_.push_back(data1);
    sut_.push_back(data2);
    auto actual = sut_.pop_back();

    sut_.push_back(data3);

    ASSERT_EQ(actual.i, 5);
    ASSERT_EQ(actual.j, 6);
}

TEST_F(Fixture, PushPopPushPop_WhenTypical)
{
    DemoStructure data{1, 2};
    DemoStructure data3{7, 8};

    sut_.push_back(data);
    sut_.pop_back();
    sut_.push_back(data3);
    auto actual = sut_.pop_back();

    ASSERT_EQ(actual.i, 7);
    ASSERT_EQ(actual.j, 8);
}