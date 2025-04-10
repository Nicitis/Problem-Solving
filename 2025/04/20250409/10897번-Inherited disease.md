# 10897번-Inherited disease

## 문제

- 백준, 골드 5, https://www.acmicpc.net/problem/10897
- 풀이 날짜: 2025.4.9.
- 풀이 시간: 15:49~17:46(1시간 57분), 17:35분에 포기하고 다른 사람 풀이 확인
- 알고리즘 분류: 수학, 구현, 트리
- 사용 언어: C++

## 문제 해설

d번째 세대의 인원 수는 d!이며 세대 d ≤ 100이므로, 트리를 직접 만들어서는 해결할 수 없다.

따라서 수학적으로 해결해야 한다.

몇 번의 실험 후, 다음과 같이 식을 세웠다.

l 세대 c번째 자손의 번호 F(l, c)는

$$
F(l, c) = [\text{1번째부터 (l-1)세대까지 정민의 수}] + [\text{(l-1) 세대에서 ‘현재 선택된 부모’의 손위 형제의 수}] * l + c
$$

와 같이 정의할 수 있다.

(다만, F는 이전 입력에 따라 바뀌므로 엄밀히 말하면 함수라고 할 수는 없다.)

예를 들어, 예제 입력에서

```cpp
3
1 2 1
```

출력은 0번 정민의 첫 번째 자손, 그 두 번째 자손, 그 첫 번째 자손을 순서대로 보여주는 것이다.

이때, (l-1) 세대에서 ‘현재 선택된 부모’의 손위 형제의 수는 말 그대로 (l-1)세대에서 현재 부모보다 먼저 태어난 사람을 말한다.

예제 입력에서 주어진 대로, 세 번째 세대에서 첫 번째 자손의 번호를 계산해보자.

![첫 자손의 번호는.png](%EC%B2%AB_%EC%9E%90%EC%86%90%EC%9D%98_%EB%B2%88%ED%98%B8%EB%8A%94.png)

세 번째 세대의 첫 번째 자손의 번호는 7번이다.

(1~2세대의 수)는 3명이고, (부모의 손위 형제의 수)는 1명이다(2번 하나). 이들이 낳을 수 있는 자손의 수는 3명이며, 현재 구하고자 하는 자손은 첫 번째 자손이다.

위 식에 따라 구하면, F(l, c) = F(3, 1) = 3 + 1 \* 3 + 1 = 7으로 번호를 계산할 수 있다.

### 1~(l-1) 세대까지의 정민의 수

1번째부터 (l - 1)번째 세대의 정민의 수는 말 그대로 1세대, 2세대, …, (l - 1)세대까지의 정민의 수를 모두 합한 것이다. 이는 정확히 (l-1)세대의 마지막 정민의 번호와 같다.

이를 C(l-1)이라 할 때,

$$
\begin{align*}
C(l-1) &= 1 + 1*2 + 1*2*3 + … + 1*2*…*(l-2)*(l-1)\\
&=1!+2!+3!+...+(l-1)!\\
&=\sum_{i=1}^{l-1}(i!)
\end{align*}
$$

와 같이 정의 가능하다.

계산의 편의성을 위해 C(l-1)을 C(l-2)로 기술하면,

$$
C(l-1)=\sum_{i=1}^{l-2}(i!)+(l-1)!=C(l-2)+(l-1)!
$$

로 변형할 수 있다.

모든 세대마다 (l-1)!를 구하는 것은 비효율적이다(l 세대까지 구하려면 곱 연산을 $1 + 2 + 3 + … + l = O(l^2)$번 수행해야 한다). 따라서 (l-2)!를 저장해놓고, C(l-1)을 구할 때 (l-2)!에 (l-1)만 곱하는 식으로 접근할 수 있다.

### (l-1) 세대에서 ‘현재 선택된 부모’ 이전에 태어난 같은 세대의 부모의 수(손위 형제의 수)

이게 무슨 말이냐 하면, 현재 선택된 부모는 (l-1)세대로써, 다음 세대인 l세대 자손을 낳게 된다.

이때 선택된 부모보다 (l-1)세대에서 더 빨리 태어난 부모들이 존재한다. 현재 선택된 부모의 자손은 이들이 자손을 낳은 다음에 태어나게 된다. 따라서, 더 빨리 태어난 형제자매의 자손에게 번호를 붙이려면, 현재 선택된 부모가 낳을 자손은 더 빨리 태어난 형제자매의 자손의 수만큼 번호가 뒤로 밀리게 된다.

따라서 현재 선택된 부모의 손위 형제의 수를 구하고, 그에 대한 자손의 수를 구해야 한다.

손위 형제의 수는 다음과 같이 구한다.

$$
(부모의\ 번호)-(1세대에서\ (l-2)세대까지\ 정민의\ 수)-1\\
= (부모의\ 번호)-C(l-2)-1
$$

이때, l=1일 땐 C(l-2)=C(-1)이 되어 계산이 0이 나와야 하는데 -1이 나온다. 따라서 1세대에 대해서는 0으로 처리해줘야 한다.

이제 이들이 낳을 자손은 각각 l명이므로, 최종적으로 다음만큼 번호가 붙을 것이다.

$$
((부모의\ 번호)-C(l-2)-1) \times l
$$

### 최종 계산식

여기에 마지막으로 몇 번째 자손인지, 즉 C를 더해줘야 l세대의 선택된 정민의 C번째 자손의 번호를 구할 수 있다.

최종적으로 정리하면 이렇다.

$$
F(l, c) = C(l-1)+((부모의\ 번호)-C(l-2)-1)\times l + c
$$

이때 C(l-1)은

$$
C(l-1)=C(l-2)+(l-2)! \cdot (l-1)
$$

정리하면 이런 코드가 된다.

```cpp
#include <iostream>

#define MOD 1000000007

using namespace std;

int main()
{
    int d;
    long long child;
    long long prevGens = 1ll;
    long long numberOfAllGens = 1ll;
    long long numberOfAllPrevGens = 0ll;
    long long parentNumber = 1, number;

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> d;

    cin >> child;
    cout << parentNumber << "\n"; // 첫 번째 자손은 무조건 1

    for (int l = 2; l <= d; l++)
    {
        cin >> child;

        long long numberOfParentGen = (parentNumber - numberOfAllPrevGens - 1);
        while (numberOfParentGen < 0) numberOfParentGen += MOD;

        long long prevChildren = (numberOfParentGen * l) % MOD;
        number = (numberOfAllGens + prevChildren + child) % MOD;
        prevGens = (prevGens * l) % MOD;
        numberOfAllPrevGens = numberOfAllGens; // C((l+1)-2)
        numberOfAllGens = (numberOfAllGens + prevGens) % MOD; // C((l+1)-1)
        parentNumber = number;

        cout << number << "\n";
    }

    return 0;
}
```
