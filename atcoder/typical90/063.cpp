/**
 * Author: Ayuphys
 * Problem Number: typical90-063
 * Title: Monochromatic Subgrid
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_bk
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/61327540
 * Difficulty: 4
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/others/chmax.hpp"

void Ayuphys_solve(void)
{
    int H, W;
    cin >> H >> W;
    vector<vector<int>> P(H, vector<int>(W));
    rep(i, H)
    {
        rep(j, W)
        {
            cin >> P[i][j];
        }
    }
    int ans = 0;
    for (int bit = 1; bit < (1 << H); ++bit)
    {
        int ans_j = 0;
        vector<int> V;
        vector<int> F;
        rep(i, H)
        {
            if ((bit >> i) & 1)
            {
                F.push_back(i);
            }
        }
        rep(j, W)
        {
            bool all = true;
            FOR(i, 1, (int)F.size() - 1)
            {
                if (P[F[i]][j] != P[F[0]][j])
                {
                    all = false;
                }
            }
            if (all)
            {
                V.push_back(P[F[0]][j]);
            }
        }
        map<int, int> M;
        rep(i, (int)V.size())
        {
            ++M[V[i]];
            chmax(ans_j, M[V[i]]);
        }
        chmax(ans, ans_j * (int)F.size());
    }
    cout << ans << endl;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}