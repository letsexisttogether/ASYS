#pragma once 

namespace ASYS
{
    template <auto _First, auto... _Args>
    inline constexpr auto IsOneOfV = static_cast<bool>
        (((_First == _Args) || ...));
};
