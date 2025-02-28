# 31884번-Stacking Sticks

## 문제

- 백준, 실버 2, https://www.acmicpc.net/problem/31884
- 풀이 날짜: 2025.2.27.
- 풀이 시간: 12:35~12:52(17분)
- 알고리즘 분류: 구현, 자료구조, 시뮬레이션, 해시 기반 집합/맵
- 사용 언어: C++

## 문제 해설

15만 번의 쿼리가 주어질 때, 블럭의 최대 Y를 계산하는 문제이다.

쿼리의 순서에 따라 블럭을 쌓는 순서가 달라져 최대 Y가 달라지게 된다. 따라서 쿼리가 주어지는 순서대로 계산을 수행해야 한다.

그런데 각 좌표별로 Y 값을 저장하도록 하면 20억 개의 좌표에 대해 Y 값을 저장해야 하므로 메모리가 부족하다.

그러나 매 쿼리 시마다 앞에 있었던 모든 연산을 수행하도록 하기에는, 쿼리의 수 Q가 15만 번이나 되므로, 단일 쿼리 내에서 O(logQ)의 시간 안에 연산을 수행할 수 있어야 한다. 그러면 $QlogQ ≤ 150,000 * \log_2{150,000}≤150,000 * 20 = 3,000,000$의 연산량으로 계산을 수행할 수 있다.

따라서 좌표를 저장하되, 블럭이 존재하는 좌표만 Y 값을 저장하도록 하여야 한다. 또한, 해당 좌표에 접근할 수 있는 시간은 O(logQ) 이내여야 한다. 이를 수행하기에 알맞은 자료구조는 해시맵 또는 트리가 있다.

C++에서는 map(BST 기반), unordered map(Hash map 기반) 두 가지를 활용할 수 있다. 다만 unordered map은 키 중복 시 O(N)의 접근 시간을 갖게 되는 위험이 존재하므로 map을 활용하고자 하였다.

이때 map에 저장될 자료는 이렇다.

- Key: X 좌표
- Value: 해당 X의 최대 Y 좌표

### 코드

이를 기반으로 짠 코드를 살펴보자.

각 좌표별로 map에서 자료를 검색하고, 자료가 존재하지 않으면 Y를 0으로 간주하도록 한다.

쿼리의 타입이 1이면 수평으로 놓아야 한다. 따라서 해당하는 4개 칸 중 가장 높은 Y인 maximumY를 찾고, 네 개 칸에 (maximumY + 1)의 값을 저장한다.

쿼리 타입이 2일 경우엔 (해당 칸의 최대 Y + 4)를 저장한다.

쿼리 타입이 3일 땐 map에서 자료를 검색한다.

```cpp
#include <iostream>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    map<int, int> heightMap;
    int q, type, x;
    map<int, int>::iterator it;
    int maximumY;

    cin >> q;

    for (int i = 0; i < q; i++)
    {
        cin >> type >> x;
        maximumY = 0;

        switch (type)
        {
            case 1:
                // find maximum y
                for (int j = x; j < x + 4; j++)
                {
                    it = heightMap.find(j);
                    if (it != heightMap.end() && it->second > maximumY)
                        maximumY = it->second;
                }
                // update
                for (int j = x; j < x + 4; j++)
                {
                    heightMap[j] = maximumY + 1;
                }
                break;
            case 2:
                it = heightMap.find(x);
                if (it != heightMap.end() && it->second > maximumY)
                    maximumY = it->second;
                heightMap[x] = maximumY + 4;
                break;
            case 3:
                it = heightMap.find(x);
                if (it != heightMap.end() && it->second > maximumY)
                    maximumY = it->second;
                cout << maximumY << '\n';
                break;
        }
    }

    return 0;
}
```

## 더 나은 풀이

https://www.acmicpc.net/source/78887203

최상위권 유저의 풀이인데, 인상적이어서 가져와 본다.

- unique 함수를 통한 효율적인 중복 제거 방법
  - `arr.erase(unique(arr.begin(), arr.end()), arr.end());`
  - 위와 같은 형식의 연산을 통해 빠르게 중복을 제거할 수 있다. 해당 유저는 블럭 또는 쿼리가 존재하는 모든 X를 해당 방법을 통해 저장해 놓도록 하였다.
  - 이렇게 하면 필요한 X를 모두 찾을 수 있으므로, 굳이 map이나 Hash 기반의 자료구조를 사용하지 않고 배열로도 Y 값을 모두 저장할 수 있어 유리하다.
- lower_bound를 통한 이진 탐색 수행
  - lower_bound를 이용해서도 이진 탐색을 수행할 수 있다. lower_bound는 검색할 값 x보다 크거나 같은 최초의 값을 찾는데, 이때 이진 탐색을 기반으로 검색하기 때문에, 해당 값 x가 존재한다는 확신이 있을 땐 이진 탐색 대용으로도 활용할 수 있다.
