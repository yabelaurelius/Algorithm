#include <bits/stdc++.h>

using namespace std;

ll lcm(ll a, ll b)
{
    return (a * b) / __gcd(a, b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    long long int a, b;
    cin >> a >> b;

    a = factorial(a);
    b = factorial(b);

    cout << a << " " << b << endl;
    if(b > a)
        swap(a,b);

    cout << gcd(a,b);
}
