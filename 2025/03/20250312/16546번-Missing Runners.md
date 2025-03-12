# 16546번-Missing Runners

## 문제

- 백준, 브론즈 3, https://www.acmicpc.net/problem/16546
- 풀이 날짜: 2025.3.12.
- 풀이 시간: 22:23~22:26(3분)
- 알고리즘 분류: 구현, 수학
- 사용 언어: C++

## 문제 해설

n명의 달리기 선수가 있을 때, 각 선수의 등에는 1번부터 n번까지 선수 번호가 붙어 있다. 도착한 (n-1)명의 선수 번호가 주어졌을 때, 아직 도착하지 않은 마지막 선수의 번호를 구하는 문제이다.

단순히 생각하면 n개짜리 bool 배열을 만들어서 검사해야 할 것 같다. 하지만 굳이 그럴 필요없이, 수학적으로 접근하면 된다.

1부터 n까지를 더한 결과는 n(n+1)/2이다. 이때, 도착한 runner의 모든 숫자를 빼면, 1부터 n까지의 수 중 단 하나 K를 제외하고 모두 빼는 셈이 된다. 즉, 빼는 값은 n(n+1)/2 - K이 된다.

그러면 남는 값은 n(n+1)/2 - (n(n+1)/2 - K) = K이다.

즉, n(n+1)/2에서 도착한 모든 달리기 선수의 번호를 빼면, 남는 것은 마지막 선수의 번호이다.

이러면 O(n)의 시간 복잡도, O(1)의 공간 복잡도에 문제를 해결할 수 있다.

```csharp
#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, runner, sumOfRunners;
    cin >> n;

    sumOfRunners = n * (n+1) / 2;

    for (int i = 1; i < n; i++)
    {
        cin >> runner;
        sumOfRunners -= runner;
    }

    cout << sumOfRunners << '\n';

    return 0;
}
```
