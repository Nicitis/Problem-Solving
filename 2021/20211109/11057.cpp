// 백준 11057: 오르막 수(C++)
#include <cstdio>
#define MOD 10007

int main()
{
    // dp를 통해 마지막에 들어가는 수마다 오르막 수의 개수를 저장한다.
    int n, dp[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, count;

    scanf("%d", &n);

    // 수의 길이를 하나씩 증가시키며 오르막 수의 개수를 구함
    for (int i = 2; i <= n; i++)
    {
        // 길이가 1 증가할 때 마지막에 수를 추가함
        // 수 k(0<=k<=9)에 대한 오르막 수의 개수는 
        // count = sum(dp[0], dp[1], ..., dp[k])
        // 중복 계산을 줄이기 위해 count 변수를 사용
        count = 0;
        for (int k = 0; k < 10; k++)
        {
            count = (count + dp[k]) % MOD; 
            dp[k] = count;
        }
    }

    int total = 0;
    for (int i = 0; i < 10; i++)
    {
        total += dp[i];
    }
    printf("%d\n", total % MOD);
}