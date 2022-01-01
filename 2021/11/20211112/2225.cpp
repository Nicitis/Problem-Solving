// 백준 2225: 합분해(C++)
#include <iostream>
#define MOD 1000000000

using namespace std;

int dp[201][201];

int Decomposition(int n, int k)
{
    // 0을 만드는 방법은 0을 합하는 것밖에 없음
    if (n == 0)
        return 1;
    // 1개의 정수로 분해하는 것은 하나의 경우만이 존재
    if (k == 1)
        return 1;
    
    // 계산되지 않은 값이라면...
    if (dp[n][k] == 0)
    {
        // 0부터 N까지의 값을 좌측에 더하고, 그에 대한 합분해의 경우의 수를 가져온다.
        for (int i = 0; i <= n; i++)
        {
            dp[n][k] += Decomposition(i, k-1);
            dp[n][k] %= MOD;
        }
    }
    return dp[n][k];
}

int main()
{
    int n, k;
    ios_base::sync_with_stdio(false);

    cin >> n >> k;

    printf("%d\n", Decomposition(n, k));
}