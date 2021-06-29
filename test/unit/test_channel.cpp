#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "containers/channel.h"

#include "test_common.h"

class Fixture : public ::testing::Test
{
};

class Foo{
    public:
    void Transmit(const char &data) const{
        std::cout<< "Transmit(): "<<data<<std::endl;
    }
};

TEST_F(Fixture, ConstructorWorks_WhenTypical)
{
    Foo object{};
    containers::channel<char, Foo> channel{object, &Foo::Transmit};
    channel << 'a';
}