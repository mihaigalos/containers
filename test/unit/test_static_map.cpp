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

using MyTypes = ::testing::Types<containers::static_map<uint16_t, DemoStructure, kMapSize>>;
TYPED_TEST_SUITE(Fixture, MyTypes);

TYPED_TEST(Fixture, GuardsAgainstCorruption_WhenTypical)
{
    auto expected = DemoStructure{11, 12};

    for(uint16_t i =0; i < kMapSize + 2; ++i){
        this->sut_[i] = DemoStructure{i, static_cast<uint16_t>(i + 1)};
    }

    auto actual1 = this->sut_[10];
    ASSERT_EQ(actual1, expected);
    auto actual2 = this->sut_[11];
    ASSERT_EQ(actual2, expected);
}
