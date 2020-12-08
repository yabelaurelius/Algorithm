#include <bits/stdc++.h>
#define EPS 1e-9

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt","r", stdin);
    freopen("output.txt","w", stdout);

    int many, query;
    cin >> many >> query;

    vector <vector<int>> adjList;
    int degree[many] = {};
    adjList.resize(many);

    while(query--)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        degree[b]++;
        adjList[a].push_back(b);
    }

    queue <int> que;
    vector <int> answer;

    for(int i = 0; i < many; i++)
    {
        if(degree[i] == 0)
            que.push(i);
    }

    while(!que.empty())
    {
        int a = que.front();
        que.pop();
        answer.push_back(a);

        for(int i = 0; i < adjList[a].size(); i++)
        {
            int temp = adjList[a][i];
            degree[temp]--;
            if(degree[temp] == 0)
                que.push(temp);
        }
    }

    for(int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] + 1;
        if(i != answer.size()-1)
            cout << " ";
    }
    cout << endl;

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << " ms\n";
}

