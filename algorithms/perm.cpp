#include <bits/stdc++.h>
using namespace std;
bool chosen[20];
vector<int> perm;
int n = 3;
void search()
{
    if (perm.size() == n)
    {
        for (int x : perm)
            cout << x << ",";
        cout << endl;
    }

    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (chosen[i])
                continue;
            chosen[i] = true;
            perm.push_back(i);
            search();
            chosen[i] = false;
            perm.pop_back();
        }
    }
}
int main()
{

    //cin >> n;

    search();
}