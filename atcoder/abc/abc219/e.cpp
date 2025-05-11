/**
 * Author: Ayuphys
 * Problem Number: abc219-e
 * Title: Moat
 * Link to the Problem: https://atcoder.jp/contests/abc219/tasks/abc219_e
 * Link to the Submission: https://atcoder.jp/contests/abc219/submissions/65721168
 * Difficulty: 1690
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/structure/union_find/union_find.hpp"

constexpr const int N = 4;

struct Ayuphys_solve
{
    void Run(void)
    {
        vector<vector<int>> A(N + 2, vector<int>(N + 2, 0));
        rep(i, 4) rep(j, 4) cin >> A[i + 1][j + 1];
        int ans = 0;
        rep(bit, (1 << (N * N)))
        {
            UnionFind uf((N + 2) * (N + 2));
            vector<vector<bool>> C(N + 2, vector<bool>(N + 2, 0));
            int num = 0;
            vector<vector<int>> used(4, vector<int>(4));
            bool all = 1;
            rep(i, N) rep(j, N)
            {
                bool in = (bit >> (i * N + j)) & 1;
                if (in)
                {
                    num++;
                    C[i + 1][j + 1] = 1;
                }
                if (A[i + 1][j + 1] && !C[i + 1][j + 1])
                {
                    all = 0;
                }
            }
            if (!all)
                continue;
            // VVOUT(C);
            // OUT("--------");
            rep(i, N + 2) rep(j, N + 2)
            {
                rep(k, 2)
                {
                    int ni = i + di[k], nj = j + dj[k];
                    if (ni < 0 || ni >= N + 2 || nj < 0 || nj >= N + 2)
                        continue;
                    if (C[i][j] == C[ni][nj])
                    {
                        uf.unite(i * (N + 2) + j, ni * (N + 2) + nj);
                    }
                }
            }
            if (uf.connected_components_number() == 2)
            {
                ans++;
            }
            // cout << bit << ": " << uf.connected_components_number() << "," << num << endl;
        }
        OUT(ans);
        return;
    }
};

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int testcase_number = 1;
    // cin >> testcase_number;

    rep(testcase, testcase_number)
    {
        Ayuphys_solve Ayuphys;
        Ayuphys.Run();
    }

    return 0;
}