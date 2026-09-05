#include <cstring>
#include <gtest/gtest.h>

#include <ASYS/String/StringLiteral.hpp>

TEST(Literal, Constuction)
{
    constexpr auto literal = ASYS::SL{ "Hello" };
    const auto cStr = "Hello";

    EXPECT_EQ(std::strcmp(literal, cStr), 0);
}
