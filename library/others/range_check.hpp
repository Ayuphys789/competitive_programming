#pragma once

bool range_check(int H, int W, int x, int y)
{
    bool ret = true;
    if (x < 0 || x >= H || y < 0 || y >= W)
    {
        ret = false;
    }
    return ret;
}