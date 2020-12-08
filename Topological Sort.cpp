#include <bits/stdc++.h>
#define EPS 1e-9

using namespace std;

vector <vector<int>> adjList;
vector <bool> flag;
vector <int> answer;

void ts_dfs(int v)
{
    flag[v] = true;
    for(int i = 0; i < adjList[v].size(); i++)
    {
        if(!flag[adjList[v][i]])
            dfs(adjList[v][i]);
    }
    answer.push_back(v);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt","r", stdin);
    freopen("output.txt","w", stdout);

    int many, query;
    while(cin >> many >> query)
    {
        if(many + query == 0)
            break;

        adjList.clear();
        adjList.resize(many);
        flag.assign(many, false);
        answer.clear();

        while(query--)
        {
            int a, b;
            cin >> a >> b;
            a--;
            b--;

            adjList[a].push_back(b);
        }

        for(int i = 0; i < many; i++)
        {
            if(flag[i] == false)
                dfs(i);
        }

        reverse(answer.begin(), answer.end());
        for(int i = 0; i < answer.size(); i++)
        {
            cout << answer[i] + 1;
            if(i != answer.size()-1)
                cout << " ";
            else
                cout << endl;
        }

    }

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << " ms\n";
}

