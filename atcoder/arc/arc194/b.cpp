/**
 * Author: Ayuphys
 * Problem Number:
 * Title:
 * Link to the Problem:
 * Link to the Submission:
 * Difficulty:
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/structure/others/binary_indexed_tree.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    vector<int> P(N);
    vector<int> Q(N);
    rep(i, N)
    {
        cin >> P[i];
        --P[i];
        Q[P[i]] = i;
    }
    BinaryIndexedTree<ll> BIT(N);
    ll ans = 0;
    rFOR(i, N - 1, 1)
    {
        ll cnt = BIT.prod(0, Q[i]);
        ll left = Q[i] + 1 - cnt;
        ll right = i;
        ans += (left + right) * (right - left + 1) / 2;
        BIT.apply(Q[i], 1);
        // cout << left << " " << right << endl;
    }
    OUT(ans);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}