#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "containers/dynamic_map.h"
#include "containers/static_map.h"

#include "test_common.h"

static constexpr uint16_t kMapSize = 10;

template <typename T>
class Fixture : public ::testing::Test
{
public:
protected:
    virtual void SetUp() override
    {
        sut_.clear();
    }

    T sut_;
};

using MyTypes = ::testing::Types<containers::dynamic_map<uint16_t, DemoStructure, kMapSize>,
                                 containers::static_map<uint16_t, DemoStructure, kMapSize>>;

TYPED_TEST_SUITE(Fixture, MyTypes);

TYPED_TEST(Fixture, ConstructWorks_WhenTypical)
{
    ASSERT_EQ(this->sut_.size(), 0);
}

TYPED_TEST(Fixture, ClearWorks_WhenTypical)
{
    this->sut_[0] = DemoStructure{1, 2};

    this->sut_.clear();

    ASSERT_EQ(this->sut_.size(), 0);
}

TYPED_TEST(Fixture, AddWorks_WhenTypical)
{
    auto expected = DemoStructure{1, 2};

    this->sut_[0] = DemoStructure{1, 2};
    auto actual = this->sut_[0];

    ASSERT_EQ(actual, expected);
}

TYPED_TEST(Fixture, AddMultiple_WhenInSequence)
{
    auto expected = DemoStructure{3, 4};

    this->sut_[0] = DemoStructure{1, 2};
    this->sut_[1] = DemoStructure{3, 4};

    ASSERT_EQ(this->sut_[1], expected);
}

TYPED_TEST(Fixture, AddMultiple_WhenRandom)
{
    auto expected = DemoStructure{5, 6};

    this->sut_[0] = DemoStructure{1, 2};
    this->sut_[2] = DemoStructure{5, 6};
    this->sut_[1] = DemoStructure{3, 4};

    ASSERT_EQ(this->sut_[2], expected);
}

TYPED_TEST(Fixture, AddMultiple_WhenRandom2)
{
    this->sut_[0] = DemoStructure{1, 2};
    this->sut_[2] = DemoStructure{5, 6};
    this->sut_[4] = DemoStructure{9, 10};
    this->sut_[1] = DemoStructure{3, 4};
    this->sut_[3] = DemoStructure{7, 8};

    ASSERT_EQ(this->sut_[0].i, 1);
    ASSERT_EQ(this->sut_[0].j, 2);
    ASSERT_EQ(this->sut_[1].i, 3);
    ASSERT_EQ(this->sut_[1].j, 4);
    ASSERT_EQ(this->sut_[2].i, 5);
    ASSERT_EQ(this->sut_[2].j, 6);
    ASSERT_EQ(this->sut_[3].i, 7);
    ASSERT_EQ(this->sut_[3].j, 8);
    ASSERT_EQ(this->sut_[4].i, 9);
    ASSERT_EQ(this->sut_[4].j, 10);
}

TYPED_TEST(Fixture, AddMultipleDeleteOne_WhenRandom)
{
    this->sut_[0] = DemoStructure{1, 2};
    this->sut_[2] = DemoStructure{5, 6};
    this->sut_[4] = DemoStructure{9, 10};
    this->sut_[1] = DemoStructure{3, 4};
    this->sut_[2] = DemoStructure{};
    this->sut_[3] = DemoStructure{7, 8};

    ASSERT_EQ(this->sut_[0].i, 1);
    ASSERT_EQ(this->sut_[0].j, 2);
    ASSERT_EQ(this->sut_[1].i, 3);
    ASSERT_EQ(this->sut_[1].j, 4);
    ASSERT_EQ(this->sut_[2].i, 0xFFFF);
    ASSERT_EQ(this->sut_[2].j, 0xFFFF);
    ASSERT_EQ(this->sut_[3].i, 7);
    ASSERT_EQ(this->sut_[3].j, 8);
    ASSERT_EQ(this->sut_[4].i, 9);
    ASSERT_EQ(this->sut_[4].j, 10);
}

TYPED_TEST(Fixture, ContainsKeyTrue_WhenTypical)
{
    auto expected = true;

    this->sut_[0] = DemoStructure{1, 2};
    this->sut_[2] = DemoStructure{5, 6};
    this->sut_[1] = DemoStructure{3, 4};
    auto actual = this->sut_.ContainsKey(1);

    ASSERT_EQ(actual, expected);
}

TYPED_TEST(Fixture, ContainsKeyTrue2_WhenTypical)
{
    auto expected = true;

    this->sut_[0] = DemoStructure{1, 2};
    this->sut_[2] = DemoStructure{5, 6};
    this->sut_[1] = DemoStructure{3, 4};
    auto actual = this->sut_.ContainsKey(2);

    ASSERT_EQ(actual, expected);
}

TYPED_TEST(Fixture, ContainsKeyFalse_WhenTypical)
{
    auto expected = false;

    this->sut_[0] = DemoStructure{1, 2};
    this->sut_[2] = DemoStructure{5, 6};
    this->sut_[1] = DemoStructure{3, 4};
    auto actual = this->sut_.ContainsKey(3);

    ASSERT_EQ(actual, expected);
}

TYPED_TEST(Fixture, AddDoesNotCorrupt_WhenTypical)
{
    auto expected = DemoStructure{9, 10};

    for(uint16_t i=0; i < kMapSize; ++i){
        this->sut_[i] = DemoStructure{i, static_cast<uint16_t>(i+1)};
    }

    auto actual = this->sut_[9];

    ASSERT_EQ(actual, expected);
}
