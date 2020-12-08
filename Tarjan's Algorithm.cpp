#include <bits/stdc++.h>
#define EPS 1e-9

using namespace std;

vector <vector<int>> adjList;
vector <int> dfs_num, dfs_low, s, visited;
int answer, timer;

void tarjan(int a)
{
    dfs_low[a] = dfs_num[a] = timer++;
    s.push_back(a);
    visited[a] = 1;

    for(int i = 0; i < adjList[a].size(); i++)
    {
        int temp = adjList[a][i];
        if(dfs_num[temp] == 0)
            tarjan(temp);
        if(visited[temp])
            dfs_low[a] = min(dfs_low[a], dfs_low[temp]);
    }

    if(dfs_low[a] == dfs_num[a])
    {
        answer++;
        cout << "SCC " << answer << " : ";
        while(true)
        {
            int temp = s.back();
            s.pop_back();
            visited[temp] = 0;
            cout << temp << " ";
            if(a == temp)
                break;
        }
        cout << endl;
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

    s.clear();
    visited.assign(many, 0);
    dfs_low.assign(many, 0);
    dfs_num.assign(many, 0);
    adjList.resize(many);
    timer = 1;
    answer = 0;
    adjList.clear();

    for(int i = 0; i < query; i++)
    {
        int a, b;
        cin >> a >> b;

        adjList[a].push_back(b);
    }

    for(int i = 0; i < many; i++)
        if(dfs_num[i] == 0)
            tarjan(i);

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << " ms\n";

    return 0;
}
