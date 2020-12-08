#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    vector <int> vec;
    for(int i = 0; i < 10; i++)
        vec.push_back(i+1);

    int x = 5, left = 0, right = vec.size()-1;
    while(left <= right)
    {
        int mid = left + ((right - left) / 2);
        if(vec[mid] == x)
            cout << x << " at " << mid << endl;
        if(vec[mid] > x)
            right = mid-1;
        else
            left = mid+1;
    }
}
