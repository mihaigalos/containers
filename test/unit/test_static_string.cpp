#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "containers/static_string.h"

#include "test_common.h"

class Fixture : public ::testing::Test
{
public:
protected:
    virtual void SetUp() override
    {
        sut_.clear();
    }

    containers::static_string<> sut_;
};

TEST_F(Fixture, ConstructorWorks_WhenTypical)
{
    containers::static_string<> myString{"FooBar"};

    ASSERT_EQ(myString.size(), 7);
}

TEST_F(Fixture, ConstructorFirstLetterCoincidesWorks_WhenTypical)
{
    containers::static_string<> myString{"FooBar"};

    ASSERT_EQ(myString[0], 'F');
}

TEST_F(Fixture, CStrWorks_WhenTypical)
{
    containers::static_string<> myString{"FooBar"};

    const char *character = myString.c_str();

    // std::cout << "character: " << character << std::endl;
    ASSERT_EQ(*character, 'F');
}

// TEST_F(Fixture, CopyConstructorWorks_WhenTypical)
// {
//     containers::static_string<> myString{"FooBar"};

//     containers::static_string<> myString2{myString};

//     ASSERT_GT(myString2.size(), 0);
// }

// TEST_F(Fixture, MoveConstructorWorks_WhenTypical)
// {
//     containers::static_string<> myString{containers::static_string<>{"FooBar"}};

//     ASSERT_GT(myString.size(), 0);
// }

// TEST_F(Fixture, CopyAssignmentWorks_WhenTypical)
// {
//     containers::static_string<> s{"FooBar"};

//     containers::static_string<> myString = s;

//     ASSERT_GT(myString.size(), 0);
// }

// TEST_F(Fixture, MoveAssignmentWorks_WhenTypical)
// {

//     containers::static_string<> myString = {"FooBar"};

//     ASSERT_GT(myString.size(), 0);
// }

// TEST_F(Fixture, OperatorEqualsWorks_WhenTypical)
// {
//     std::string expected{"FooBar"};

//     containers::static_string<> other{"FooBar"};

//     ASSERT_EQ(sut_, other);
// }

// TEST_F(Fixture, OperatorNotEqualsWorks_WhenTypical)
// {
//     std::string expected{"FooBla"};

//     containers::static_string<> other{"FooBar"};

//     ASSERT_NE(sut_, other);
// }