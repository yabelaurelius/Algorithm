#include <bits/stdc++.h>

using namespace std;

bitset <150005> visited;
vector <vector<int>> adjList;

void dfs(int u)
{
    visited[u] = 1;
    for (int i = 0; i < adjList[u].size(); i++)
    {
        if (!visited[adjList[u][i]])
            dfs(adjList[u][i]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int number, a, b;
    cout << "Number of node ";
    cin >> number;

    vector <int> vec[number+1];
    while(cin >> a >> b)
    {
        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    for(int i = 0; i < number; i++)
    {
        cout << i << " : ";
        for(int j = 0; j < vec[i].size(); j++)
            cout << vec[i][j] << " ";
        cout << endl;
    }

    bool flag[number];
    memset(flag, 0, number);
    queue <int> que;

    int tree = 0;
    for(int i = 0; i < number; i++)
    {
        int temp = 0;
        if(flag[i] == false)
        {
            que.push(i);
            flag[i] = true;
            temp++;
            while(!que.empty())
            {
                int now = que.top();
                que.pop();
                for(int j = 0; j < vec[now].size(); j++)
                {
                    if(flag[vec[now][j]] == false)
                    {
                        que.push(vec[now][j]);
                        flag[vec[now][j]] = true;
                        temp++;
                    }
                }
            }
        }
        if(temp > 1)
            tree++;
    }
    cout << "You have " << tree << " tree." << endl;
}
