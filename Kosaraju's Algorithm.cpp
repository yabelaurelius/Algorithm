#include <bits/stdc++.h>
#define EPS 1e-9

using namespace std;

vector <vector<int>> adjList1, adjList2;
vector <bool> visited;
vector <int> order, component;
int many, query;

void dfs1(int a)
{
    visited[a] = true;
    for(int i = 0; i < adjList1[a].size(); i++)
    {
        int temp = adjList1[a][i];
        if(visited[temp] == 0)
            dfs1(temp);
    }
    order.push_back(a);
}

void dfs2(int a)
{
    visited[a] = true;
    component.push_back(a);
    for(int i = 0; i < adjList2[a].size(); i++)
    {
        int temp = adjList2[a][i];
        if(visited[temp] == 0)
            dfs2(temp);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.txt","r", stdin);
    // freopen("output.txt","w", stdout);

    int many, query;
    cin >> many >> query;

    adjList1.clear();
    adjList2.clear();
    adjList1.resize(many);
    adjList2.resize(many);
    visited.assign(many , 0);
    order.clear();

    for(int i = 0; i < query; i++)
    {
        int a, b;
        cin >> a >> b;
        adjList1[a].pb(b);
        adjList2[b].pb(a);
    }

    for(int i = 0; i < many; i++)
    {
        if(!visited[i])
            dfs1(i);
    }

    visited.assign(many, 0);
    for(int i = 0; i < many; i++)
    {
        int temp = order[many - 1 - i];
        if(visited[temp] == 0)
        {
            dfs2(temp);
            for(int j = 0; j < component.size(); j++)
                cout << component[j] << " ";
            component.clear();
        }
    }

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << " ms\n";
}
