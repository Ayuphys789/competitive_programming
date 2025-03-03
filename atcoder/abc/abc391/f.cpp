/**
 * Author: Ayuphys
 * Problem Number: abc391-f
 * Title: K-th Largest Triplet
 * Link to the Problem: https://atcoder.jp/contests/abc391/tasks/abc391_f
 * Link to the Submission: https://atcoder.jp/contests/abc391/submissions/63363471
 * Difficulty: 1554
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

ll calc(ll val1, ll val2, ll val3)
{
    return val1 * val2 + val2 * val3 + val3 * val1;
}

void Ayuphys_solve(void)
{
    int N, K;
    cin >> N >> K;
    vector<ll> A(N), B(N), C(N);
    rep(i, N)
    {
        cin >> A[i];
    }
    rep(i, N)
    {
        cin >> B[i];
    }
    rep(i, N)
    {
        cin >> C[i];
    }
    sort(all(A));
    sort(all(B));
    sort(all(C));
    reverse(all(A));
    reverse(all(B));
    reverse(all(C));

    priority_queue<tuple<ll, int, int, int>> PQ;

    PQ.push(make_tuple(calc(A[0], B[0], C[0]), 0, 0, 0));

    int cnt = 0;

    while (!PQ.empty())
    {
        auto W = PQ.top();
        PQ.pop();
        ++cnt;
        int x = get<1>(W);
        int y = get<2>(W);
        int z = get<3>(W);
        // OUT(get<0>(W));
        if (cnt == K)
        {
            ll Ans = get<0>(W);
            OUT(Ans);
            return;
        }
        if (z + 1 < N)
        {
            PQ.push(make_tuple(calc(A[x], B[y], C[z + 1]), x, y, z + 1));
        }
        if (z == 0 && y + 1 < N)
        {

            PQ.push(make_tuple(calc(A[x], B[y + 1], C[z]), x, y + 1, z));
        }
        if (y == 0 && z == 0 && x + 1 < N)
        {
            PQ.push(make_tuple(calc(A[x + 1], B[y], C[z]), x + 1, y, z));
        }
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