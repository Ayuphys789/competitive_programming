#pragma once

// Sieve of Eratosthenes
// verified with: "/atcoder/typical90/030.cpp"

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

struct eratosthenes
{
    int n;
    vector<bool> is_prime;
    vector<int> prime_list;
    vector<int> num_factor;
    eratosthenes(int n) : n(n)
    {
        is_prime.resize(n + 1, 1);
        num_factor.resize(n + 1, 0);
        is_prime[0] = 0;
        is_prime[1] = 0;
        for (int i = 2; i <= n; ++i)
        {
            if (is_prime[i])
            {
                ++num_factor[i];
                prime_list.push_back(i);
                for (int j = 2 * i; j <= n; j += i)
                {
                    is_prime[j] = 0;
                    ++num_factor[j];
                }
            }
        }
    }
};