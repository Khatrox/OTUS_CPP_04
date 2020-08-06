//
// Created by xMellox on 05-Aug-20.
//
#include <gtest/gtest.h>
#include <endianess.h>

using namespace otus;

TEST(Endianess,CheckSwapEndian)
{
    short value = 123;

    auto SwappedValue = SwapEndian(value);
    auto SameValue = SwapEndian(SwappedValue);

    ASSERT_EQ(SwappedValue, 31488);
    ASSERT_EQ(SameValue, value);
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}