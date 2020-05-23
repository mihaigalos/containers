#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <memory>

#include "containers/dynamic_map.h"
#include "containers/static_map.h"

#include "test_common.h"

class MockDynamicMap : public containers::dynamic_map<uint16_t, DemoStructure, 2>
{
public:
    MOCK_METHOD(void, Die, ());
    virtual ~MockDynamicMap() { Die(); }

protected:
};

// see https://stackoverflow.com/a/7199706/2394327

TEST(DynamicMapDestructor, Works_WhenDynamicallyCreated)
{
    std::unique_ptr<MockDynamicMap> my_dynamic_map = std::make_unique<MockDynamicMap>();

    EXPECT_CALL(*my_dynamic_map, Die());
}

TEST(DynamicMapDestructor, Works_WhenStaticallyCreated)
{
    MockDynamicMap my_dynamic_map;

    EXPECT_CALL(my_dynamic_map, Die());
}
