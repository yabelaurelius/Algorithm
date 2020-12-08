#include <bits/stdc++.h>
using namespace std;

int many;
int data[200005];

void add(int index, int value)
{
    while(many >= index)
    {
        data[index] += value;
        index += index & -index;
    }
}

int sum(int index)
{
    int sum = 0;
    while(index > 0)
    {
        sum += data[index];
        index -= index & -index;
    }
    return sum;
}

int main()
{
    int number;
    cin >> number;

    while(number--)
    {
        memset(data, 0, sizeof(data));
        vector<pair<int,int>> vec;

        cin >> many;

        for(int i = 0; i < many; i++)
        {
            int temp;
            cin >> temp;
            vec.push_back(make_pair(temp,i + 1));
        }

        sort(vec.rbegin(), vec.rend());

        long long ans = 0;
        for(int i = 0; i < vec.size(); i++)
        {
            ans += sum(vec[i].second);
            add(vec[i].second,1);
        }
        cout << ans << endl;

    }
}

