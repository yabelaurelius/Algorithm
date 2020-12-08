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

vector< vector <pair<int, int> > > adjList;
vector <int> dist;

void BellmanFord(int start)
{
    dist[start] = 0;

    for(int i = 0; i < many - 1; i++)
    {
        bool condition = false;
        for(int j = 0; j < many; j++)
        {
            if(dist[j] == 1e9)
                continue;

            for(int k = 0; k < adjList[j].size(); k++)
            {
                pair <int, int> temp = adjList[j][k];
                if(dist[j] + temp.se < dist[temp.fi])
                {
                    dist[temp.fi] = dist[j] + temp.se;
                    condition = true;
                }
            }
        }

        if(!condition)
            break;
    }

    bool negativeCycle = false;
    for(int i = 0; i < many; i++)
    {
        if(dist[i] == 1e9)
            continue;

        for(int j = 0; j < adjList[i].size(); j++)
        {
            pair <int,int> temp = adjList[i][j];
            if(dist[i] + temp.se < dist[temp.fi])
                negativeCycle = true;
        }
    }
}

void BellmanFordMoore(int start)
{
    dist[start] = 0;

    queue <int> que;
    vector <int> optimal;

    que.push(start);
    optimal.assign(many, 0);

    while(!que.empty())
    {
        int now = que.front();
        optimal[now] = 0;
        que.pop();

        for(int i = 0; i < adjList[now].size(); i++)
        {
            pair <int, int> temp = adjList[now][i];
            if(dist[now] + temp.se < dist[temp.fi])
                dist[temp.fi] = dist[now] + temp.se;

            if(!optimal[temp.fi])
            {
                que.push(temp.fi);
                optimal[temp.fi] = 1;
            }
        }
    }
}

int main()
{
    fastio();
        
    // freopen("input.txt","r", stdin);
    // freopen("output.txt","w", stdout);
    // g++ -std=c++11 Default.cpp  -o test
    // g++ -Wl,--stack=268435456 -std=c++11 Default.cpp  -o test


    dist.resize(201);
    adjList.resize(201);
    vec.resize(201);

    while(cin >> many)
    {
        for(int i = 0; i <= many; i++)
        {
            dist[i] = 1e9;
            adjList[i].clear();
        }

        for(int i = 0; i < many; i++)
            cin >> vec[i];

        cin >> number;

        for(int i = 0; i < number; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;

            a--;
            b--;

            adjList[a].pb(mp(b, c));
        }

        bellmanFord(0);

        // for(int i = 0; i < many; i++)
        //     cout << dist[i] << " ";
        // cout << '\n';
    }


    //
    return 0;
}