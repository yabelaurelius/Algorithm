#include <bits/stdc++.h>
#define EPS 1e-9
#define ll long long int
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define phi 3.1415926535
 
using namespace std;
 
ll tc, cnt = 0, number, many, total = 0;
int rmove[4] = {0, 0, -1, 1};
int cmove[4] = {1, -1, 0, 0};

int digit[367][801], frequency[367][11];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    // freopen("input.txt","r", stdin);
    // freopen("output.txt","w", stdout);
    // g++ -std=c++11 Default.cpp  -o test

    memset(digit, 0, sizeof(digit));
    memset(frequency, 0, sizeof(frequency));

    digit[0][0] = 1, frequency[0][0] = 1;
    for(int i = 1; i <= 366; i++)
    {
        for(int j = 0; j < 800; j++)
        {
            digit[i][j] += digit[i - 1][j] * i;
            digit[i][j + 1] += digit[i][j] / 10;
            digit[i][j] %= 10;
        }

        int temp = 800;
        while(!digit[i][temp])
            temp--;

        for(int j = temp; j >= 0; j--)
            frequency[i][digit[i][j]]++;
    }

    while(cin >> number)
    {
        if(number == 0)
            break;

        cout << number << "! --" << endl;
        cout << setw(6) << "(0)" << setw(5) << frequency[number][0] << setw(7) << "(1)" << setw(5) << frequency[number][1] << setw(7) << "(2)" << setw(5) << frequency[number][2] << setw(7) << "(3)" << setw(5) << frequency[number][3] << setw(7) << "(4)" << setw(5) << frequency[number][4] << endl;
        cout << setw(6) << "(5)" << setw(5) << frequency[number][5] << setw(7) << "(6)" << setw(5) << frequency[number][6] << setw(7) << "(7)" << setw(5) << frequency[number][7] << setw(7) << "(8)" << setw(5) << frequency[number][8] << setw(7) << "(9)" << setw(5) << frequency[number][9] << endl;
    }

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << " ms\n";
    return 0;
}

