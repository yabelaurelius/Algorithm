#include <bits/stdc++.h>

#define ll long long int
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define phi 3.1415926535
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
using namespace std;

const ll mod = 1000000007;    

ll tc, cnt = 0, number, many, total = 0, query, require, length;
int rmove[8] = {1, 0, 0, -1, -1, 1, -1, 1};
int cmove[8] = {0, -1, 1, 0, 1, -1, -1, 1};

ll modpow(ll x, ll y, ll m)
{
    ll res = 1;
    while(y > 0)
    {
        if(y & 1)
            res = (res * x) % m;
        x = (x * x) % m;
        y >>= 1;
    }

    return res;
}

vector < vector<int> > adjList;

vector <int> Hierholzer(int start)//Directed Eulerian Path
{
    vector <int> answer, sum, vec;
    sum.assign(many, 0);
    vec.pb(start);

    while(!vec.empty())
    {
        int now = vec.back();
        if(sum[now] < adjList[now].size())
        {
            vec.pb(adjList[now][sum[now]]);
            sum[now]++;
        }
        else
        {
            answer.pb(now);
            vec.pop_back();
        }
    }

    reverse(answer.begin(), answer.end());
    return answer;
}

int main()
{
    fastio();
        
    // freopen("input.txt","r", stdin);
    // freopen("output.txt","w", stdout);
    // g++ -std=c++11 Default.cpp  -o test
    // g++ -Wl,--stack=268435456 -std=c++11 Default.cpp  -o test

    cin >> many >> number;

    adjList.resize(many);

    for(int i = 0; i < number; i++)
    {
        int a, b;
        cin >> a >> b;

        a--;
        b--;

        adjList[a].pb(b);
        adjList[b].pb(a);
    }

    vector <int> vec = Hierholzer(0);

    for(int i = 0; i < vec.size(); i++)
        cout << i << " ";
    cout << '\n';

    //
    return 0;
}