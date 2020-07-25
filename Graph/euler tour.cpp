#include <bits/stdc++.h>
using namespace std;

const int N = 100001;
vector<int>graph[N];
int visited[N];

void euler_tour_1(int src)
{
    visited[src] = true;
    cout << src << " ";

    for (auto i : graph[src])
    {
        if (!visited[i])
        {
            euler_tour_1(i);
            cout << src << " ";
        }
    }
}

void euler_tour_1_op(int src, int parent)
{
    cout << src << " ";

    for (auto i : graph[src])
    {
        if (i != parent)
        {
            euler_tour_1_op(i, src);
            cout << src << " ";
        }
    }
}

void euler_tour_2(int src)
{
    cout << src << " ";
    visited[src] = true;

    for (auto i : graph[src])
    {
        if (!visited[i])
        {
            euler_tour_2(i);
        }
    }
    cout << src << " ";
}

void euler_tour_2_op(int src, int parent)
{
    cout << src << " ";

    for (auto i : graph[src])
    {
        if (i != parent)
        {
            euler_tour_2_op(i, src);
        }
    }
    cout << src << " ";
}

void euler_tour_3(int src, int parent)
{
    cout << src << " ";

    for (auto i : graph[src])
    {
        if (i != parent)
        {
            euler_tour_3(i, src);
        }
    }

}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    // euler_tour_1(1);
    // cout<<endl;
    // euler_tour_1_op(1,0);
    // euler_tour_2(1);
    // cout<<endl;
    // euler_tour_2_op(1,0);
    euler_tour_3(1, 0);

}
