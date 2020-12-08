#include <bits/stdc++.h>
#define EPS 1e-9

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt","r", stdin);
    //freopen("output.txt","w", stdout);

    int many;
    while(cin >> many)
    {
        if(many == 0)
            break;

        vector < vector<int> > adjList;
        adjList.resize(many);

        int query;
        cin >> query;

        for(int i = 0; i < query; i++)
        {
            int a, b;
            cin >> a >> b;

            a--;
            b--;

            adjList[a].push_back(b);
            adjList[b].push_back(a);
        }

        bool condition = true;
        queue <int> que;
        vector <int> color(many, -1);

        for(int i = 0; i < many; i++)
        {
            if(color[i] == -1)
            {
                que.push(i);
                color[i] = 0;

                while(!que.empty())
                {
                    int now = que.front();
                    que.pop();

                    for(int j = 0; j < adjList[now].size(); j++)
                    {
                        int temp = adjList[now][j];
                        if(color[temp] == -1)
                        {
                            color[temp] = color[now] ^ 1;
                            que.push(temp);
                        }
                        else
                        {
                            if(color[temp] == color[now])
                            {
                                condition = false;
                                break;
                            }

                        }
                    }
                }
            }
        }
       for(int i = 0; i < color.size(); i++)
           cout << color[i] << " ";
       cout << endl;

        if(condition)
            cout << "BICOLORABLE.";
        else
            cout << "NOT BICOLORABLE.";
        cout << endl;
    }

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << " ms\n";
}

