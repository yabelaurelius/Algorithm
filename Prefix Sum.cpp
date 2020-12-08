#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int number;
    cin >> number;

    int arr[number];
    for(int i = 0; i < number; i++)
        cin >> arr[i];

    for(int i = 0; i < number; i++)
        cout << arr[i] << " ";
    cout << endl;

    for(int i = 0; i < number; i++)
    {
        if(i != 0)
            arr[i] += arr[i-1];
        cout << arr[i] << " ";
    }
    cout << endl;

    int a, b, sum1 = 0, sum2 = 0;
    cin >> a >> b;

    for(int i = 0; i < max(a,b); i++)
    {
        if(i < a)
            sum1 += arr[i];
        if(i < b)
            sum2 += arr[i];
    }
    cout << abs(sum2-sum1) << endl;

}

