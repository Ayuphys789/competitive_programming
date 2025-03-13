/**
 * Author: Ayuphys
 * Problem Number: abc334-e
 * Title: Christmas Color Grid 1
 * Link to the Problem: https://atcoder.jp/contests/abc334/tasks/abc334_e
 * Link to the Submission: https://atcoder.jp/contests/abc334/submissions/63696637
 * Difficulty: 1195
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/structure/union_find/union_find.hpp"
#include "/home/ayuphys789/competitive_programming/library/math/number_theory/modint.hpp"
using mint = Fp<MOD>;

void Ayuphys_solve(void)
{
    int H, W;
    cin >> H >> W;
    vector<vector<char>> S(H, vector<char>(W));
    rep(i, H)
    {
        rep(j, W)
        {
            cin >> S[i][j];
        }
    }
    UnionFind uf(H * W);
    vector<mint> V;
    rep(i, H)
    {
        rep(j, W)
        {
            if (S[i][j] == '.')
            {
                continue;
            }
            rep(k, 4)
            {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx < 0 || nx >= H || ny < 0 || ny >= W)
                {
                    continue;
                }
                if (S[nx][ny] == '#')
                {
                    uf.unite(i * W + j, nx * W + ny);
                }
            }
        }
    }
    set<int> cnt;
    rep(i, H)
    {
        rep(j, W)
        {
            if (S[i][j] == '#')
            {
                cnt.insert(uf.root(i * W + j));
                continue;
            }
            set<int> st;
            rep(k, 4)
            {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx < 0 || nx >= H || ny < 0 || ny >= W)
                {
                    continue;
                }
                if (S[nx][ny] == '#')
                {
                    st.insert(uf.root(nx * W + ny));
                }
            }
            V.emplace_back((mint)(st.size() - 1));
        }
    }
    mint Ans = cnt.size();
    mint num = V.size();
    mint sum = 0;
    rep(i, V.size())
    {
        sum += V[i];
    }
    Ans -= sum / num;
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