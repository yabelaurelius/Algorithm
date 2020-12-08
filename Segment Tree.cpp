#include <bits/stdc++.h>
#define EPS 1e-9
#define ll long long int

using namespace std;

ll arr[200000], st[4 * 200000], lazy[4 * 200000], highest = 0;

void propagate(int i, int tLeft, int tRight)
{
    st[i] += lazy[i];
    if(tLeft != tRight)
    {
        lazy[i * 2] += lazy[i];
        lazy[i * 2 + 1] += lazy[i];
    }
    lazy[i] = 0;
}

void buildST(int i, int tLeft, int tRight)
{
    highest = max(highest, i);
    if(tLeft == tRight)
        st[i] = arr[tLeft];
    else
    {
        int tMid = (tLeft + tRight) / 2;
        buildST(i * 2, tLeft, tMid);
        buildST(i * 2 + 1, tMid + 1, tRight);
        st[i] = st[i * 2] + st[i * 2 + 1];
    }
}

ll queryST(int i, int tLeft, int tRight, int left, int right)
{
    if(left > tRight || right < tLeft)
        return 0;
    else if(left <= tLeft && right >= tRight)
        return st[i];
    else
    {
        int tMid = (tLeft + tRight) / 2;
        return queryST(i * 2, tLeft, tMid, left, right) + queryST(i * 2 + 1, tMid + 1, tRight, left, right);
    }
}

ll lazyQueryST(int i, int tLeft, int tRight, int left, int right)
{
    if(lazy[i] != 0)
        propagate(i, tLeft, tRight);

    if(left > tRight || right < tLeft)
        return 0;
    else if(left <= tLeft && right >= tRight)
        return st[i];
    else
    {
        int tMid = (tLeft + tRight) / 2;
        return queryST(i * 2, tLeft, tMid, left, right) + queryST(i * 2 + 1, tMid + 1, tRight, left, right);
    }
}

void updateST(int i, int tLeft, int tRight, int index, int value)
{
    if(index == tLeft || index == tRight)
        return;
    else if(tLeft == tRight)
        st[i] = value;
    else
    {
        int tMid = (tLeft + tRight) / 2;
        updateST(i * 2, tLeft, tMid, index, value);
        updateST(i * 2 + 1, tMid + 1, tRight, index, value);
        st[i] = st[i * 2] + st[i * 2 + 1];
    }
}

void lazyUpdateST(int i, int tLeft, int tRight, int left, int right, int value)
{
    if(lazy[i] != 0)
        propagate(i, tLeft, tRight);
 
    if (right < tLeft || tRight < left)
        return;
    else if (tLeft >= left && tRight <= right)
    {
        st[i] += value * (tRight - tLeft + 1);
        if(tLeft != tRight)
        {
            lazy[i * 2] += value;
            lazy[i * 2 + 1] += value;
        }
    }
    else
    {
        int tMid = (tLeft + tRight) / 2;
        lazyUpdateST(i * 2, tLeft, tMid, left, right, value);
        lazyUpdateST(i * 2 + 1, tMid + 1, tRight, left, right, value);
        st[i] = st[i * 2] + st[i * 2 + 1];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int many, query;
    cin >> many >> query;

    for(int i = 0; i < many; i++)
        cin >> arr[i];

    buildST(1, 0, many - 1);
//    for(int i = 0; i < 4 * (many - 1); i++)
//        cout << st[i] << " ";
//    cout << endl;

    while(query--)
    {
//        for(int i = 0; i < 4 * (many - 1); i++)
//            cout << st[i] << " ";
//        cout << endl;

        int a, b, c;
        cin >> a >> b >> c;

        if(a == 1)
            updateST(1, 0, many - 1, --b, c);
        else
            cout << queryST(1, 0, many - 1, --b, --c) << endl;
    }

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << " ms\n";
    return 0;
}
