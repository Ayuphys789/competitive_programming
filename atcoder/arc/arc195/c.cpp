/**
 * Author: Ayuphys
 * Problem Number: arc195-c
 * Title: Hamiltonian Pieces
 * Link to the Problem: https://atcoder.jp/contests/arc195/tasks/arc195_c
 * Link to the Submission: https://atcoder.jp/contests/arc195/submissions/64140765
 * Difficulty: ?
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int R, B;
    cin >> R >> B;
    int X = 300000;
    int Y = 300000;
    if (R % 2 == 1)
    {
        OUT("No");
        return;
    }
    if (R == 0)
    {
        if (B % 2 == 1)
        {
            OUT("No");
            return;
        }
        OUT("Yes");
        int N = B / 2;
        rep(i, N)
        {
            cout << "B " << X + i << " " << Y + i << endl;
        }
        rep(i, N)
        {
            cout << "B " << X + N - i << " " << Y + N - 2 - i << endl;
        }
        return;
    }
    if (B == 0)
    {
        OUT("Yes");
        int M = R / 2;
        rep(i, M)
        {
            cout << "R " << X + i << " " << Y << endl;
        }
        rep(i, M)
        {
            cout << "R " << X + M - 1 - i << " " << Y + 1 << endl;
        }
        return;
    }

    if (B % 2 == 0)
    {
        OUT("Yes");
        int N = B / 2;
        rep(i, N + 1)
        {
            cout << "B " << X + i << " " << Y + i << endl;
        }
        rep(i, N - 1)
        {
            cout << "B " << X + N + 1 - i << " " << Y + N - 1 - i << endl;
        }
        int M = R / 2;
        rep(i, M)
        {
            cout << "R " << X + 2 << " " << Y - i << endl;
        }
        rep(i, M)
        {
            cout << "R " << X + 1 << " " << Y - M + 1 + i << endl;
        }
        return;
    }

    if (B % 2 == 1)
    {
        OUT("Yes");
        int N = B / 2;
        rep(i, N + 1)
        {
            cout << "B " << X + i << " " << Y + i << endl;
        }
        rep(i, N)
        {
            cout << "B " << X + N + 1 - i << " " << Y + N - 1 - i << endl;
        }
        int M = R / 2;
        rep(i, M)
        {
            cout << "R " << X + 1 << " " << Y - 1 - i << endl;
        }
        rep(i, M)
        {
            cout << "R " << X << " " << Y - M + i << endl;
        }
        return;
    }
    EXIT_FAILURE;
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int testcase_num;
    cin >> testcase_num;

    rep(testcase, testcase_num)
    {
        Ayuphys_solve();
    }

    return 0;
}