/**
 * Author: Ayuphys
 * Problem Number: abc398-f
 * Title: ABCBA
 * Link to the Problem: https://atcoder.jp/contests/abc398/tasks/abc398_f
 * Link to the Submission: https://atcoder.jp/contests/abc398/submissions/64719072
 * Difficulty: 1112
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/string/rolling_hash.hpp"

void Ayuphys_solve(void)
{
    string S;
    cin >> S;
    int N = S.size();
    string T = S;
    reverse(all(S));
    swap(S, T);
    int Z = N;
    int Y = N;
    int M = N / 2;
    RollingHash rhS(S), rhT(T);
    FOR(i, M, N - 2)
    {
        if (rhS.get(i, N) == rhT.get(N - 1 - i, 2 * N - 1 - 2 * i))
        {
            Z = i + 1;
            break;
        }
    }
    FOR(i, (N + 1) / 2, N - 1)
    {
        if (rhS.get(i, N) == rhT.get(N - i, 2 * N - 2 * i))
        {
            Y = i;
            break;
        }
    }
    if (2 * Z - 1 <= 2 * Y)
    {
        rep(i, Z)
        {
            cout << S[i];
        }
        rFOR(i, Z - 2, 0)
        {
            cout << S[i];
        }
        ENDL;
    }
    else
    {
        rep(i, Y)
        {
            cout << S[i];
        }
        rFOR(i, Y - 1, 0)
        {
            cout << S[i];
        }
        ENDL;
    }
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}