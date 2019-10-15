#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int tree[4 * N + 1];
int a[N + 1];

void build(int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = a[start];
    }

    else
    {
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }
}

void update(int node, int start, int end, int idx, int val)
{
    /* if (start == end)
    {
        a[idx] = val;
        tree[node] = val;
    }

    else
    {
        int mid = (start + end) / 2;
        update(2 * node, start, mid, idx, val);
        update(2 * node + 1, mid + 1, end, idx, val);
        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }*/

    if (start == end)
    {
        a[idx] = val;
        tree[node] = val;
    }
    else
    {
        int mid = (start + end) / 2;
        if (idx >= start && idx <= mid)
            update(2 * node, start, mid, idx, val);
        else
            update(2 * node + 1, mid + 1, end, idx, val);
        if (tree[2 * node] < tree[2 * node + 1])
            tree[node] = tree[2 * node];
        else
            tree[node] = tree[2 * node + 1];
    }
}

int query(int node, int start, int end, int l, int r)
{
    if (r < start or l > end)
        return INT_MAX;
    if (l <= start and r >= end)
        return tree[node];

    int mid = (start + end) / 2;
    int p1 = query(2 * node, start, mid, l, r);
    int p2 = query(2 * node + 1, mid + 1, end, l, r);
    return min(p1, p2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, Q;
    cin >> N >> Q;

    for (int i = 1; i <= N; i++)
        cin >> a[i];

    build(1, 1, N);

    //cout << endl;

    while (Q--)
    {
        char ch;
        int x, y;
        cin >> ch >> x >> y;
        if (ch == 'q')
        {
            cout << query(1, 1, N, x, y) << endl;
        }

        else
        {
            update(1, 1, N, x, y);
        }
    }

    return 0;
}
