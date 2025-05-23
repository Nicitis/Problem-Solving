/*
n <= 50000
n^2 <= 2,500,000,000
알고리즘이 n^2보다는 더 빨라야 한다.
무조건 큰 값으로 채운다고 능사는 아니다.
ex) 20000 = 10000 + 10000 = 10^2 + 10^2

역으로, 이렇게 접근하면 어떨까?
1개 합으로 표현 가능한 모든 값을 갱신하고, 2개 합으로 표현 가능한 모든 값을 갱신하고,
3개 합으로 표현 가능한 모든 값을 갱신하고, 계속해서 n개 합까지 계산해보는 것이다
하지만 이렇게 하면 문제가 3개 합으로 표현 가능한 값은 어떻게 구하나? 2개 합에 1개 합을 더해서?
4개 합은 1+3, 2+2, 1+1+2, 1+1+1+1 이렇게 네 개를 모두 구해야 한다

모두 탐색하면 시간 복잡도가 초과나게 된다.

25 = 5^2
26 = 5^2 + 1 = 26

11339 = 11236(106^2)+103
103 = 

34567



*/

#include <iostream>
#include <cmath>

#define MAX 1234567890

using namespace std;

int main()
{
    int n;
    int dp[50001] = { 0, };

    cin >> n;

    int sqrtN = (int)sqrt(n);
    for (int i = 1; i <= sqrtN; i++)
    {
        dp[i*i] = 1;
    }
    if (dp[n] == 0)
    {
        for (int i = 2; i <= n; i++)
        {
            if (dp[i] != 0)
                continue;
            int halfI = i / 2;
            dp[i] = MAX;
            for (int j = 1; j * j <= i; j++)
                if (dp[i-j*j] + 1 < dp[i])
                    dp[i] = dp[i-j*j] + 1;
        }
    }

    cout << dp[n];

    return 0;
}