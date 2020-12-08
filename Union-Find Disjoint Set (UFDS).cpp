#include <bits/stdc++.h>

using namespace std;

vector <int> parent, sizes;

void make_set(int v)
{
    parent[v] = v;
    sizes[v] = 1;
}

int find_set(int v)
{
    if(v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if(a != b)
    {
        if(sizes[a] < sizes[b])
            swap(a,b);
        parent[b] = a;
        if(sizes[a] == sizes[b])//Depth
            sizes[a]++;
        //sizes[a] += sizes[b] size
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int vertex;
    cin >> vertex;
    
    parent.resize(vertex);
    sizes.resize(vertex);
    for(int i = 0; i < vertex; i++)
        make_set(i);

    for(int i = 0; i < vertex; i++)
    {
        int c, d;
        cin >> c >> d;

        union_sets(c,d);

        for(int j = 0; j < vertex; j++)
            cout << sizes[parent[j]] << " ";
        cout << endl;
    }
}
