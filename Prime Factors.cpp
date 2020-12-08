#include <bits/stdc++.h>
#include <math.h>
#define phi 3.14159265358979323846

using namespace std;

void primeFactors(int n)
{
    while (n % 2 == 0)
    {
        cout << 2 << " ";
        n = n/2;
    }

    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            cout << i << " ";
            n = n/i;
        }
    }

    if (n > 2)
        cout << n << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);

    int number;
    cin >> number;

    primeFactors(number);
}

