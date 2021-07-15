// 10844 쉬운 계단 수 https://www.acmicpc.net/problem/10844
#include <cstdio>
#define MOD 1000000000

int main(void)
{
    // 이유는 모르겠는데 어쩐지 안 된다.
    int dp[100] = { 9, };
    int bitcount[1000] = { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    int N, i, j;

    scanf("%d", &N);
    
    for (i = 1; i < N; i++)
    {
        dp[i] = (dp[i-1] * 2 - (bitcount[10 * (i-1) + 0] + bitcount[10 * (i-1) + 9])) % MOD;

        // 각 자리수를 구한다.
        bitcount[10 * i] = bitcount[10 * (i-1) + 1] % MOD;
        for (j = 1; j < 9; j++)
        {
            int index = 10 * i + j;
            bitcount[index] = (bitcount[index - 11] + bitcount[index - 9]) % MOD;
        }
        bitcount[10 * i + 9] = bitcount[10 * (i-1) + 8] % MOD;
        // for (j = 0; j < 10; j++)
            // printf("length %d, last number of %d = %d\n", i, j, bitcount[i * 10 + j]);
        // printf("=====================================");
    }

    printf("%d", dp[N - 1]);
    return 0;
}