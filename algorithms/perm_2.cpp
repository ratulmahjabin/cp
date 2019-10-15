#include <bits/stdc++.h>
using namespace std;
vector<int> perm;
int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        perm.push_back(i);

    do
    {
        for (int x : perm)
            cout << x << ",";
        cout << endl;
    } while (next_permutation(perm.begin(), perm.end()));

    return 0;
}