#pragma once 

#include <algorithm>
#include <array>
#include <string_view>

namespace ASYS
{
    template <std::size_t _Size>
        requires (_Size > 0)
    struct StringLiteral
    {
        consteval StringLiteral() noexcept = default;

        template <std::size_t _OtherSize>
            requires (_OtherSize <= _Size)
        consteval StringLiteral(const StringLiteral<_OtherSize>& literal) noexcept
        {
            std::copy_n(literal.Data.begin(), _OtherSize, Data.begin());
        }

        consteval StringLiteral(const char (&data)[_Size]) noexcept
        {
            std::copy_n(data, _Size, Data.begin());
        }

        constexpr auto GetSize() const noexcept -> std::size_t
        {
            return _Size;
        }

        consteval auto GetLength() const noexcept -> std::size_t
        {
            const auto nullTermIter = std::ranges::find(Data, '\0');

            return std::distance(Data.begin(), nullTermIter);
        }

        constexpr auto operator [] (const std::size_t index)
            const noexcept -> char
        {
            return Data[index];
        }

        constexpr operator const char* () const noexcept
        {
            return Data.data();
        }

        template <std::size_t _OtherSize>
        constexpr auto operator + (StringLiteral<_OtherSize> literal)
            const noexcept -> StringLiteral<_Size + _OtherSize - 1>
        {
            auto result = StringLiteral<_Size + _OtherSize - 1>{};

            constexpr auto firstStringLimit = _Size - 1;
            
            for (auto i = 0uz; i < firstStringLimit; ++i)
            {
                result.Data[i] = Data[i];
            }
            for (auto i = 0uz; i < _OtherSize; ++i)
            {
                result.Data[i + firstStringLimit] = literal[i];
            }

            return result;
        }

        consteval auto Append(std::string_view str) -> StringLiteral&
        {
            const auto length = GetLength();

            if (length + str.size() >= _Size)
            {
                throw "[ASYS::StringLiteral::Append] The string "
                    "after the operations will exceed _Size";
            }

            std::copy(str.begin(), str.end(), Data.begin() + length);

            Data[length + str.size()] = '\0';

            return *this;
        }

        template<std::size_t _OtherSize>
        consteval auto Append(StringLiteral<_OtherSize> other)
            -> StringLiteral&
        {
            return Append(std::string_view{
                other.Data.data(),
                other.GetLength()
            });
        }
        template <std::size_t _OtherSize>
        constexpr auto operator == (const StringLiteral<_OtherSize>& literal)
            const noexcept -> bool
        {
            for (auto i = 0uz, end = std::max(_Size, _OtherSize); i < end; ++i)
            {
                if (i >= _Size)
                {
                    return !literal[i];
                }
                if (i >= _OtherSize)
                {
                    return !Data[i];
                }

                if (Data[i] != literal[i])
                {
                    return false;
                }
            }

            return true;
        }

        template <std::size_t _OtherSize>
        constexpr auto operator != (const StringLiteral<_OtherSize>& literal)
            const noexcept -> bool
        {
            return !(*this == literal);
        }

        std::array<char, _Size> Data{};
    };

    template <std::size_t _Size>
    using SL = StringLiteral<_Size>;
};
