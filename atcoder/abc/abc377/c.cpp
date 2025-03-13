/**
 * Author: Ayuphys
 * Problem Number: abc377-c
 * Title: Avoid Knight Attack
 * Link to the Problem: https://atcoder.jp/contests/abc377/tasks/abc377_c
 * Link to the Submission: https://atcoder.jp/contests/abc377/submissions/63692256
 * Difficulty: 274
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    ll N;
    int M;
    cin >> N >> M;
    set<pair<ll, ll>> S;
    ll ddx[9] = {0, 2, 1, -1, -2, -2, -1, 1, 2};
    ll ddy[9] = {0, 1, 2, 2, 1, -1, -2, -2, -1};
    rep(i, M)
    {
        int A, B;
        cin >> A >> B;
        --A;
        --B;
        rep(k, 9)
        {
            ll nx = A + ddx[k];
            ll ny = B + ddy[k];
            if (nx >= 0 && nx < N && ny >= 0 && ny < N)
            {
                S.insert(make_pair(nx, ny));
            }
        }
    }
    ll Ans = N * N - S.size();
    OUT(Ans);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}