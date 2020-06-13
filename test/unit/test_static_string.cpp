#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "containers/static_string.h"

#include "test_common.h"

class Fixture : public ::testing::Test
{
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

    ASSERT_EQ(*character, 'F');
}

TEST_F(Fixture, OperatorEqualsWorks_WhenTypical)
{
    containers::static_string<> expected{"FooBar"};

    containers::static_string<> other{"FooBar"};

    ASSERT_EQ(expected, other);
}

TEST_F(Fixture, OperatorNotEqualsWorks_WhenTypical)
{
    containers::static_string<> expected{"FooBla"};

    containers::static_string<> other{"FooBar"};

    ASSERT_NE(expected, other);
}

TEST_F(Fixture, CopyConstructorWorks_WhenTypical)
{
    containers::static_string<> myString{"FooBar"};

    containers::static_string<> myString2{myString};

    ASSERT_GT(myString2.size(), 0);
}

TEST_F(Fixture, CopyConstructorActuallyCopies_WhenTypical)
{
    containers::static_string<> myString{"FooBar"};

    containers::static_string<> myString2{myString};

    ASSERT_EQ(myString2, myString);
}

TEST_F(Fixture, MoveConstructorWorks_WhenTypical)
{
    containers::static_string<> intial_string{"FooBar"};

    containers::static_string<> myString{std::move(intial_string)};

    ASSERT_GT(myString.size(), 0);
}

TEST_F(Fixture, MoveConstructorActuallyMoves_WhenTypical)
{
    containers::static_string<> initial_string{"FooBar"};

    containers::static_string<> myString{std::move(initial_string)};

    ASSERT_EQ(myString, containers::static_string<>{"FooBar"});
}

TEST_F(Fixture, CopyAssignmentWorks_WhenTypical)
{
    containers::static_string<> s{"FooBar"};

    containers::static_string<> myString = s;

    ASSERT_GT(myString.size(), 0);
}

TEST_F(Fixture, CopyAssignmentActuallyCopies_WhenTypical)
{
    containers::static_string<> s{"FooBar"};

    containers::static_string<> myString = s;

    ASSERT_EQ(myString, s);
}

TEST_F(Fixture, CopyAssignmentWorks_WhenReasignment)
{
    containers::static_string<> myString = {"FooBar"};

    myString = "Baz";

    ASSERT_EQ(myString, containers::static_string<>{"Baz"});
}

TEST_F(Fixture, MoveAssignmentWorks_WhenTypical)
{
    containers::static_string<> myString = {"FooBar"};

    ASSERT_GT(myString.size(), 0);
}

TEST_F(Fixture, MoveAssignmentActuallyMoves_WhenTypical)
{
    containers::static_string<> myString = {"FooBar"};

    ASSERT_EQ(myString, containers::static_string<>{"FooBar"});
}

TEST_F(Fixture, MoveAssignmentWorks_WhenMovedAfterCreation)
{
    containers::static_string<> myString{};

    myString = {"FooBar"};

    ASSERT_EQ(myString, containers::static_string<>{"FooBar"});
}

TEST_F(Fixture, OperatorPlusWorks_WhenTypical)
{
    containers::static_string<> myString = {"FooBar"};

    containers::static_string<> result = myString + "Baz";

    ASSERT_EQ(result, containers::static_string<>{"FooBarBaz"});
}

TEST_F(Fixture, OperatorPlusRValueWorks_WhenTypical)
{
    containers::static_string<> myString = {"FooBar"};

    myString = myString + "Baz";

    ASSERT_EQ(myString, containers::static_string<>{"FooBarBaz"});
}

TEST_F(Fixture, OperatorPlusLValueWorks_WhenTypical)
{
    containers::static_string<> myString = {"FooBar"};
    containers::static_string<> otherString = {"Baz"};

    myString = otherString;

    ASSERT_EQ(myString, containers::static_string<>{"Baz"});
}

TEST_F(Fixture, OperatorPlusEqualsRValueStringWorks_WhenTypical)
{
    containers::static_string<> myString = {"FooBar"};

    myString += "Baz";

    ASSERT_EQ(myString, containers::static_string<>{"FooBarBaz"});
}

TEST_F(Fixture, OperatorPlusStaticString_WhenTypical)
{
    containers::static_string<> myString = {"FooBar"};
    containers::static_string<> other{"Baz"};

    myString = myString + other;

    ASSERT_EQ(myString, containers::static_string<>{"FooBarBaz"});
}

TEST_F(Fixture, OperatorPlusStaticStringRValue_WhenTypical)
{
    containers::static_string<> myString = {"FooBar"};

    containers::static_string<> second_string = myString + containers::static_string<>{"Baz"};

    ASSERT_EQ(myString, containers::static_string<>{"FooBar"});
    ASSERT_EQ(second_string, containers::static_string<>{"FooBarBaz"});
}

TEST_F(Fixture, OperatorPlusEqualsStaticString_WhenTypical)
{
    containers::static_string<> myString = {"FooBar"};
    containers::static_string<> other{"Baz"};

    myString += other;

    ASSERT_EQ(myString, containers::static_string<>{"FooBarBaz"});
}

TEST_F(Fixture, OperatorPlusEqualsStaticStringRValue_WhenTypical)
{
    containers::static_string<> myString = {"FooBar"};

    myString += containers::static_string<>{"Baz"};

    ASSERT_EQ(myString, containers::static_string<>{"FooBarBaz"});
}

TEST_F(Fixture, OperatorPlusEqualsRValueCharWorks_WhenTypical)
{
    containers::static_string<> myString = {"FooBar"};

    myString += 'B';

    ASSERT_EQ(myString, containers::static_string<>{"FooBarB"});
}

TEST_F(Fixture, OperatorPlusCharWorks_WhenTypical)
{
    containers::static_string<> myString = {"FooBar"};

    myString = myString + 'B';

    ASSERT_EQ(myString, containers::static_string<>{"FooBarB"});
}

TEST_F(Fixture, OperatorPlusNullIgnores_WhenTypical)
{
    containers::static_string<> myString = {"FooBar"};
    auto expected = myString.size();

    myString = myString + '\0';
    auto actual = myString.size();

    ASSERT_EQ(actual, expected);
}

containers::static_string<> get()
{
    containers::static_string<> result{};
    return result;
}

TEST_F(Fixture, SizeZero_WhenReturned)
{
    containers::static_string<> myString = get();

    ASSERT_EQ(myString.size(), 0);
}

TEST_F(Fixture, SizeZero_WhenReturnedMoved)
{
    containers::static_string<> myString = std::move(get());

    ASSERT_EQ(myString.size(), 0);
}