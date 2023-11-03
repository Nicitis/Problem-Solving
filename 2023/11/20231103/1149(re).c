// 백준-1149 RGB 거리
#include <stdio.h>

#define MIN(X,Y) ((X)<(Y)?(X):(Y))

// N개의 집 RGB 중 하나로, 비용이 주어졌을 때, 최소 비용
// 집의 수는 1000개, 모든 집을 칠하는 것은 너무 리스크가 크다.
// 이웃한 집은 색이 달라야 한다.
// dp로 풀자? 각 집을 빨강/초록/파랑으로 칠했을 때의 최소비용을 구하자
int main()
{
    int dp[1000][3] = { 0 };
    int N;
    int result;

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        scanf("%d %d %d", &dp[i][0], &dp[i][1], &dp[i][2]);

    // dp 계산: dp[i+1][c] += max(dp[i][(c + 1) % 3], dp[i][(c + 2) % 3]
    for (int i = 1; i < N; i++)
    {
        for (int c = 0; c < 3; c++)
        {
            dp[i][c] += 
                MIN(dp[i-1][(c + 1) % 3], dp[i-1][(c + 2) % 3]);
        }
    }

    result = MIN(dp[N-1][0],
                MIN(dp[N-1][1], dp[N-1][2]));
    
    printf("%d", result);

    return 0;
}