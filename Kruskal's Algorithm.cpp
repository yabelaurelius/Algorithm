#include <bits/stdc++.h>
#define EPS 1e-9
#define ll long long int

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
        if(sizes[a] == sizes[b])
            sizes[a]++;
    }
}

struct Edge
{
    ll u, v, weight;
    bool operator<(Edge const& other)
    {
        return weight > other.weight;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt","r", stdin);
    freopen("output.txt","w", stdout);

    int number;
    cin >> number;

    while(number--)
    {
        int many, query;
        cin >> many >> query;

        vector <Edge> edges, result;
        parent.resize(many);
        sizes.resize(many);
        edges.resize(query);

        for(int i = 0; i < many; i++)
            make_set(i);

        for(int i = 0; i < query; i++)
        {
            ll a, b, c;
            cin >> a >> b >> c;

            a--;
            b--;

            edges[i].u = a;
            edges[i].v = b;
            edges[i].weight = c;
        }

        sort(edges.begin(), edges.end());

        ll cost = 0;
        for(int i = 0; i < edges.size(); i++)
        {
            if(find_set(edges[i].u) != find_set(edges[i].v))
            {
                cost += edges[i].weight;
                result.push_back(edges[i]);
                union_sets(edges[i].u, edges[i].v);
            }
        }
        cout << cost << endl;
    }

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << " ms\n";
}
