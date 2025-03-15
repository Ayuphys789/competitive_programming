/**
 * Author: Ayuphys
 * Problem Number: abc384-e
 * Title: Takahashi is Slime 2
 * Link to the Problem: https://atcoder.jp/contests/abc384/tasks/abc384_e
 * Link to the Submission: https://atcoder.jp/contests/abc384/submissions/63747923
 * Difficulty: 1002
 */

#include "/home/ayuphys789/competitive_programming/template/template.hpp"

void Ayuphys_solve(void)
{
    int H, W;
    cin >> H >> W;
    ll X;
    cin >> X;
    int P, Q;
    cin >> P >> Q;
    --P;
    --Q;
    vector<vector<ll>> S(H, vector<ll>(W));
    rep(i, H)
    {
        rep(j, W)
        {
            cin >> S[i][j];
        }
    }

    ll Tak = S[P][Q];
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> PQ;
    vector<vector<bool>> used(H, vector<bool>(W));
    used[P][Q] = 1;
    rep(k, 4)
    {
        int nx = P + dx[k];
        int ny = Q + dy[k];
        if (nx < 0 || nx >= H || ny < 0 || ny >= W)
        {
            continue;
        }
        PQ.push(make_pair(S[nx][ny], nx * W + ny));
        used[nx][ny] = 1;
    }
    while (!PQ.empty())
    {
        auto pr = PQ.top();
        PQ.pop();
        ll R = pr.first;
        int x = pr.second / W;
        int y = pr.second % W;
        // SOUT(R);
        // SOUT(x);
        // OUT(y);
        if (R <= (ll)((Tak - 1) / X))
        {
            Tak += R;
            rep(k, 4)
            {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (nx < 0 || nx >= H || ny < 0 || ny >= W)
                {
                    continue;
                }
                if (!used[nx][ny])
                {
                    PQ.push(make_pair(S[nx][ny], nx * W + ny));
                    used[nx][ny] = 1;
                }
            }
            // OUT(Tak);
        }
        else
        {
            break;
        }
    }
    // VVOUT(used);
    OUT(Tak);
    return;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    Ayuphys_solve();

    return 0;
}