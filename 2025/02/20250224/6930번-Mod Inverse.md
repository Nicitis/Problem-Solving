# 6930번-Mod Inverse

## 문제

- 백준, 브론즈2, https://www.acmicpc.net/problem/6930
- 풀이 날짜: 2025.2.24.
- 풀이 시간: 16:02~16:27(25분)
- 알고리즘 분류: 수학, 브루트포스, 정수론, 모듈러 역원
- 사용 언어: C++

## 문제 해설

모듈러 역원에 대한 문제.

x _ n - 1 = m _ k 꼴이 되는 n을 찾아야 한다.

단, n은 0 < n < m인 정수이므로 해당 범위 내에서 브루트포스로 순회하면 끝이다.

```cpp
#include <iostream>

using namespace std;

int main()
{
    int x, m;
    cin >> x >> m;

    for (int n = 1; n < m; n++)
    {
        if ((x * n - 1) % m == 0)
        {
            cout << n << '\n';
            return 0;
        }
    }
    cout << "No such integer exists.\n";

    return 0;
}
```
