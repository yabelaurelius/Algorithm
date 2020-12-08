#include <bits/stdc++.h>

#define ll long long int
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define phi 3.1415926535
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
using namespace std;

const ll mod = 1000000007;    

ll tc, cnt = 0, number, many, total = 0, query, require;
int rmove[8] = {1, 0, -1, 0, -1, 1, -1, 1};
int cmove[8] = {0, 1, 0, -1, 1, -1, -1, 1};

ll modpow(ll x, ll y, ll m)
{
    ll res = 1;
    while(y > 0)
    {
        if(y & 1)
            res = (res * x) % m;
        x = (x * x) % m;
        y >>= 1;
    }

    return res;
}

ll dist[505][505], path[505][505];

void FloydWarshall()
{
    for(int i = 0; i < many; i++)
    {
        for(int j = 0; j < many; j++)
        {
            for(int k = 0; k < many; k++)
            {
                // dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
                if(dist[j][i] + dist[i][k] < dist[j][k])
                {
                    dist[j][k] = dist[j][i] + dist[i][k];
                    // path[j][k] = path[i][k];
                }
            }
        }
    }           
}

void printPath(int a, int b)
{   
    if(path[a][b] == a)
        return ;
    
    printPath(a, path[a][b]);
    cout << " " << path[a][b] + 1;
}

int main()
{
    fastio();
        
    // freopen("input.txt","r", stdin);
    // freopen("output.txt","w", stdout);
    // g++ -std=c++11 Default.cpp  -o test
    // g++ -Wl,--stack=268435456 -std=c++11 Default.cpp  -o test

    cin >> many >> number >> query;

    for(int i = 0; i < many; i++)
    {
        for(int j = 0; j < many; j++)
        {
            dist[i][j] = 1e18;
            path[i][j] = i;
        }
        dist[i][i] = 0;
        path[i][i] = -1;
    }

    for(int i = 0; i < number; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;

        dist[a - 1][b - 1] = c;
        dist[b - 1][a - 1] = c;
    }
    
    FloydWarshall();

    // for(int i = 0; i < many; i++)
    // {
    //     for(int j = 0; j < many; j++)
    //         cout << dist[i][j] << " ";
    //     cout << '\n';
    // }
    // cout << '\n';

    while(query--)
    {
        int a, b;
        cin >> a >> b;


        if(dist[a - 1][b - 1] != 1e18)
            cout << dist[a - 1][b - 1];
        else
            cout << -1;
        cout << '\n';

        cout << a;
        printPath(a - 1, b - 1);
        cout << " " << b - 1 << '\n';
    }

    //
    return 0;
}