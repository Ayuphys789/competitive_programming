/**
 * Author: Ayuphys
 * Problem Number: abc380-e
 * Title: 1D Bucket Tool
 * Link to the Problem: https://atcoder.jp/contests/abc380/tasks/abc380_e
 * Link to the Submission: https://atcoder.jp/contests/abc380/submissions/63936353
 * Difficulty: 1230
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"
#include "/home/ayuphys789/competitive_programming/library/structure/union_find/union_find.hpp"

void Ayuphys_solve(void)
{
    int N, Q;
    cin >> N >> Q;
    UnionFind uf(N);
    vector<int> color(N);
    vector<int> cnt(N, 1);
    vector<int> length(N, 1);
    vector<int> left(N, 1);
    rep(i, N)
    {
        color[i] = i;
        left[i] = i;
    }

    rep(query, Q)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int X, C;
            cin >> X >> C;
            --X;
            --C;
            int length_X = length[uf.root(X)];
            int left_X = left[uf.root(X)];
            int color_X = color[uf.root(X)];
            cnt[color_X] -= length_X;
            cnt[C] += length_X;
            color[uf.root(X)] = C;
            if (left_X + length_X < N)
            {
                if (color[uf.root(left_X + length_X)] == C)
                {
                    // cout << "joined right!\n";
                    int length_Y = length[uf.root(left_X + length_X)];
                    uf.unite(left_X, left_X + length_X);
                    length[uf.root(X)] = length_X + length_Y;
                    left[uf.root(X)] = left_X;
                    color[uf.root(X)] = C;
                }
            }
            length_X = length[uf.root(X)];
            left_X = left[uf.root(X)];
            color_X = color[uf.root(X)];
            if (left_X > 0)
            {
                if (color[uf.root(left_X - 1)] == C)
                {
                    // cout << "joined left!\n";
                    int length_Y = length[uf.root(left_X - 1)];
                    int left_Y = left[uf.root(left_X - 1)];
                    uf.unite(left_X, left_X - 1);
                    length[uf.root(X)] = length_X + length_Y;
                    left[uf.root(X)] = left_Y;
                    color[uf.root(X)] = C;
                }
            }
            // cout << left_X << ":" << color[uf.root(left_X - 1)] << ":" << C << endl;
        }
        else if (type == 2)
        {
            int C;
            cin >> C;
            --C;
            OUT(cnt[C]);
        }
        // rep(i, N)
        // {
        //     cout << length[uf.root(i)] << " ";
        // }
        // cout << "    length\n";
        // rep(i, N)
        // {
        //     cout << color[uf.root(i)] << " ";
        // }
        // cout << "    color\n";
        // rep(i, N)
        // {
        //     cout << left[uf.root(i)] << " ";
        // }
        // cout << "    left\n";
        // rep(i, N)
        // {
        //     cout << cnt[i] << " ";
        // }
        // cout << "    cnt\n";
        // cout << "-------------------------------" << endl;
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