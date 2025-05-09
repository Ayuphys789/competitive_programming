/**
 * Author: Ayuphys
 * Problem Number: abc214-d
 * Title: Sum of Maximum Weights
 * Link to the Problem: https://atcoder.jp/contests/abc214/tasks/abc214_d
 * Link to the Submission: https://atcoder.jp/contests/abc214/submissions/65607611
 * Difficulty: 1341
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/structure/union_find/union_find.hpp"

struct Ayuphys_solve
{
    void Run(void)
    {
        int N;
        cin >> N;
        UnionFind uf(N);
        vector<tuple<ll, int, int>> A(N);
        rep(i, N - 1)
        {
            cin >> get<1>(A[i]) >> get<2>(A[i]) >> get<0>(A[i]);
            get<1>(A[i])--;
            get<2>(A[i])--;
        }
        sort(all(A));

        ll sum = 0;

        rep(i, N)
        {
            ll num_u = uf.size(get<1>(A[i]));
            ll num_v = uf.size(get<2>(A[i]));
            sum += num_u * num_v * get<0>(A[i]);
            uf.unite(get<1>(A[i]), get<2>(A[i]));
        }
        cout << sum << endl;
        return;
    }
};

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int testcase_number = 1;
    // cin >> testcase_number;

    rep(testcase, testcase_number)
    {
        Ayuphys_solve Ayuphys;
        Ayuphys.Run();
    }

    return 0;
}