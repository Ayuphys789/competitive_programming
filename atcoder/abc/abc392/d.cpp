/**
 * Author: Ayuphys
 * Problem Number: abc392-d
 * Title: Doubles
 * Link to the Problem: https://atcoder.jp/contests/abc392/tasks/abc392_d
 * Link to the Submission: https://atcoder.jp/contests/abc392/submissions/63710531
 * Difficulty: 579
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    vector<vector<int>> A(N);
    vector<map<int, int>> M(N);
    rep(i, N)
    {
        int L;
        cin >> L;
        A[i].assign(L, 0);
        rep(j, L)
        {
            cin >> A[i][j];
            M[i][A[i][j]] += 1;
        }
        sort(all(A[i]));
    }
    double Ans = 0;
    rep(i, N - 1)
    {
        FOR(j, i + 1, N - 1)
        {
            // cout << i << " and " << j << endl;
            double numerator = 0.0;
            double denominator = (double)(A[i].size() * A[j].size());
            // for (auto itr = M[i].begin(); itr != M[i].end(); ++itr)
            // {
            //     double val1 = itr->second;
            //     double val2 = M[j][itr->first];
            //     // Fcout(0) << val1 << " " << val2 << endl;
            //     numerator += val1 * val2;
            // }
            int cnt = 1;
            rep(k, A[i].size())
            {
                if (k < A[i].size() - 1 && A[i][k] == A[i][k + 1])
                {
                    ++cnt;
                }
                else
                {
                    double val1 = cnt;
                    double val2 = M[j][A[i][k]];
                    numerator += val1 * val2;
                    cnt = 1;
                }
            }
            chmax(Ans, numerator / denominator);
        }
    }
    fOUT(Ans);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}