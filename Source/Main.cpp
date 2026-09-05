#include <iostream>
#include <cstdint>

#include <ASYS/String/StringLiteral.hpp>
#include <ASYS/Something/Something.hpp>

auto main() -> std::int32_t
{
    std::cout << ASYS::SL{ "Hello, ASYS " }
        << SomeThing() << std::endl;

    return EXIT_SUCCESS;
}


