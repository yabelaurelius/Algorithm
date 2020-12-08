#include <bits/stdc++.h>
#include <iostream>
#include <string>

#define ll long long int
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define phi 3.1415926535
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
 
using namespace std;

const ll mod = 1000000007;    

ll tc, cnt = 0, number, many, total = 0, query;
vector <vector <int> > adjList;
int rmove[8] = {-1, 0, 1, 0, -1, 1, -1, 1};
int cmove[8] = {0, 1, 0, -1, 1, -1, -1, 1};

ll power(ll x, ll y, ll mod)
{
    if(y == 0)
        return 1;
    else if(y % 2 == 0)
        return (power(x, y / 2, mod) % mod * power(x, y / 2, mod) % mod) % mod;
    else
        return x * (power(x, y / 2, mod) % mod * power(x, y / 2, mod) % mod) % mod;
}

int subtree[100000 + 5], parent[100000 + 5];
vector <int> vec;
int root;

void dfs(int a, int p)
{
    parent[a] = p;
    subtree[a] = 1;

    bool centroid = true;
    for(int i = 0; i < adjList[a].size(); i++)
    {
        int temp = adjList[a][i];
        if(temp == p)
            continue;
        
        dfs(temp, a);
        subtree[a] += subtree[temp];
        if(subtree[temp] > many / 2)
            centroid = false;
    }

    if(many - subtree[a] > many / 2)
        centroid = false;

    if(centroid)
        vec.pb(a);
}

int main()
{
    fastio();
        
    // freopen("input.txt","r", stdin);
    // freopen("output.txt","w", stdout);
    // g++ -std=c++11 Default.cpp  -o test
    // g++ -Wl,--stack=268435456 -std=c++11 Default.cpp  -o test
    
    cin >> many;

    vec.clear();
    adjList.clear();
    memset(subtree, 0, sizeof(subtree));
    memset(parent, -1, sizeof(parent));
    root = -1;

    adjList.resize(many);

    for(int i = 1; i < many; i++)
    {
        int a, b;
        cin >> a >> b;

        a--;
        b--;

        adjList[a].pb(b);
        adjList[b].pb(a);
    }

    dfs(0, -1);

    // for(int i = 0; i < many; i++)
    //     cout << subtree[i] << " ";
    // cout << endl;

    // for(int i = 0; i < vec.size(); i++)
    //     cout << vec[i] << " ";
    // cout << endl;

    // for(int i = 0; i < many; i++)
    //     cout << parent[i] << " ";
    // cout << endl;

    // cout << vec.size() << endl;

    cout << "Centroid : ";
    for(int i = 0; i < vec.size(); i++)
        cout << vec[i] + 1 << " ";
    cout << endl;

    //
    return 0;
}