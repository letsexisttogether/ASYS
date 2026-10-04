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

consteval auto BuildLiteral()
{
    auto literal = ASYS::SL<255>{};

    literal.Append(ASYS::SL{ "App" });
    literal.Append(ASYS::SL{ "end" });

    return literal;
}

TEST(Literal, Append)
{
    constexpr auto literal = BuildLiteral();

    static_assert(literal.GetSize() == 255);
    static_assert(literal.GetLength() == 6);
    static_assert(literal == ASYS::SL{ "Append" });
}

TEST(Literal, Trim)
{
    constexpr auto literal = ASYS::SL{ "Hello\0\0\0\0\0" };
    constexpr auto properLiteral = ASYS::Trim<literal>();

    static_assert(properLiteral.GetSize() == 6);
    static_assert(properLiteral.GetLength() == 5);
    static_assert(properLiteral == ASYS::SL{ "Hello" });
}
