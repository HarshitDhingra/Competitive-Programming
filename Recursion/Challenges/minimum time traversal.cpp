#include <bits/stdc++.h>
using namespace std;

int ans;

void rec(int sr, int sc, int dr, int dc, vector<vector<int>>&pipes, int i, int n, int cost, int visited[])
{
    ans = min(ans, cost + abs(dr - sr) + abs(dc - sc));

    for (int k = 0; k < n; k++) {
        if (!visited[k])
        {
            visited[k] = 1;
            //go from start to end of the pipe
            rec(pipes[k][2], pipes[k][3], dr, dc, pipes, i + 1, n, cost + abs(pipes[k][0] - sr) + abs(pipes[k][1] - sc) + pipes[k][4], visited);
            //go from end to start of the pipe
            rec(pipes[k][0], pipes[k][1], dr, dc, pipes, i + 1, n, cost + abs(pipes[k][2] - sr) + abs(pipes[k][3] - sc) + pipes[k][4], visited);

            visited[k] = 0;
        }
    }

    return ;
}

int main() {
    int t;
    cin >> t;
    int c = 1;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>>pipes(n);
        int visited[10] = {0};
        int sr, sc, dr, dc;
        cin >> sr >> sc >> dr >> dc;
        for (int i = 0; i < n; i++)
        {
            int psr, psc, pdr, pdc, pcost;
            cin >> psr >> psc >> pdr >> pdc >> pcost;
            pipes[i] = {psr, psc, pdr, pdc, pcost};
        }
        ans = abs(dr - sr) + abs(dc - sc);
        rec(sr, sc, dr, dc, pipes, 0, n, 0, visited);
        cout << "#" << c << " : " << ans << endl;
        c++;
    }
}
