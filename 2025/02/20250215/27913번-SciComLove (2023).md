# 27913번-SciComLove (2023)

## 문제

- 백준, 브론즈2, https://www.acmicpc.net/problem/27913
- 풀이 날짜: 2025.2.15.
- 풀이 시간: 14:55~15:11(16분)
- 알고리즘 분류: 구현
- 사용 언어: C++

## 문제 해설

단순히 주어진 수를 대-소문자로 뒤집기만 하면 되는 문제이다.

여기서 꼭 뒤집힌 문자열을 출력할 필요는 없으므로 bool 배열이나 bitset으로 처리해도 되는데, 여기서는 메모리가 충분하므로 bool 배열로 처리하도록 했다.

이때 처음에 문자열에 접근하여 초기화할 땐 defaultString[(i-1)%defaultString.length()]와 같이 반복되는 구간을 처리하기 위해 %로 나머지 연산을 사용하였다.

이때 isUpperCaseList[i]에서 0번 자리는 비우도록 한다. 왜냐하면 입력에서 1번이 가장 첫 원소를 가리키기 때문이다. 이와 똑같이 맞춰주도록 하였다.

```cpp
#include <iostream>
#include <string>

#define MAX_N 200001

using namespace std;

bool isUpperCaseList[MAX_N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string defaultString = "SciComLove";
    int n, q, x, answer = 0;

    cin >> n >> q;

    for (int i = 1; i <= n; i++)
    {
        char c = defaultString[(i - 1) % defaultString.length()];
        bool isUpper = c >= 'A' && c <= 'Z';
        isUpperCaseList[i] = isUpper;
        answer += isUpper;
    }

    for (int i = 0; i < q; i++)
    {
        cin >> x;
        answer += isUpperCaseList[x] ? -1 : 1;
        isUpperCaseList[x] = !isUpperCaseList[x];
        cout << answer << '\n';
    }

    return 0;
}
```
