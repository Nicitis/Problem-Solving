// 2023.02.27., 2xn 타일링, https://school.programmers.co.kr/learn/courses/30/lessons/12900?language=cpp
#include <string>
#include <vector>

#define MOD 1000000007

using namespace std;

int solution(int n)
{
    vector<int> dp(n + 1, 0);
    
    dp[1] = 1; // n = 1일 때
    dp[2] = 2; // n = 2일 때
    
    for (int i = 3; i <= n; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD; 
        // dp[k] (k>=1)는 최대 약 10억이므로, dp[i-1] + dp[i-2]도 int의 범위를 넘지 않는다.
    }
    
    return dp[n];
}