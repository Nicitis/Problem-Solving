# 25773번-Number Maximization

## 문제

- 백준, 브론즈 2, https://www.acmicpc.net/problem/25773
- 풀이 날짜: 2025.2.2.
- 풀이 시간: 16:26~16:31 (5분)
- 알고리즘 분류: 정렬
- 사용 언어: C++

## 문제 해설

단순히 숫자를 6개로 쪼개어 정렬한 후 큰 수부터 출력하는 문제.

```cpp
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int number;
    int digits[6], idx = 0;
    cin >> number;

    while (number > 0)
    {
        digits[idx++] = number % 10;
        number /= 10;
    }
    sort(digits, digits + idx);

    number = 0;
    for (int i = idx - 1; i >= 0; i--)
    {
        number = number * 10 + digits[i];
    }
    cout << number << '\n';

    return 0;
}
```
