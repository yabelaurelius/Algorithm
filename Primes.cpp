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

bitset <1500 + 5> bittersweet;
vector <ll> prime;

void SieveOfEratosthenes(int a)
{
    bittersweet.set();
    bittersweet[0] = bittersweet[1] = false;

    for(ll i = 2; i <= a; i++)
    {
        if(bittersweet[i])
        {
            for(ll j = i * i; j <= a; j += i)
                bittersweet[j] = false;
            prime.pb(i);
        }
    }
}

bool isPrime(ll a)
{
    if(a <= 1500)
        return bittersweet[a];

    for(int i = 0; i < prime.size() && prime[i] * prime[i] <= a; i++)
    {
        if(a % prime[i] == 0)
            return false;
    }
    return true;
}

vector <ll> primeFactors(ll n)
{
    ll index = 0, now = prime[index];
    vector <ll> temp;

    while(now * now <= n)
    {
        while(n % now == 0)
        {
            n /= now;
            temp.pb(now);
        }
        now = prime[++index];
    }
    if(n != 1)
        temp.pb(n);

    return temp;
}

ll countPrimeFactors(ll n)
{
    ll index = 0, now = prime[index], answer = 0;

    while(now * now <= n)
    {
        while(n % now == 0)
        {
            n /= now;
            answer++;
        }
        now = prime[++index];
    }

    if(n != 1)
        answer++;
    return answer;
}

ll countDivisor(ll n)
{
    ll index = 0, now = prime[index], answer = 1;
    while(now * now <= n)
    {
        ll power = 0;
        while(n % now == 0)
        {
            n /= now;
            power++;
        }
        answer *= (power + 1);
        now = prime[++index];
    }

    // if(n != 1)
    //     return 2 * answer;
    return (n != 1) ? 2 * answer : answer;
}

ll sumDivisor(ll n)
{
    ll index = 0, now = prime[index], answer = 1;
    while(now * now <= n)
    {
        ll power = 0;
        while(n % now == 0)
        {
            n /= now;
            power++;
        }
        answer *= (ceil(pow(now, power + 1.0)) - 1) / (now - 1);
        now = prime[++index];
    }

    if(n != 1)
        answer *= (ceil(pow(n, 2.0) - 1)) / (n - 1);
    return answer;
}

ll eulerPhi(ll n)
{
    ll index = 0, now = prime[index], answer = n;
    while(now * now <= n)
    {
        if(n % now == 0)
            answer -= answer / now;

        while(n % now == 0)
            n /= now;

        now = prime[++index];
    }

    if(n != 1)
        answer -= answer / n;
    return answer;
}

ll power(ll a, ll b, ll c)
{
    if(b == 0)
        return 1;

    if(b % 2 == 0)
    {
        ll temp = power(a, b / 2, c);
        return (temp * temp) % c;
    }
    else
        return (a % c * power(a, b - 1, c)) % c;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    // freopen("input.txt","r", stdin);
    // freopen("output.txt","w", stdout);
    // g++ -std=c++11 Default.cpp  -o test

    
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << " ms\n";
    return 0;
}