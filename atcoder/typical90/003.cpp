#include "../../template/template.hpp"
#include "../../library/tree/tree_diameter.hpp"

void Ayuphys_solve(void)
{
    int N;
    cin >> N;
    TreeDiameter<int> g(N);
    g.read(N - 1, -1, false, false);
    cout << g.build() + 1 << endl;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}