# 16815번-Star in Parentheses

## 문제

- 백준, 실버 5, https://www.acmicpc.net/problem/16815
- 풀이 날짜: 2025.2.4.
- 풀이 시간: 10:02~10:08(6분)
- 알고리즘 분류: 스택, 문자열
- 사용 언어: C++

## 문제 해설

\*이 속한 괄호가 몇 중으로 괄호가 쳐져 있는지 구하는 문제이다.

괄호의 구조는 스택과 유사하다. 다만 여기서는 이미 괄호가 Balance가 맞다고 되어 있으므로, (가 나올 때 중첩이 1 증가하고 )가 나올 때 중첩이 감소한다는 부분만 구현하면 된다.

그리고 \*이 나올 때 괄호의 중첩 수를 출력하면 해결된다.

```cpp
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int parentheses = 0;
    string input;

    cin >> input;

    for (char c : input)
    {
        if (c == '(')
            parentheses++;
        else if (c == ')')
            parentheses--;
        else if (c == '*')
        {
            cout << parentheses << '\n';
            break;
        }
    }

    return 0;
}
```
