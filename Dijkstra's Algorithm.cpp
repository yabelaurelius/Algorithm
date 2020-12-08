#include <bits/stdc++.h>

#define ll long long int
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define phi 3.1415926535
 
using namespace std;

const ll mod = 1000000007;    

ll tc, cnt = 0, number, many, total = 0, query;
// vector <vector <int> > adjList;
int rmove[8] = {0, 0, -1, 1, -1, 1, -1, 1};
int cmove[8] = {1, -1, 0, 0, 1, -1, -1, 1};

ll power(ll x, ll y, ll mod)
{
    if(y == 0)
        return 1;
    else if(y % 2 == 0)
        return (power(x, y / 2, mod) % mod * power(x, y / 2, mod) % mod) % mod;
    else
        return x * (power(x, y / 2, mod) % mod * power(x, y / 2, mod) % mod) % mod;
}

vector < vector < pair<int, int> > > adjList;
vector <ll> dist;

void Dijkstra(int start)
{
    priority_queue < vector<ll>, vector <pair <ll,ll> >, greater <pair <ll,ll> > > pq;
    set < pair<ll, ll> > sethcurry;

    dist[start] = 0;
    pq.push(make_pair(dist[start], start));
    while(!pq.empty())
    {
        if(sethcurry.count(pq.top()))
        {
            sethcurry.erase(pq.top());
            pq.pop();
            continue;
        }

        ll a = pq.top().fi, b = pq.top().se;
        pq.pop();

        for(int i = 0; i < adjList[b].size(); i++)
        {
            ll c = adjList[b][i].fi;
            ll d = adjList[b][i].se;
            if(a + d < dist[c])
            {
                sethcurry.insert(mp(dist[c], c));
                dist[c] = a + d;
                pq.push(make_pair(dist[c], c));
            }
        }
    }

    return ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
        
    // freopen("input.txt","r", stdin);
    // freopen("output.txt","w", stdout);
    // g++ -std=c++11 Default.cpp  -o test  
    // g++ -Wl,--stack=268435456 -std=c++11 Default.cpp  -o test

    cin >> many >> number;

    adjList.clear();
    dist.clear();

    dist.assign(many, 1e18);
    adjList.resize(many);

    for(int i = 0; i < number; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        a--;
        b--;

        adjList[a].pb(mp(b, c));
        // adjList[b].pb(mp(a, c));
    }

    dijkstra(0);

    for(int i = 0; i < many; i++)
        cout << dist[i] << " ";
    cout << endl;

    // cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << " ms\n";    
    return 0;
    
}