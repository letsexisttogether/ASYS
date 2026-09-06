#include <cstring>
#include <gtest/gtest.h>

#include <ASYS/String/StringLiteral.hpp>

TEST(Literal, Constuction)
{
    constexpr auto literal = ASYS::SL{ "Hello" };
    const auto cStr = "Hello";

    EXPECT_EQ(std::strcmp(literal, cStr), 0);
}

TEST(Literal, Copy)
{
    constexpr auto literal = ASYS::SL{ "CopyMeCompletely" };
    constexpr auto copy = ASYS::SL<60>{ literal };

    EXPECT_EQ(copy.GetLength(), 16);

    EXPECT_TRUE(literal == copy);
}
