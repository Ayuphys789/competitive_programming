/**
 * Author: Ayuphys
 * Problem Number: abc323-c
 * Title: World Tour Finals
 * Link to the Problem: https://atcoder.jp/contests/abc323/tasks/abc323_c
 * Link to the Submission: https://atcoder.jp/contests/abc323/submissions/63625262
 * Difficulty: 357
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> A(M);
    rep(i, M)
    {
        cin >> A[i].first;
        A[i].second = i;
    }
    sort(all(A));
    reverse(all(A));
    vector<vector<bool>> C(N, vector<bool>(M));
    rep(i, N)
    {
        string S;
        cin >> S;
        rep(j, M)
        {
            C[i][j] = (S[A[j].second] == 'o' ? 1 : 0);
        }
    }
    vector<int> score(N);
    rep(i, N)
    {
        rep(j, M)
        {
            if (C[i][j])
            {
                score[i] += A[j].first;
            }
        }
        score[i] += i;
    }
    rep(i, N)
    {
        int Ans = 0;
        rep(j, N)
        {
            int Ans_j = 0;
            if (i == j || score[i] > score[j])
            {
                continue;
            }
            int dif = score[j] - score[i];
            rep(k, M)
            {
                if (!C[i][k])
                {
                    dif -= A[k].first;
                    Ans_j += 1;
                }
                if (dif < 0)
                {
                    break;
                }
            }
            chmax(Ans, Ans_j);
        }
        OUT(Ans);
    }
    // VOUT(score);
    // VVOUT(C);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}