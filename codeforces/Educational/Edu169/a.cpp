#include "../../template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    if (N > 2)
    {
        cout << "NO\n";
        return;
    }
    if (A[0] + 1 == A[1])
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int query;
    cin >> query;
    while (query--)
    {
        Ayuphys_solve();
    }

    return 0;
}