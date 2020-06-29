#include<bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;


int dx[] = { -1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
bool visited[2000][2000];
int a[2000][2000];
int n, m;
int hashmap[100000] = {0};

void dfs(int x, int y, int groupid)
{
	if (x < 0 || x >= n || y < 0 || y >= m || a[x][y] == 0 || visited[x][y])
		return;

	a[x][y] = groupid;
	visited[x][y] = true;
	hashmap[groupid]++;
	for (int i = 0; i < 4; i++)
	{
		int x1 = x + dx[i];
		int y1 = y + dy[i];
		dfs(x1, y1, groupid);
	}
}

int main()
{
	FAST_IO;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}
	int groupid = 0;
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] == 0)
				continue;
			if (!visited[i][j])
			{
				groupid++;
				dfs(i, j, groupid);
			}
		}
	}
	int ans = -1;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] == 0)
			{
				set<int> st;
				if (i - 1 >= 0)
					st.insert(a[i - 1][j]);
				if (i + 1 < n)
					st.insert(a[i + 1][j]);
				if (j - 1 >= 0)
					st.insert(a[i][j - 1]);
				if (j + 1 < m)
					st.insert(a[i][j + 1]);
				int sum = 0;
				for (auto x : st)
				{
					sum += hashmap[x];
				}
				ans = max(ans, sum + 1);
			}
		}
	}
	cout << ans;
}
