/**
 * Author: Ayuphys
 * Problem Number:
 * Title:
 * Link to the Problem:
 * Link to the Submission:
 * Difficulty:
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    sort(A.begin(), A.end());
    int Q;
    cin >> Q;
    vector<ll> B(Q);
    rep(i, Q)
    {
        cin >> B[i];
        int ad = lower_bound(A.begin(), A.end(), B[i]) - A.begin();
        ll cl1 = -INFLL, cl2 = INFLL;
        if (ad == 0)
        {
            cl1 = A[0];
            cl2 = A[0];
        }
        else if (ad == N)
        {
            cl1 = A[N - 1];
            cl2 = A[N - 1];
        }
        else
        {
            cl1 = A[ad - 1];
            cl2 = A[ad];
        }
        cout << min(abs(B[i] - cl1), abs(B[i] - cl2)) << endl;
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