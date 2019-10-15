#include<bits/stdc++.h>
using namespace std;

const long long SIZE_N = 100000005;
bool prime[SIZE_N];
void sieve()
{
    //bool prime[n + 1];
    //int total = 0;

    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= SIZE_N; p++)
    {
        if (prime[p])
        {
            for (int i = p*p; i <= SIZE_N; i += p)
            {
                prime[i] = false;
            }
        }
    }
}

void NOD(int N)
{
    int val = sqrt(N)+1;
    int sum=1;
    for(int i=2; prime[i]==true and i<val; i++)
    {
        if(N % i == 0)
        {
            int cnt =0;

            while(N % i ==0)
            {
                N/= i;
                cnt++;
            }

            sum *= (cnt+1);
        }
    }


    if(N > 1) sum *=2;

    cout<< sum <<endl;
}
int main()
{
    int n;

    cin >> n;

    sieve();
    NOD(n);
//    int ans = NOD(n);
    //cout<<ans;    return 0;
}
