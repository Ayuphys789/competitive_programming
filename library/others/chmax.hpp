#pragma once

template <typename T>
inline bool chmax(T &a, T b)
{
    return ((a < b) ? (a = b, true) : (false));
};