#pragma once

int digit_sum(long long x)
{
    int ret = 0;
    while (x > 0)
    {
        ret += x % 10;
        x /= 10;
    }
    return ret;
}