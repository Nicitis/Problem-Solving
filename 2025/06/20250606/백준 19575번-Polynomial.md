# 백준 19575번-Polynomial

## 문제

- 백준, 브론즈 1, [문제 링크](https://www.acmicpc.net/problem/19575 "https://www.acmicpc.net/problem/19575")
- 풀이 날짜: 2025.06.06
- 풀이 시간: 20:52~21:10(18분)
- 알고리즘 분류: 수학, 구현
- 사용 언어: C++

## 문제 해설

(((a0x+a1)x+a2)x+a3)+…와 같이 단순히 계산하면 끝.

```cpp
#include <iostream>

using namespace std;

int main()
{
    int n, x, a, b;
    long long result = 0LL;
    const long long Divider = 1000000007LL;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> x;

    for (int i = 0; i <= n; i++)
    {
        cin >> a >> b;
        result = (result * x + a) % Divider;
    }

    cout << result;

    return 0;
}
```
