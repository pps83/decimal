// Copyright 2026 Pavel P
// Distributed under the Boost Software License, Version 1.0.
// https://www.boost.org/LICENSE_1_0.txt

#ifndef BOOST_DECIMAL_FLOAT_CONVERSION_HPP
#define BOOST_DECIMAL_FLOAT_CONVERSION_HPP

#include <boost/decimal/decimal32_t.hpp>
#include <boost/decimal/decimal64_t.hpp>
#include <boost/decimal/decimal128_t.hpp>
#include <boost/decimal/decimal_fast32_t.hpp>
#include <boost/decimal/decimal_fast64_t.hpp>
#include <boost/decimal/decimal_fast128_t.hpp>
#include <boost/decimal/detail/concepts.hpp>
#include <boost/decimal/detail/convert_format.hpp>

namespace boost {
namespace decimal {

// The exact value of val correctly rounded to DecimalType in the current rounding mode: IEEE 754 convertFormat
// (5.4.2), as Intel's binary64_to_bid64 computes it. An exact result takes the exponent closest to 0, an inexact
// one all the digits. The constructor DecimalType {val} differs: it keeps the shortest decimal that reads back as
// val, so 0.07 gives 0.07 there and 0.07000000000000001 here (as decimal64_t, from 0.0700000000000000066613...).
BOOST_DECIMAL_EXPORT template <typename DecimalType>
BOOST_DECIMAL_CXX20_CONSTEXPR auto from_double(const double val) noexcept
    BOOST_DECIMAL_REQUIRES(detail::is_decimal_floating_point_v, DecimalType)
{
    return detail::convert_format::from_double<DecimalType>(val);
}

// The same for float, whose value a double holds exactly
BOOST_DECIMAL_EXPORT template <typename DecimalType>
BOOST_DECIMAL_CXX20_CONSTEXPR auto from_float(const float val) noexcept
    BOOST_DECIMAL_REQUIRES(detail::is_decimal_floating_point_v, DecimalType)
{
    return detail::convert_format::from_double<DecimalType>(static_cast<double>(val));
}

} // namespace decimal
} // namespace boost

#endif // BOOST_DECIMAL_FLOAT_CONVERSION_HPP
