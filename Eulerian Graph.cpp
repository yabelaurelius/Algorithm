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

vector < vector<int> > adjList;
vector <int> euler;
int inDeg[30], outDeg[30];
int edge[30][30];
 
void HierholzerPath(int a)
{
    while(!adjList[a].empty())
    {
        int temp = adjList[a].back();
        adjList[a].pop_back();
        HierholzerPath(temp);
    }
 
    euler.pb(a);
}

void HierholzerCycle(int a)
{
    for(int i = 0; i < adjList[a].size(); i++)
    {
        int temp = adjList[a][i];
        if(edge[a][temp] > 0)
        {
            edge[a][temp]--;
            edge[temp][a]--;
            HierholzerCycle(temp);
            euler.pb(a);
        }
    }
}

void DirectedEulerianPath()
{
    bool condition = true;
    int in = -1, out = -1;
    for(int i = 0; i < many && condition; i++)
    {
        if(abs(inDeg[i] - outDeg[i]) > 1)
            condition = false;
 
        if(inDeg[i] - outDeg[i] == 1)
        {
            if(in == -1)
                in = i;
            else
                condition = false;
        }
        else if(outDeg[i] - inDeg[i] == 1)
        {
            if(out == -1)
                out = i;
            else
                condition = false;
        }
    }
 
    if(out == -1 && condition)
    {
        for(int i = 0; i < 26; i++)
        {
            if(outDeg[i])
            {
                out = i;
                break;
            }
        }
    }

    if(condition)
    {
        HierholzerPath(out);
        if(euler.size() != number + 1)
            cout << "Graph is not a Directed Eulerian Path";
        else
        {
            cout << "Graph is a Directed Eulerian Path" << '\n';
            reverse(euler.begin(), euler.end());
            for(int i = 0; i < euler.size(); i++)
                cout << euler[i] + 1 << " ";
        }
    }
    else
        cout << "Graph is not a Directed Eulerian Path";
    cout << '\n';
}

void UndirectedEulerianCycle()
{
    bool condition = true;
    int start = -1;
    for(int i = 0; i < many && condition; i++)
    {
        if(adjList[i].size() == 0)
            continue;

        if(adjList[i].size() % 2 != 0)
            condition = false;
        else
            start = i;
    }

    if(condition && start != -1)
    {
        euler.pb(start);
        HierholzerCycle(start);
        if(euler.size() != number + 1)
            cout << "Graph is not a Undirected Eulerian Cycle";
        else
        {
            cout << "Graph is a Undirected Eulerian Cycle";
            for(int i = 0; i < euler.size(); i++)
                cout << euler[i] + 1 << " ";
        }
            
    }
    else
        cout << "Graph is not a Undirected Eulerian Cycle";
    cout << '\n';
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

    adjList.resize(many);

    for(int i = 0; i < number; i++)
    {
        int a, b;
        cin >> a >> b;

        a--;
        b--;

        edge[a][b]++;
        adjList[a].pb(b);
        // Uncomment if undirected graph
        // adjList[b].pb(a);
    }

    

    // cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << " ms\n";    
    return 0;
    
}