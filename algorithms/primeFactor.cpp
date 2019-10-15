#include <bits/stdc++.h>
using namespace std;
vector<int> v;
long long factorPrime(int n)
{
    long long s = 0;
    while (n % 2 == 0)
    {
        s += 2;
        n /= 2;
    }

    for (int i = 3; i <= sqrt(n); i++)
    {
        while (n % i == 0)
        {
            s += i;
            n /= i;
        }
    }

    if (n > 2)
        s += n;
}
int main()
{
    int x;

    cin >> x;
    cout << factorPrime(x) << endl;

    return 0;
}
