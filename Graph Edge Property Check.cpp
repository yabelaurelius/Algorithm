#include <bits/stdc++.h>
#define EPS 1e-9

using namespace std;

vector <int> dfs_num, dfs_parent;
vector <vector<int>> adjList;
int many;

void graphCheck(int a)
{
    dfs_num[a] = 1;
    for(int i = 0; i < adjList[a].size(); i++)
    {
        int temp = adjList[a][i];
        if(dfs_num[temp] == 0)
        {
            dfs_parent[temp] = a;
            graphCheck(temp);
        }
        else if(dfs_num[temp] == 1)
        {
            if(temp == dfs_parent[a])
                cout << "Two Ways " << "(" <<  a << " " << temp << ")" << "-" << "(" <<  temp << " " << a << ")" << endl;
            else
                cout << "Back Edge (Cycle) " << "(" << a << " " << temp << ")" << endl;
        }
        else if(dfs_num[temp] == 2)
            cout << "Cross Edge / Forward Edge " << "(" << a << " " << temp << ")" << endl;
    }
    dfs_num[a] = 2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt","r", stdin);
    //freopen("output.txt","w", stdout);

    cin >> many;

    dfs_num.assign(many, 0);
    dfs_parent.assign(many, -1);
    adjList.resize(many);

    int a, b;
    while(cin >> a >> b)
    {
        if(a + b == 0)
            break;

        adjList[a].push_back(b);
    }

    for(int i = 0; i < many; i++)
    {
        if(dfs_num[i] == 0)
        {
            cout << "Componen " << i + 1 << " : " << endl;
            graphCheck(i);
        }
    }

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << " ms\n";
}
