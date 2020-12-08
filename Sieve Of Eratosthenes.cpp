#include <bits/stdc++.h>

using namespace std;

bool prime[1000000 + 5];
vector <ll> vec;

void SieveOfEratosthenes(int a)
{
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;

    for(int i = 2; i * i <= a; i++)
    {
        if(prime[i] == true)
        {
            for(int j = i * i; j <= a; j += i)
                prime[j] = false;
        }
    }
    for(int i = 2; i <= a; i++)
    {
        if(prime[i] == true)
        {
            vec.push_back(i);
        }
    }
}

bool isPrime(ll a)
{
    if(a <= 1000000)
        return prime[a];

    for(int i = 0; i < vec.size(); i++)
    {
        if(vec[i] > sqrt(a))
            return true;
        if(a % vec[i] == 0)
            return false;
    }
    return true;
}


int main()
{
    int number;
    cin >> number;
    SieveOfEratosthenes(number);
}
