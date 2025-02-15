/**
 * Author: Ayuphys
 * Problem Number: typical90-034
 * Title: There are few types of elements
 * Link to the Problem: https://atcoder.jp/contests/typical90/tasks/typical90_ah
 * Link to the Submission: https://atcoder.jp/contests/typical90/submissions/61323067
 * Difficulty: 4
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/others/chmax.hpp"

void Ayuphys_solve(void)
{
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    vector<int> B(N, -1);
    map<int, int> M;
    int right = 0;
    int count = 0;
    rep(i, N)
    {
        while (right < N)
        {
            if (M[A[right]] == 0 && count == K)
            {
                break;
            }
            if (M[A[right]] == 0)
            {
                ++count;
            }
            ++M[A[right]];
            ++right;
        }
        B[i] = right - i;
        --M[A[i]];
        if (M[A[i]] == 0)
        {
            --count;
        }
    }
    int ans = 0;
    rep(i, N)
    {
        chmax(ans, B[i]);
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