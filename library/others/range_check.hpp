#pragma once

// verified with: "/atcoder/abc/abc096/c.cpp"

bool range_check(int x, int y, int H, int W)
{
    bool ret = true;
    if (x < 0 || x >= H || y < 0 || y >= W)
    {
        ret = false;
    }
    return ret;
}