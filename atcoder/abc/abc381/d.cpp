/**
 * Author: Ayuphys
 * Problem Number: abc381-d
 * Title: 1122 Substring
 * Link to the Problem: https://atcoder.jp/contests/abc381/tasks/abc381_d
 * Link to the Submission: https://atcoder.jp/contests/abc381/submissions/63925960
 * Difficulty: 921
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    // input
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N)
    {
        cin >> A[i];
    }

    // ランレングス圧縮
    vector<int> B;
    int cnt = 1;
    rep(i, N)
    {
        if (i == N - 1 || A[i] != A[i + 1])
        {
            if (cnt < 2)
            {
                B.emplace_back(-1);
            }
            else if (cnt == 2)
            {
                B.emplace_back(A[i]);
            }
            else if (cnt > 2)
            {
                B.emplace_back(A[i]);
                B.emplace_back(-1);
                B.emplace_back(A[i]);
            }
            cnt = 1;
            // cout << A[i] << " " << cnt << endl;s
        }
        else if (A[i] == A[i + 1])
        {
            ++cnt;
        }
        else
        {
            cnt = 1;
        }
    }

    // VOUT(B);

    // 尺取り法
    int Ans = 0;
    int right = 0;
    int S = B.size();
    set<int> st;
    FOR(left, 0, S - 1)
    {
        if (B[left] == -1)
        {
            right = left;
            st.clear();
            continue;
        }
        while (right + 1 < S)
        {
            if (B[right + 1] == -1)
            {
                break;
            }
            int val = B[right + 1];
            if (st.find(val) != st.end())
            {
                break;
            }
            st.insert(val);
            right++;
        }
        chmax(Ans, right - left + 1);
        st.erase(B[left]);
        // cout << left << " " << right << endl;
    }
    OUT(2 * Ans);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}