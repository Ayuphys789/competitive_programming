#include "../../template/template.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    vector<ll> H(N);
    rep(i, N) cin >> H[i];
    ll T = 0;
    rep(i, N)
    {
        ll h = H[i];
        ll quot = h / 5;
        T += quot * 3;
        h -= quot * 5;
        while (h > 0)
        {
            T++;
            if (T % 3 == 0)
            {
                h -= 3;
            }
            else
            {
                h -= 1;
            }
        }
    }
    cout << T << endl;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}