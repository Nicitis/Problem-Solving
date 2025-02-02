# 13119번-Mountains Beyond Mountains

## 문제

- 백준, 실버 5, https://www.acmicpc.net/problem/13119
- 풀이 날짜: 2025.2.2.
- 풀이 시간: 16:33~16:54(21분)
- 알고리즘 분류: 구현, 문자열
- 사용 언어: C++

## 문제 해설

단순 구현에 문자열을 약간 섞은 문제.

시키는 대로 하면 되긴 하는데, 어떤 자료형을 쓸지 고치는 과정에서 시간이 걸렸다.

특히, column로 먼저 순회하고 다음에 row로 순회하다 보니 인덱싱할 때 i, j를 바꾸는 실수를 해버렸다.

이 부분을 제외하면 큰 문제는 없었다.

```cpp
#include <iostream>
#include <vector>
#include <string>

#define MOUNTAIN 35
#define TUNNEL 42
#define BRIDGE 45
#define EMPTY 46
#define SUPPORT 124

using namespace std;

vector<string> map;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, X;

    cin >> N >> M >> X;

    map = vector<string>(N, string(M, EMPTY));

    int mHeight;
    for (int j = 0; j < M; j++)
    {
        cin >> mHeight;

        for (int i = 0; i < N; i++)
        {
            int h = N - i;
            if (h <= mHeight)
            {
                if (h == X)
                    map[i][j] = TUNNEL;
                else
                    map[i][j] = MOUNTAIN;
            }
            else if (h == X)
                map[i][j] = BRIDGE;
            else if (h < X && j % 3 == 2)
                map[i][j] = SUPPORT;
        }
    }

    for (int i = 0; i < N; i++)
        cout << map[i] << '\n';

    return 0;
}
```
