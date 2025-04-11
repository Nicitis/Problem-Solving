# 17626번-Four Squares

## 문제

- 백준, …, https://www.acmicpc.net/problem/17626
- 풀이 날짜: 2025.4.11
- 풀이 시간: 14:10~14:52(DP 풀이), 14:55~15:11(브루트포스 풀이)
- 알고리즘 분류: 다이나믹 프로그래밍, 브루트포스
- 사용 언어: C++

## 문제 해설

### 초기 풀이

dp[i] = 수 i를 나타내는 제곱수의 최소 개수 (단, 1 ≤ j ≤ i)

위와 같이 정의할 때, dp[i] = min(dp[i], dp[i - j] + dp[j])로 나타낼 수 있다.

이렇게 되면 시간 복잡도가 O(N^2)이 된다.

n≤50000이고 시간 제한은 0.5초이므로, 시간 복잡도가 O(N)일 경우 시간이 아슬아슬하게 초과할 가능성이 높았다. 하지만 다행히 시간 내에 해결되었다.

```cpp
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
            for (int j = i - 1; j >= halfI; j--)
                if (dp[j]+dp[i-j] < dp[i])
                    dp[i] = dp[j]+dp[i-j];
        }
    }

    cout << dp[n];

    return 0;
}
```

하지만 시간이 376ms나 걸렸고, 사실상 거의 0.5초에 근접하게 걸렸다.

개선 방법을 찾아보니, dp[i] = dp[i - j] + dp[j]가 아니라, dp[i] = min(dp[i], dp[i - j*j] + 1)로 표현하는 방법이 있었다.

즉, 기존의 수 하나에 j*j를 더하여 i의 수를 만든다는 것이다. 그러면 기존의 수 i - j*j를 만드는 데에 필요한 최소의 제곱수의 개수에 1을 더하기만 하면 된다.

이렇게 되면 시간 복잡도가 ~N^1.5로 수렴하게 된다.

```cpp
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
```

여기서 재미있는 점은, j ≤ sqrt(i)을 사용하는 것보다 j\*j < i로 계산하는 것이 더 효율적이라는 점이다. 연산의 비용 차를 이용한 최적화 방법이니 참고하자.

이렇게 하니 12ms까지 시간이 줄었다.

### 다른 방법?

브루트포스로도 해결이 가능한데, “모든 자연수는 아무리 많아도 네 개의 제곱수의 합으로 표현할 수 있다”는 라그랑주 네 제곱 정리가 주어져 있기 때문에, 이를 통해 그냥 하나의 제곱수, 두 개의 제곱수, 세 개의 제곱수로 표현이 가능한지 모두 순회해보면 된다. 그 모든 방법으로 만들 수 없다면 4개의 수로 표현이 가능하다.

```cpp
#include <iostream>

using namespace std;

int main()
{
    int n;
    int sqrN[224], sqrtN;

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    // 1
    for (int i = 1; i * i <= n; i++)
    {
        sqrN[i] = i*i;
        sqrtN = i;
        if (sqrN[i] == n)
        {
            cout << "1\n";
            return 0;
        }
    }
    // 2
    for (int i = 1; i <= sqrtN; i++)
        for (int j = 1; j <= i; j++)
        {
            if (sqrN[i] + sqrN[j] == n)
            {
                cout << "2\n";
                return 0;
            }
            if (sqrN[i] + sqrN[j] > n)
                break;
        }
    // 3
    for (int i = 1; i <= sqrtN; i++)
        for (int j = 1; j <= i; j++)
            for (int k = 1; k <= j; k++)
            {
                if (sqrN[i] + sqrN[j] + sqrN[k] == n)
                {
                    cout << "3\n";
                    return 0;
                }
                if (sqrN[i] + sqrN[j] + sqrN[k] > n)
                    break;
            }

    cout << "4\n";

    return 0;
}
```
