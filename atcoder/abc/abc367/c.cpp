/**
 * Author: Ayuphys
 * Problem Number:
 * Title:
 * Link to the Problem:
 * Link to the Submission:
 * Difficulty:
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

int N, K;
vector<int> R;
vector<int> seq;

void rec(int layer)
{
    if (layer == N)
    {
        int sum = 0;
        rep(i, N)
        {
            sum += seq[i];
        }
        if (sum % K)
        {
            return;
        }
        rep(i, N)
        {
            cout << seq[i] << " ";
        }
        cout << endl;
        return;
    }
    else
    {
        rep(i, R[layer])
        {
            seq[layer] = i + 1;
            rec(layer + 1);
        }
        return;
    }
}

void Ayuphys_solve(void)
{
    cin >> N >> K;
    R.resize(N, 0);
    seq.resize(N, 0);
    rep(i, N) cin >> R[i];
    rec(0);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}