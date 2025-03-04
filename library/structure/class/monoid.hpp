#pragma once

// Monoid
// required by: "/library/structure/segment_tree/segment_tree.hpp"

template <typename S2, typename Op, typename E>
struct LambdaMonoid
{
    using S = S2;
    S op(const S &a, const S &b) const { return _op(a, b); }

    S e() const { return _e(); }

    LambdaMonoid(Op _op, E _e) : _op(_op), _e(_e) {}

private:
    Op _op;

    E _e;
};

template <typename Op, typename E>
LambdaMonoid(Op _op, E _e) -> LambdaMonoid<decltype(_e()), Op, E>;