#include <bits/stdc++.h>

using namespace std;

long long int gcd(long long int a,long long int b)
{
    if(b == 0)
        return a;
    return gcd(b, a%b);
}

long long int lcm(long long int a, long long int b)
{
    if(a == 0)
        return b;
    return gcd(b % a, a);
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


    cout << a << " " << b << endl;
    if(b > a)
        swap(a,b);

    cout << gcd(a,b);
}
