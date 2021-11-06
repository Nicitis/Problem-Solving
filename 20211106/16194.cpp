// 백준 16194: 카드 구매하기 2(c++)
/*
카드 구매하기 1과 유사하지만, 카드 구매가의 최솟값을 저장한다는 점이 다름
*/
#include <iostream>
#include <algorithm>

int main()
{
    // 입력
    int N, dp[1001];
    std::ios_base::sync_with_stdio(false);
    std::cin >> N;
    for (int i = 1; i <= N; i++)
        // i장을 구매하는 최소 비용을 카드팩 구매 비용으로 설정
        std::cin >> dp[i]; 
    
    // 최솟값 계산
    for (int i = 2; i <= N; i++)
    {
        // dp[1] + dp[2] = dp[2] + dp[1]이므로 k <= 1/2까지만 반복
        for (int k = 1; k <= i / 2; k++)
        {
            // i장 금액 최솟값 = (i - k)장 금액 최솟값 + k장 금액 최솟값
            dp[i] = std::min(dp[i], dp[i - k] + dp[k]);
        }
    }
    std::cout << dp[N] << '\n';
    return 0;
}