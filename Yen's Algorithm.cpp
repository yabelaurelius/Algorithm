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

ll tc, cnt = 0, number, many, total = 0, query, require, length, row, column;
string str;
int rmove[8] = {1, 0, 0, -1, -1, 1, -1, 1};
int cmove[8] = {0, -1, 1, 0, 1, -1, -1, 1};

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

vector < vector < pair<int, int> > > adjList;
vector <ll> dist[105];

void Yen(int start, int last)
{
    for(int i = 0; i < 100; i++)
        dist[i].clear();

    priority_queue < vector<ll>, vector <pair <ll,ll> >, greater <pair <ll,ll> > > pq;
    ll now = 0;

    pq.push(mp(now, start));
    while(!pq.empty())
    {
        ll a = pq.top().fi, b = pq.top().se;
        pq.pop();

        if(dist[b].size() == 0)
            dist[b].pb(a);
        else if(dist[b].back() != a)
            dist[b].pb(a);

        if(dist[b].size() > 2)
            continue;

        for(int i = 0; i < adjList[b].size(); i++)
        {
            ll c = adjList[b][i].fi;
            ll d = adjList[b][i].se;

            if(dist[c].size() == 2)
                continue;

            now = d + a;
            pq.push(mp(now, c));
        }
    }

    if(dist[last].size() < 2)
        cout << "?";
    else
        cout << dist[last][1];
    cout << '\n';

    return ;
}

int main()
{
    fastio();
        
    // freopen("input.txt","r", stdin);
    // freopen("output.txt","w", stdout);
    // g++ -std=c++11 Default.cpp  -o test
    // g++ -Wl,--stack=268435456 -std=c++11 Default.cpp  -o test

    //https://codeforces.com/blog/entry/16821
    adjList.resize(100);

    while(cin >> many >> number)
    {
        for(int i = 0; i < 100; i++)
            adjList[i].clear();

        for(int i = 0; i < number; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;

            adjList[a].pb(mp(b, c));
            adjList[b].pb(mp(a, c));
        }

        cin >> query;

        cout << "Set #" << ++cnt << '\n';
        while(query--)
        {
            int a, b;
            cin >> a >> b;

            Dijkstra(a, b);
        }
    }

    //
    return 0;
}
