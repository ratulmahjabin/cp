#include <bits/stdc++.h>
using namespace std;
int cnt[32], c;
void decToBinary(int n)
{

    int binaryNum[32];

    int i = 0;
    while (n > 0)
    {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
    c = 0;
    for (int j = i - 1; j >= 0; j--)
    {
        cnt[c] = binaryNum[j];
        c++;
    }
}
int main()
{
    int n, p, m, x = 1, power;
    cin >> n >> p >> m;

    decToBinary(p);

    power = n % m;
    for (int i = 0; i < c; i++)
    {
        if (i == 0)
        {
            power = (power * power) % m;
        }
        if (cnt[i] == 1 and i != 0)
        {
            x = x * power;
            power = (power * power) % m;
        }

        else
        {
            x = x;
            power = (power * power) % m;
        }
    }
    cout << x << endl;
    return 0;
}