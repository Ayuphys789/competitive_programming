/**
 * Author: Ayuphys
 * Problem Number: round1018-d
 * Title: Wonderful Lightbulbs
 * Link to the Problem: https://codeforces.com/contest/2096/problem/D
 * Link to the Submission: https://codeforces.com/contest/2096/submission/316324056
 * Difficulty: ?
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    vector<ll> A(N), B(N);
    ll X = 0, Y = 0;
    map<ll, ll> M1, M2;
    rep(i, N)
    {
        cin >> A[i] >> B[i];
        M1[A[i]] += 1;
        M2[A[i] + B[i]] += 1;
    }

    for (auto itr = M1.begin(); itr != M1.end(); ++itr)
    {
        if (itr->second % 2 != 0)
        {
            X = itr->first;
            break;
        }
    }

    for (auto itr = M2.begin(); itr != M2.end(); ++itr)
    {
        if (itr->second % 2 != 0)
        {
            Y = itr->first - X;
            break;
        }
    }

    cout << X << " " << Y << endl;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int testcase_num;
    cin >> testcase_num;

    rep(testcase, testcase_num)
    {
        Ayuphys_solve();
    }

    return 0;
}