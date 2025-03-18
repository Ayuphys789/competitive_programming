/**
 * Author: Ayuphys
 * Problem Number: abc380-d
 * Title: Strange Mirroring
 * Link to the Problem: https://atcoder.jp/contests/abc380/tasks/abc380_d
 * Link to the Submission: https://atcoder.jp/contests/abc380/submissions/63933480
 * Difficulty: 849
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    string S;
    cin >> S;
    ll N = S.size();
    vector<bool> cap(N, 0);
    rep(i, N)
    {
        if (S[i] - 'A' >= 0 && S[i] - 'A' <= 25)
        {
            cap[i] = 1;
        }
    }
    ll Q;
    cin >> Q;
    rep(query, Q)
    {
        ll C;
        cin >> C;
        C -= 1;
        ll A = C / N;
        ll B = C % N;
        ll num = __builtin_popcountll(A);
        if (num % 2 == 0)
        {
            SOUT(S[B]);
        }
        else if (cap[B])
        {
            SOUT((char)(S[B] + 32));
        }
        else
        {
            SOUT((char)(S[B] - 32));
        }
    }

    ENDL;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}