/**
 * Author: Ayuphys
 * Problem Number: abc367-e
 * Title: Permute K times
 * Link to the Problem: https://atcoder.jp/contests/abc367/tasks/abc367_e
 * Link to the Submission: https://atcoder.jp/contests/abc367/submissions/65067655
 * Difficulty: 1370
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    ll K;
    cin >> N >> K;
    vector<int> X(N);
    vector<ll> A(N);
    rep(i, N)
    {
        cin >> X[i];
        --X[i];
    }
    rep(i, N)
    {
        cin >> A[i];
    }
    vector<vector<int>> db(61, vector<int>(N, -1));
    rep(i, N)
    {
        db[0][i] = X[i];
    }
    FOR(b, 1, 60)
    {
        rep(i, N)
        {
            db[b][i] = db[b - 1][db[b - 1][i]];
        }
    }
    vector<int> ids(N);
    rep(i, N)
    {
        ids[i] = i;
    }
    rep(b, 61)
    {
        if (((K >> b) & 1) == 1)
        {
            rep(i, N)
            {
                ids[i] = db[b][ids[i]];
            }
        }
    }
    rep(i, N)
    {
        SOUT(A[ids[i]]);
    }
    ENDL;
    // ENDL;
    // VVOUT(db);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}