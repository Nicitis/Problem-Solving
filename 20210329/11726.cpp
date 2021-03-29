// 백준 11726 2xn 타일링 https://www.acmicpc.net/problem/11726
// dp 문제로, 가장 왼쪽에 어떤 블록을 놓느냐에 따라서 가능한 경우의 수를 결정할 수 있다.
// 이전의 결과를 가져온다는 사고가 가장 중요하다.
#include <cstdio>

int dp[1001];

int solve(int n)
{
    if (dp[n] != 0)
        return dp[n] % 10007;
    dp[n] = solve(n-1) + solve(n-2);
    return dp[n] % 10007;
}

int main()
{
    int n;

    dp[0] = -1;
    dp[1] = 1;
    dp[2] = 2;
    
    scanf("%d", &n);
    printf("%d", solve(n));
}

/*
// bottom-up dynamic programming
int dp[1001];
int main()
{
    int n;
    scanf("%d", &n);
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++)
        dp[i] = dp[i-1] + dp[i-2];
    printf("%d", &dp[n]);
    return 0;
}
*/

/*
// non-recursive method
int main()
{
    int n;
    scanf("%d", &n);
    // calculate fib(n+1)
    if (n == 1) printf("1");
    else if (n == 2) printf("2");
    else
    {
        int a = 1, b = 2, result;
        for (int i = 3; i <= n; i++)
        {
            result = (a + b) % 10007;
            a = b;
            b = result;
        }
        printf("%d", result);
    }
}
*/