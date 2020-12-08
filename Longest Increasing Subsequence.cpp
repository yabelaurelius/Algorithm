#include <bits/stdc++.h>
#define EPS 1e-9
#define ll long long int
#define pb push_back
#define MAX_N 100000
 
using namespace std;
 
ll tc, cnt = 0, number, many, total = 0;

void print_array(string str, int sequence[], int now)
{
    for(int i = 0; i < now; i++)
    {
        if(i)
            cout << ", ";
        else
            cout << str << ": [";
        cout << sequence[i];
    }
    cout << "]" << endl;
}

void reconstruct(int i, vector <int> vec, int index[])
{
    int temp = i;   
    stack <int> stk;

    for(; index[temp] >= 0; temp = index[temp])
        stk.push(vec[temp]);

    cout << "[" << vec[temp];
    for(; stk.size() > 1; stk.pop())
        cout << ", " << stk.top();
    cout << "]" << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    freopen("input.txt","r", stdin);
    freopen("output.txt","w", stdout);
    // g++ -std=c++11 Default.cpp  -o test
    
    

    // n ^ 2
    vector <int> arr;
    while(cin >> number)
        arr.pb(number);        
    many = arr.size();

    int dp[many];
    memset(dp, 0, sizeof(dp));

    for(int i = many - 1; i >= 0; i--)
    {
        for(int j = i + 1; j < many; j++)
        {
            if(arr[j] > arr[i])
                dp[1][i] = max(dp[1][i], dp[1][j] + 1);
        }
    }

    int answer = 0;
    for(int i = 0; i < many; i++)
        answer = max(answer, dp[1][i]);
        
    cout << answer << endl;
    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << " ms\n";
    return 0;
}