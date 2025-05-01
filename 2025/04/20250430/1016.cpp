#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

// min�� max�� ���̴� �ִ� 100��.
/*
100�� log 100���̸� ����� �ذ� ������ ����.
������ min�� ������ 1~1��
�׷��� �����غ��� sqrt(1��) = �鸸.

1�� ���̵��
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
�� ������ ��� ��ȸ�ϴ� ���. ������ �־��� ���
���� �ð��� �ɸ���.

2�� ���̵��
1 ~ sqrt(max)���� ��� �� i�� ����
min <= i * i * k <= max�� �����ϴ� ��� k�� ����
i * i * k�� ���� �����Ѵ�.
�⺻������ min~max ��� ���� ������������ �����ϸ�,
�̵��� ���� (max-min+1)�� �迭 isNotSquared�� ���εǴµ�
���� 0~(max-min) �ε����� ���´�.
�ʱ⿡�� ��� �ε����� ���� isNotSquared�� true�̴�.
�̶� ���� ���� min <= i * i * k�� ���� �� �̶��� k�� t�� ����
idx = i * i * t - min�� ���� isNotSquared[idx]=false�� �����ϰ�,
idx += i * i, idx <= max - min�� ������ ���� �� �۾��� �ݺ��Ѵ�.
�̷��� �ϸ� �ð����⵵�� (max-min) * (1/4 + 1/9 + ... + 1/(sqrt(max)-1)^2
 + 1/(sqrt(max))^2) = ~(max - min) * (sqrt(max)(sqrt(max)+1)(2sqrt(max)+1)/6max)
 = ~sqrt(max)*(max-min)=�� �ð����⵵�� ���´�.(100��*100��)

���̵�� 3
�Ҽ��� ������ ����� �����Ѵٸ�?

(max - min * 1/4 + 1/9 + ...) 
< (max-min) * (1/2 + 1/3 + 1/5 + ... + 1/sqrt(max))
= (max-min)loglog(max)

+ sqrt(max) ������ �Ҽ� ���ϴ� �ð� 
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
        // minimum �̻��� ���� ���� p*p�� ����� ���
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