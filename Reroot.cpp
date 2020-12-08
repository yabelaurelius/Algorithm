#include <bits/stdc++.h>
#define EPS 1e-9
#define ll long long int

using namespace std;

int tc;

ll arr[200000 + 5];
bool visited[200000 + 5];
vector <ll> sum;
vector < vector<int> > adjList;
ll highest = 0, answer = 0;


void dfs(int a, int depth)
{
    highest += (arr[a] * depth);
    visited[a] = true;
    sum[a] = arr[a];

    for(int i = 0; i < adjList[a].size(); i++)
    {
        int temp = adjList[a][i];
        if(!visited[temp])
        {
            dfs(temp, depth + 1);
            sum[a] += sum[temp];
        }
    }
}

void reroot(int a)
{
    visited[a] = true;
    answer = max(answer, highest);

    for(int i = 0; i < adjList[a].size(); i++)
    {
        int temp = adjList[a][i];
        if(!visited[temp])
        {
            highest -= sum[temp];
            sum[a] -= sum[temp];
            highest += sum[a]; 
            sum[temp] += sum[a];

            // cout << temp << " " << highest << endl;
            // for(int j = 0; j < sum.size(); j++)
            //     cout << sum[j] << " ";
            // cout << endl;
            reroot(temp);

            sum[temp] -= sum[a];
            highest -= sum[a];
            sum[a] += sum[temp];
            highest += sum[temp];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

//    freopen("input.txt","r", stdin);
//    freopen("output.txt","w", stdout);

    int many;
    cin >> many;

    for(int i = 0; i < many; i++)
        cin >> arr[i];

    memset(visited, false, sizeof(visited));
    sum.assign(many, 0);
    adjList.resize(many);

    for(int i = 0; i < many - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adjList[--a].push_back(--b);
        adjList[b].push_back(a);
    }

//    for(int i = 0; i < many; i++)
//    {
//        cout << i << " : ";
//        for(int j = 0; j < adjList[i].sBize(); j++)
//            cout << adjList[i][j] << " ";
//        cout << endl;
//    }

    dfs(0, 0);
    // cout << highest << endl;
    // for(int i = 0; i < sum.size(); i++)
    //     cout << sum[i] << " ";   
    // cout << endl;
    memset(visited, false, sizeof(visited));

    reroot(0);

    cout << answer << endl;

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << " ms\n";
    return 0;
}
