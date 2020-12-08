#include <bits/stdc++.h>
#define EPS 1e-9

using namespace std;

int answer = 0, start, last;
vector <int> visited, parent;
queue <int> que;
vector <vector<int>> adjList;

void bfs()
{
    que.push(start);
    visited[start] = 1;
    while(!que.empty())
    {
        int now = que.front();
        que.pop();
        //cout << now << " " << vec[now] << endl;

        for(int i = 0; i < adjList[now].size(); i++)
        {
            int temp = adjList[now][i];
            if(!visited[temp])
            {
                visited[temp] = 1;
                parent[temp] = now;
                que.push(temp);
            }
        }
    }
}

void printPath(int a)
{
    if(a != last)
        answer++;
    if(a == start)
    {
        //cout << start;
        return;
    }
    printPath(parent[a]);
    //cout << " " << a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt","r", stdin);
    //freopen("output.txt","w", stdout);

    int number;
    cin >> number;

    for(int i = 0; i < number; i++)
    {
        int many, query;
        cin >> many >> query;

        adjList.clear();
        adjList.resize(many);

        while(query--)
        {
            int a, b;
            cin >> a >> b;

            adjList[a].push_back(b);
            adjList[b].push_back(a);
        }

        parent.assign(many, -1);
        visited.assign(many, 0);

        cin >> start >> last;

        bfs();
        printPath(mapping[b]);
        cout << a << " " << b << " " << answer << endl;
    }

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << " ms\n";
}
