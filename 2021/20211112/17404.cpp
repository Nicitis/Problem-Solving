// 백준 17404: RGB거리 2
#include <iostream>
#define R 0
#define G 1
#define B 2
#define MIN(x, y) ((x)<(y)?(x):(y))
#define MAXIMUM 987654321

using namespace std;

int main()
{
    int n, min_result = MAXIMUM; 
    int dp[3] = { 0 }, prices[1001][3] = {0}; // dp[집 색깔]
    
    ios_base::sync_with_stdio(false);

    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> prices[i][R] >> prices[i][G] >> prices[i][B];

    for (int first = R; first <= B; first++)
    {
        dp[R] = dp[G] = dp[B] = MAXIMUM;
        dp[first] = prices[1][first];
        for (int i = 2; i <= n; i++)
        {
            int r, g, b;
            r = prices[i][R];
            g = prices[i][G];
            b = prices[i][B];

            if (i < n) // 일반 집
            {
                // 현재 선택할 색이 아닌 다른 색 중 최소 비용을 선택
                r += MIN(dp[G], dp[B]);
                g += MIN(dp[R], dp[B]);
                b += MIN(dp[R], dp[G]);

                dp[R] = r;
                dp[G] = g;
                dp[B] = b;
            }
            else // i == n (마지막 집)
            {
                // 마지막 집의 색상이 첫 집의 색상과 같지 않게 한다.
                if (first != R)
                    min_result = MIN(min_result, r + MIN(dp[G], dp[B]));
                if (first != G)
                    min_result = MIN(min_result, g + MIN(dp[R], dp[B]));
                if (first != B)
                    min_result = MIN(min_result, b + MIN(dp[R], dp[G]));
            }
        }
    }

    cout << min_result;
}