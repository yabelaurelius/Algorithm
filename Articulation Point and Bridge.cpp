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

ll tc, cnt = 0, number, many, total = 0, query, require, length;
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

vector <int> low, num, parent;
vector <bool> articulation;
vector < vector <int> > adjList;
int timer, dfsRoot, rootChildren;

void Bridge(int a)
{
    low[a] = num[a] = timer++;
    for(int i = 0; i < adjList[a].size(); i++)
    {
        int temp = adjList[a][i];
        if(num[temp] == 0)
        {
            parent[temp] = a;
            if(a == dfsRoot)
                rootChildren++;

            Bridge(temp);

            if(low[temp] >= num[a])
                articulation[a] = true;

            if(low[temp] > num[a])
                cout << "Edge (" << a << " " << temp << ") is a bridge." << endl;

            low[a] = min(low[a], low[temp]);

        }
        else if(temp != parent[a])
            low[a] = min(low[a], num[temp]);
    }
}

int main()
{
    fastio();
        
    // freopen("input.txt","r", stdin);
    // freopen("output.txt","w", stdout);
    // g++ -std=c++11 Default.cpp  -o test
    // g++ -Wl,--stack=268435456 -std=c++11 Default.cpp  -o test

    cin >> many >> number;

    num.resize(1000);
    low.resize(1000);
    articulation.resize(1000);
    adjList.resize(1000);
    parent.resize(1000);
    
    timer = 1;
    for(int i = 0; i < many; i++)
    {
        num[i] = 0;
        low[i] = 0;
        articulation[i] = 0;
        adjList[i].clear();
        parent[i] = -1;
    }

    for(int i = 0; i < number; i++)
    {
        int a, b;
        cin >> a >> b;

        a--;
        b--;

        adjList[a].pb(b);
        adjList[b].pb(a);
    }

    cout << "Bridges :" << endl;
    for(int i = 0; i < many; i++)
    {
        if(num[i] == 0)
        {
            dfsRoot = i;
            rootChildren = 0;
            Bridge(i);
            if(rootChildren > 1)
                articulation[dfsRoot] = true;
            else
                articulation[dfsRoot] = false;
        }
    }

    cout << "Articulation Points :" << endl;
    for(int i = 0; i < many; i++)
    {
        if(articulation[i])
            cout << "Vertex " << i << endl;
    }
    
    //
    return 0;
}