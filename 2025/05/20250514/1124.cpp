#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPrime[100001];
vector<int> primes;

void getPrimes(int maxN, vector<int>& outPrimes)
{
    fill_n(isPrime, maxN + 1, true);
    
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= maxN; i++)
    {
        if (isPrime[i])
            for (int j = i * i; j <= maxN; j += i)
                isPrime[j] = false;
    }

    for (int i = 2; i <= maxN; i++)
    {
        if (isPrime[i])
            outPrimes.push_back(i);
    }
}

int PrimeFactorize(int n)
{
    int factors = 0;
    while (n % 2 == 0)
    {
        factors++;
        n /= 2;
    }
    int p = 3;

    while (p * p <= n)
    {
        while (n % p == 0)
        {
            n /= p;
            factors++;
        }
        p += 2;
    }
    
    if (n > 1)
        factors++;

    return factors;
}

int FindUnderPrimes(int a, int b)
{
    int underprimes = 0;
    for (int i = a; i <= b; i++)
    {
        if (isPrime[i])
            continue;
        int factors = PrimeFactorize(i);
        if (isPrime[factors])
            underprimes++;
    }
    return underprimes;
}

int main()
{
    int a, b;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> a >> b;

    getPrimes(b, primes);

    cout << FindUnderPrimes(a, b);

    return 0;
}