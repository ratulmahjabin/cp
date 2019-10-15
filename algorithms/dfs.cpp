#include <bits/stdc++.h>
using namespace std;

int dist[2005];
const int N = 100005;
vector<int> V[N];
bool vis[N];

void dfs(int s)
{
    vis[s] = true;
    for (int x : V[s])
    {
        if (vis[x] == true)
            continue;
        dfs(x);
    }
}

int main()
{
    int node, edge;
    cin >> node;
    for (int i = 1; i < node; i++)
    {
        int u, v;
        cin >> u >> v;
        V[u].push_back(v);
        V[v].push_back(u);
    }

    dfs(1);
    int Q, x;
    cin >> Q;
    int a[Q + 1];
    int i = 1;
    while (Q--)
    {
        cin >> a[i];
        i++;
    }

    sort(a + 1, a + Q + 1);
    cout << a[1] << endl;

    return 0;
}
