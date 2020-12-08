#include <bits/stdc++.h>
#define EPS 1e-9

using namespace std;

int visited[100][100];
int rmove[8] = {0,0,1,1,-1,-1,0,1};
int cmove[8] = {1,-1,0,1,-1,1,1,1};
int row, column, odd = 0, even = 0;

void dfs(int r, int c)
{
    visited[r][c] = 1;
    for (int i = 0; i < 8; i++)
    {
        int a = r + rmove[i], b = c + cmove[i];
        if(a >= row || b >= column || a < 0 || b < 0 || visited[a][b] == -1)
            continue;

        if(visited[a][b] == 0)
            dfs(a, b);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt","r", stdin);
    //freopen("output.txt","w", stdout);

    int row, column;
    while(cin >> row >> column)
    {
        if(row + column == 0)
            break;

        memset(visited, false, sizeof(visited));

        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < column; j++)
            {
                char temp;
                cin >> temp;
                if(temp == '@')
                    visited[i][j] = 0;
                else
                    visited[i][j] = -1;
            }
        }



        dfs(0,0);
    }

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << " ms\n";
}
