#include <bits/stdc++.h>

#define ll long long int
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define phi 3.1415926535
 
using namespace std;
     
ll tc, cnt = 0, number, many, total = 0, query;
//vector <vector <int> > adjList;
int rmove[4] = {0, 0, -1, 1};
int cmove[4] = {1, -1, 0, 0};

ll power(ll x, ll y, ll mod)
{
    if(y == 0)
        return 1;
    else if(y % 2 == 0)
        return (power(x, y / 2, mod) % mod * power(x, y / 2, mod) % mod) % mod;
    else
        return x * (power(x, y / 2, mod) % mod * power(x, y / 2, mod) % mod) % mod;
}

ll arr[100000 + 5], ft[100000 + 5];

void buildFT()
{
    for(int i = 1; i <= many; i++)
    {
        for(int j = i; j <= many; j += (j & -j))
            ft[j] += arr[i];
    }
}

void updateFT(int a, ll value)
{
    ll temp = arr[a];
    arr[a] ^= value;
    temp = arr[a] - temp;

    for(int i = a; i <= many; i += (i & -i))
        ft[i] += temp;
}

ll queryFT(int a)
{
    ll sum = 0;
    for(int i = a; i >= 1; i -= (i & -i))
        sum += ft[i];

    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
        
    // freopen("input.txt","r", stdin);
    // freopen("output.txt","w", stdout);
    // g++ -std=c++11 Default.cpp  -o test  

    cin >> many >> number;

    memset(ft, 0, sizeof(ft));
    memset(arr, 0, sizeof(arr));

    for(int i = 1; i <= many; i++)
        cin >> arr[i];
    
    buildFT();

    // for(int i = 0; i <= many; i++)
    //     cout << ft[i] << " ";
    // cout << endl;

    while(number--)
    {
        ll a, b, c;
        cin >> a >> b >> c;

        if(a == 1)
        {
            updateFT(b, c);

            // for(int i = 0; i <= many; i++)
            //     cout << ft[i] << " ";
            // cout << endl;
        }
        else if(a == 2)
        {
            cout << queryFT(c) - queryFT(b - 1) << endl;
        }
    }

    // cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << " ms\n";    
    return 0;
    
}