#include<bits/stdc++.h>
using namespace std;
const int SIZE_N = 1000005;
bool prime[SIZE_N];
void sieve(int n)
{
    //bool prime[n + 1];
    int total = 0;

    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p])
        {
            for (int i = p*p; i <= n; i += p)
            {
                prime[i] = false;
            }
        }
    }
}
int main()
{
    int n,total=0;

    cin >> n;

    sieve(n);

        for (int i = 2; i <= n; i++)
    {
        if (prime[i])
        {
            cout << i << " ";
            total++;
        }
    }

    cout << "\n"
         << total;

    return 0;
}
