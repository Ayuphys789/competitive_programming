#pragma once

template <typename T>
inline bool chmin(T &a, T b)
{
    return ((a > b) ? (a = b, true) : (false));
};