// 2023.03.05., 3 x n 타일링, https://school.programmers.co.kr/learn/courses/30/lessons/12902
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    if (n % 2 == 1)
        return 0;
    
    long long dp[5001] = { 1, 0, 3, 0 };
    long long mod = 1000000007LL;
    
    for (int i = 4; i <= n; i += 2)
    {
        // 나머지간 뺄셈 연산을 하기 때문에, 음수가 나올 수 있다.
        // 따라서 뺄셈 이후 mod(1,000,000,007) 값을 더해준 다음 나머지 연산을 한다.
        dp[i] = ((4 * dp[i - 2]) % mod - dp[i - 4] + mod) % mod;
    }
        
    return (int)dp[n];
}

int main()
{
    int n;

    cin >> n;

    cout << solution(n);

    return 0;
}