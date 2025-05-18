/*
시간 복잡도: NloglogN
공간 복잡도: sqrt(N)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPrime[4000001];
void primeSieve(int maxN, vector<int>& outPrimes)
{
    fill_n(isPrime, maxN + 1, true);
    
    outPrimes.reserve(maxN + 1);

    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= maxN; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= maxN; j += i)
                isPrime[j] = false;
        }
    }

    for (int i = 2; i <= maxN; i++)
    {
        if (isPrime[i])
            outPrimes.push_back(i);
    }
}

int dp[4000001];

inline int getConsecutivePrimeSum(int i, int j)
{
    if (i == 0)
        return dp[j];
    else
        return dp[j] - dp[i - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;

    cin >> n;

    // 1. 체 방식으로 소수 구하기
    vector<int> primes;
    primeSieve(n, primes);

    // 2. table 구하기
    dp[0] = primes[0];
    for (int i = 1; i < primes.size(); i++)
    {
        dp[i] = dp[i - 1] + primes[i];
    }

    // 3. 최초 인덱스 찾기
    int result = 0;
    int idx = 0;

    for (int i = 0; i < primes.size(); i++)
    {
        while (idx < primes.size() &&
            getConsecutivePrimeSum(i, idx) < n)
            idx++;
        
        if (idx >= primes.size())
            break;
        if (getConsecutivePrimeSum(i, idx) == n)
        {
            result++;
        }
    }
    cout << result;

    return 0;
}
