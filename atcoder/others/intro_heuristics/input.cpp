#include <bits/stdc++.h>

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

int main()
{
    std::mt19937 mt_for_construct(0);
    cout << 365 << "\n";
    rep(i, 26)
    {
        cout << mt_for_construct() % 101 << " ";
    }
    cout << "\n";
    rep(i, 365)
    {
        rep(j, 26)
        {
            cout << mt_for_construct() % 20001 << " ";
        }
        cout << "\n";
    }
    return 0;
}