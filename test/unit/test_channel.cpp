#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>

#include "containers/channel.h"

#include "test_common.h"

std::string buffer_{};
class Fixture : public ::testing::Test
{
    void SetUp() override {
        buffer_ = std::string{};
    }
};

class Foo{
    public:
    void Transmit(const int source, const int destination, const auto &data) const{
        std::cout<< "Transmit() "<<source<<" -> "<<destination<<": "<<data<<std::endl;
        buffer_ += data;
    }
};

TEST_F(Fixture, ChannelCallsProxyTransmit_WhenTypical)
{
    Foo proxy{};
    const int kSource{1};
    const int kDestination{2};
    const int kLength{1};
    std::string expected = "abc";
    
    containers::channel<char, decltype(kSource), decltype(kLength), Foo> channel {proxy, kSource, kDestination, &Foo::Transmit};
    channel << 'a' << 'b' << 'c';

    ASSERT_EQ(buffer_, expected);
}

TEST_F(Fixture, ChannelCallsProxyTransmit_WhenStringPayloadType)
{
    Foo proxy{};
    const int kSource{1};
    const int kDestination{2};
    const int kLength{1};
    std::string expected = "abc";
    
    containers::channel<std::string, decltype(kSource), decltype(kLength), Foo> channel {proxy, kSource, kDestination, &Foo::Transmit};
    channel << "abc";

    ASSERT_EQ(buffer_, expected);
}