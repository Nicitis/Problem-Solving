# 프로그래머스-봉인된 주문(lv3)

## 문제

- 프로그래머스, lv3, https://school.programmers.co.kr/learn/courses/30/lessons/389481?language=cpp
- 풀이 날짜: 2025.4.18.
- 풀이 시간: 13:27~14:26(59분)
- 알고리즘 분류: 구현, 수학
- 사용 언어: C++

## 문제 해설

시간 제한 1초라 가정할 때,
n <= 10^15이므로, 1 000 000 000 000 000번의 연산은 O(n)에 해결할 수 없다.
즉, 수학적으로 접근하든지, O(logN) 시간에 해결하든지 해야 한다.

1글자로 완성할 수 있는 주문 수는 26글자이고,
2글자로 완성할 수 있는 주문 수는 26 \* 26,
3글자로 완성할 수 있는 주문 수는 26 ^ 3이다.
즉, k글자로 완성할 수 있는 주문의 수는 f(k)=26+26^2+26^3+...+26^n=a(r^n-1)/(r-1)=26(26^n-1)/25로 정리할 수 있다.
또한, n>f(k-1)인 가장 큰 k에 대하여 n번째 주문은 k글자로 구성되며 i번째 글자(1<=i<=k)는 (n-f(k))/26^(k-i))%26로 일반화할 수 있다.
그런데 삭제된 주문이 있으므로...
주문을 구하기 이전에 각 주문의 번호 b를 구하고, n보다 작은 주문번호 b의 개수만큼 n을 증가시켜야 한다.
그런데 주문을 ban하게 되면, n번보다 큰 주문이 원래는 영향을 안 끼쳤는데 나중엔 영향을 끼칠 수도 있다.
그래서 모든 주문의 주문번호를 구하고, 주문 번호를 오름차순으로 정렬하고, 주문 번호보다 n이 작거나 같으면 n을 증가시킨다.
그렇게 해서 n에 해당하는 주문을 구한다.

```cpp
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

#include <iostream>

using namespace std;

long long llPow(long long x, long long p)
{
    if (x == 0)
        return 0;
    if (p == 0)
        return 1;

    if (p % 2 == 0)
    {
        long long ans = llPow(x, p / 2);
        return ans * ans;
    }
    else
    {
        return llPow(x, p - 1) * x;
    }
}

long long numberOfScrollByLength(int length)
{
    return 26LL * (llPow(26, length)-1) / 25;
}

long long getScrollId(string& scroll)
{
    int length = scroll.size();
    long long id = numberOfScrollByLength(length - 1) + 1;
    long long mult = 1;
    for (int i = length - 1; i >= 0; i--, mult *= 26)
    {
        id += (scroll[i]-'a')*mult;
    }
    return id;
}

string getScrollById(long long id)
{
    string scroll = "";
    int length;
    for (int i = 0; i <= 11; i++)
    {
        long long numberOfScrolls = numberOfScrollByLength(i);
        if (id <= numberOfScrolls)
        {
            length = i - 1;
            id -= numberOfScrolls;
            break;
        }
    }
    long long div = 1;
    for (int i = length - 1; i >= 0; i--, div *= 26)
    {
        char c = (id / div) % 26 + 'a';
        scroll = c + scroll;
    }
    return scroll;
}

string solution(long long n, vector<string> bans) {
    string answer;

    vector<long long> ban_ids;

    // 1. 각 bans에 대한 주문 번호를 구한다.
    for (string ban : bans)
    {
        ban_ids.push_back(getScrollId(ban));
    }

    // 2. 오름차순 정렬하여, 금지된 주문 번호가 n 이하라면 n을 증가시킨다.
    sort(ban_ids.begin(), ban_ids.end());
    for (long long id : ban_ids)
    {
        if (n >= id)
            n++;
    }

    // 3. n에 해당하는 주문을 구한다.
    answer = getScrollById(n);

    return answer;
}

int main()
{
    string str;
    cin >> str;

    cout << getScrollId(str);

    return 0;
}
```
