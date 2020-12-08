#include <bits/stdc++.h>

#define ll long long int
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define phi 3.1415926535
 
using namespace std;
 
ll tc, cnt = 0, number, many, total = 0;
int rmove[4] = {0, 0, -1, 1};
int cmove[4] = {1, -1, 0, 0};

ll EEA(ll a, ll b, ll &x, ll &y)
{
    ll xx = y = 0;
    ll yy = x = 1;

    while(b)
    {
        ll q = a / b;

        ll t = b;
        b = a % b;
        a = t;

        t = xx;
        xx = x - q * xx;
        x = t;

        t = yy;
        yy = y - q * yy;
        y = t;
    }
    return a;
}

ll modInvers(ll b, ll m)
{
    ll x, y;
    ll d = EEA(b, m, x, y);

    if(d != 1)
        return -1;
    return x % m;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    freopen("input.txt","r", stdin);
    freopen("output.txt","w", stdout);
    // g++ -std=c++11 Default.cpp  -o test

    

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << " ms\n";
    return 0;
}