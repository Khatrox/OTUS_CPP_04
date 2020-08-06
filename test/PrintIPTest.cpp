//
// Created by xMellox on 05-Aug-20.
//
#include <gtest/gtest.h>
#include <print_ip.h>

using namespace otus;

TEST(CheckPrintIP,CheckIntegerImpl)
{
    std::stringstream ss;

    print_ip(short(123),ss);
    auto output = ss.str();

    ASSERT_STREQ(output.c_str(), "0.123");
}

TEST(CheckPrintIP,CheckStringImpl)
{
    std::stringstream ss;

    print_ip(std::string{"123.123"},ss);
    auto output = ss.str();

    ASSERT_STREQ(output.c_str(), "123.123");
}

TEST(CheckPrintIPContainer,CheckVectorPrint)
{
    std::stringstream ss;
    std::vector<int> v{123,444,122,144,0,12312};

    print_ip( v,ss);
    auto output = ss.str();

    ASSERT_STREQ(output.c_str(), "123.444.122.144.0.12312");
}

TEST(CheckPrintIPContainer,CheckListPrint)
{
    std::stringstream ss;
    std::list<int> l{127,0,111,444,333,2727};

    print_ip( l,ss);
    auto output = ss.str();

    ASSERT_STREQ(output.c_str(), "127.0.111.444.333.2727");
}

TEST(CheckPrintIP,CheckPrintIPTuple)
{
    std::stringstream ss;
    std::tuple<int,int,int,int> t{123,444,777,0};

    print_ip( t, ss);
    auto output = ss.str();

    ASSERT_STREQ(output.c_str(), "123.444.777.0");
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}