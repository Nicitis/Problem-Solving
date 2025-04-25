# 14565번-역원(Inverse) 구하기

## 문제

- 백준, 골드 2, https://www.acmicpc.net/problem/14565
- 풀이 날짜: 2025.4.25.
- 풀이 시간: 13:12~
- 알고리즘 분류: 수학, 모듈러 역원
- 사용 언어: C++

## 문제 해설

p에 대한 a의 곱셈의 역원 x는

$$
ax+pq'=1
$$

다음에 주어진 확장된 유클리드 알고리즘을 통해 구하여야 한다.

$$
r_{i+1}=r_{i-1}-q_i r_i\\
s_{i+1}=s_{i-1}-q_i s_i\\
t_{i+1}=t_{i-1}-q_i t_i\\
(단,\ 0\le r_{i+1}<|r_{i}|인\ q_i)
$$

확장된 유클리드 알고리즘을 구현하면 이런 식이다.

중요한 점은 마지막에 b = 0일 때, x와 y는

$$
x = s_{k+1},\ y=t_{k+1}
$$

로 마지막에서 한 단계 더 계산한 결과이다. 실제로는 이 이전 단계에 해당하는 old_x를 사용해야 한다.

또한 문제가 되는 것은, x와 y는 음수일 수도 있다는 것이다.

예를 들어 a=11, b=26일 때 최종 결과에서 old_x는 -7이다. mod 26을 했을 때 결과가 -7이기 때문에 이것도 모듈러 역원에 해당하지만, 양의 정수 범위로 처리하려면 >0이 될 때까지 b의 값을 계속 더해줘야 제대로 된 값이 나온다.

```cpp
int extended_gcd(long long a, long long b, long long& x, long long& y)
{
    long long temp_x, temp_y;
    long long old_x = 1;
    long long old_y = 0;
    x = 0;
    y = 1;
    long long initial_b = b;

    while (b != 0)
    {
        long long q = a / b, r = a % b;

        a = b; b = r;

        temp_x = x, temp_y = y;
        x = old_x - q * x;
        y = old_y - q * y;
        old_x = temp_x;
        old_y = temp_y;
    }
    while (old_x < 0)
    {
        old_x += initial_b;
    }
    old_x %= initial_b;
    x = old_x; // 기존 x, y는 x_t+1, y_t+1이므로 이전으로 되돌리기
    y = old_y;

    return a;
}

long long mod_inverse(long long a, long long b)
{
    long long x, y;
    long long gcd = extended_gcd(a, b, x, y);
    if (gcd != -1 && gcd != 1)
        return -1;
    return x;
}
```

다만 위 식에서 y 값은 모듈러 역원을 구할 땐 사실상 필요가 없다. 따라서 모듈러 역원만 구하고자 한다면 old_x를 x로, x를 y로 대체하도록 하여 아래와 같이 처리할 수 있다.

```cpp
long long modInverse(long long a, long long n)
{
    long long t;
    long long x = 1;
    long long y = 0;
    long long n0 = n;

    while (n != 0)
    {
        long long q = a / n, r = a % n;

        a = n; n = r;

        t = y;
        y = x - q * y;
        x = t;
    }

    while (x < 0)
    {
        x += n0;
    }

    if (a != 1)
        return -1;
    else
        return x;
}
```
