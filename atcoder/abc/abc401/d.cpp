/**
 * Author: Ayuphys
 * Problem Number: abc401-d
 * Title: Logical Filling
 * Link to the Problem: https://atcoder.jp/contests/abc401/tasks/abc401_d
 * Link to the Submission: https://atcoder.jp/contests/abc401/submissions/64783938
 * Difficulty: ?
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    int cnt = 0;
    rep(i, N)
    {
        if (S[i] == 'o')
        {
            ++cnt;
        }
        else if (S[i] == '?')
        {
            if (i > 0 && S[i - 1] == 'o')
            {
                S[i] = '.';
            }
            else if (i <= N - 2 && S[i + 1] == 'o')
            {
                S[i] = '.';
            }
        }
    }
    vector<pair<int, int>> V;
    int seq = 1;
    rep(i, N)
    {
        if (S[i] != '?')
        {
            seq = 1;
            continue;
        }
        if (i == N - 1 || S[i + 1] != '?')
        {
            V.emplace_back(make_pair(seq, i - seq + 1));
            seq = 1;
        }
        else
        {
            ++seq;
        }
    }
    if (K == cnt)
    {
        rep(i, N)
        {
            if (S[i] == '?')
            {
                S[i] = '.';
            }
        }
        rep(i, N)
        {
            cout << S[i];
        }
        ENDL;
        return;
    }
    int L = V.size();
    int sum = 0;
    rep(i, L)
    {
        sum += (V[i].first + 1) / 2;
    }
    if (sum > K - cnt)
    {
        rep(i, N)
        {
            cout << S[i];
        }
        ENDL;
        return;
    }
    rep(i, L)
    {
        if (V[i].first % 2 == 1)
        {
            rep(j, V[i].first)
            {
                if (j % 2 == 0)
                {
                    S[V[i].second + j] = 'o';
                }
                else
                {
                    S[V[i].second + j] = '.';
                }
            }
        }
    }
    rep(i, N)
    {
        cout << S[i];
    }
    ENDL;
    return;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}