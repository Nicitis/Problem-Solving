#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

// min과 max의 차이는 최대 100만.
/*
100만 log 100만이면 충분히 해결 가능한 수준.
하지만 min의 범위는 1~1경
그러나 생각해보면 sqrt(1경) = 백만.

1번 아이디어
1 10
1 x
2 x
3 x
4 o
5 x
6 x
7 x
8 x
9 o
10 x
각 수마다 모두 순회하는 방법. 하지만 최악의 경우
많은 시간이 걸린다.

2번 아이디어
1 ~ sqrt(max)까지 모든 수 i에 대해
min <= i * i * k <= max를 만족하는 모든 k에 대해
i * i * k인 수를 제외한다.
기본적으로 min~max 모든 수는 제곱ㄴㄴ수로 시작하며,
이들은 길이 (max-min+1)의 배열 isNotSquared에 매핑되는데
각각 0~(max-min) 인덱스를 갖는다.
초기에는 모든 인덱스에 대해 isNotSquared는 true이다.
이때 가장 작은 min <= i * i * k를 구한 후 이때의 k를 t라 하자
idx = i * i * t - min에 대해 isNotSquared[idx]=false로 변경하고,
idx += i * i, idx <= max - min인 범위인 동안 위 작업을 반복한다.
이렇게 하면 시간복잡도는 (max-min) * (1/4 + 1/9 + ... + 1/(sqrt(max)-1)^2
 + 1/(sqrt(max))^2) = ~(max - min) * (sqrt(max)(sqrt(max)+1)(2sqrt(max)+1)/6max)
 = ~sqrt(max)*(max-min)=의 시간복잡도를 갖는다.(100만*100만)

아이디어 3
소수의 제곱의 배수만 제거한다면?

(max - min * 1/4 + 1/9 + ...) 
< (max-min) * (1/2 + 1/3 + 1/5 + ... + 1/sqrt(max))
= (max-min)loglog(max)

+ sqrt(max) 이하의 소수 구하는 시간 
sqrt(max)loglog(max)

*/

void PrimeSieve(int maxN, vector<int>& outPrimes)
{
    bool isPrime[1000001];

    fill(isPrime, isPrime + maxN + 1, true);
    
    for (int i = 2; i * i <= maxN; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= maxN; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 2; i <= maxN; i++)
        if (isPrime[i])
            outPrimes.push_back(i);
}

int main()
{
    long long minimum, maximum;

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> minimum >> maximum;

    long long delta = maximum - minimum;
    // vector<int> primes;

    // PrimeSieve((int)sqrt((double)maximum), primes);
    
    bool isNotSquared[1000001];

    fill(isNotSquared, isNotSquared + (delta + 1), true);

    for (long long p = 2; p * p < maximum; p++)
    // for (long long p : primes)
    {
        long long pSquare = p * p;
        // minimum 이상의 가장 작은 p*p의 배수를 계산
        long long idx;
        if (minimum <= pSquare)
        {
            idx = pSquare;
        }
        else
        {
            idx = (minimum / pSquare) * pSquare;
            if (idx < minimum)
                idx += pSquare;
        }
        // (min~max) -> (0~(max-min))
        idx -= minimum;
        for (; idx <= delta; idx += pSquare)
        {
            isNotSquared[idx] = false;
        }
    }

    int answer = 0;
    for (long long i = 0; i <= delta; i++)
    {
        if (isNotSquared[i])
        {
            answer++;
        }
    }

    cout << answer;

    return 0;
}