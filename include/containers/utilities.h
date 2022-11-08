#pragma once

namespace containers
{

template <typename T, typename U>
constexpr decltype(auto) forward(U &&u) noexcept
{
    return static_cast<T &&>(u);
}

} // namespace containers

