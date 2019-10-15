#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
ll SIZE;
bitset<10000010> bs;
vi primes;

void sieve(ll upperbound)
{
    SIZE = upperbound + 1;
    bs.set(); //set all bits to 1

    bs[0] = bs[1] = 0;

    for (ll i = 2; i <= SIZE; i++)
    {
        if (bs[i])
        {
            for (ll j = i * i; j <= SIZE; j += i)
                bs[j] = 0;
        }
        primes.push_back(int(i));
    }
}

bool isPrime(ll N)
{
    if (N <= SIZE)
        return bs[N];

    for (int i = 0; i < primes.size(); i++)
        if (N % primes[i] == 0)
            return false;

    return true;
}

vi primeFactors(ll N)
{
    vi factors;

    ll PF_idx = 0, PF = primes[PF_idx];

    while (PF * PF <= N)
    {
        while (N % PF == 0)
        {
            N /= PF;
            factors.push_back(PF);
        }

        PF = primes[++PF_idx];
    }

    if (N != 1)
        factors.push_back(N);
    return factors;
}

ll numPF(ll N)
{
    //vi factors;

    ll PF_idx = 0, PF = primes[PF_idx];
    ll ans = 0;
    while (PF * PF <= N)
    {
        while (N % PF == 0)
        {
            N /= PF;
            ans++;
        }

        PF = primes[++PF_idx];
    }

    if (N != 1)
        ans++;
    return ans;
}

ll numDiv(ll N)
{
    //vi factors;

    ll PF_idx = 0, PF = primes[PF_idx];
    ll ans = 1;
    while (PF * PF <= N)
    {
        ll power = 0;
        while (N % PF == 0)
        {
            N /= PF;
            power++;
        }
        ans *= (power + 1);
        PF = primes[++PF_idx];
    }

    if (N != 1)
        ans *= 2;
    return ans;
}

ll sumDiv(ll N)
{
    //vi factors;

    ll PF_idx = 0, PF = primes[PF_idx];
    ll ans = 1;
    while (PF * PF <= N)
    {
        ll power = 0;
        while (N % PF == 0)
        {
            N /= PF;
            power++;
        }
        ans *= ((ll)(pow((double)PF, power + 1.0 - 1)) - 1) / (N - 1);
        PF = primes[++PF_idx];
    }

    if (N != 1)
        ans *= ((ll)pow((double)N, 2.0) - 1) / (N - 1);
    return ans;
}

ll eulerPhi(ll N)
{
    //vi factors;

    ll PF_idx = 0, PF = primes[PF_idx];
    ll ans = N;
    while (PF * PF <= N)
    {
        if (N % PF == 0)
        {
            N /= PF;
            ans -= ans / N;
        }

        while (N % PF == 0)
            N /= PF;

        PF = primes[++PF_idx];
    }

    if (N != 1)
        ans -= ans / N;
    return ans;
}

int main()
{

        sieve(10000000); //can go up to 10^7 (needs few sec)
    /* int n;
    cin >> n;

    while (n--)
    {
        int x;
        cin >> x;
        if (isPrime(x))
            cout << "Prime" << endl;
        else
            cout << "Non Prime" << endl;
    } */
    ll n;
    cin >> n;
    vi r = primeFactors(n * 1LL);
    for (vi::iterator i = r.begin(); i != r.end(); i++)
    {
        printf("! %d\n", *i);
    }
    return 0;
}