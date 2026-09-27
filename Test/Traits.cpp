#include <gtest/gtest.h>

#include <ASYS/Traits/Traits.hpp>

TEST(Traits, IsOneOfV)
{
    enum class State
    {
        None, 
        First,
        Second
    };

    constexpr auto state = State::First;

    constexpr auto stateEqual = ASYS::IsOneOfV
    <
        state, State::First, State::Second
    >;

    EXPECT_TRUE(stateEqual);
}
