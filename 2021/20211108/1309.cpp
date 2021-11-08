// 백준 1309: 동물원
// N = x일 때의 방법의 수는 N = (x - 1)일 때의 방법의 수에 의존한다.
// 따라서 N의 값을 하나씩 높여가며 bottom-up 방식으로 풀이
/*
1. N이 증가할 때마다 가장 하단에 2x1 모양 우리를 추가함
2. 가장 하단의 우리 모양에 따라 다음에 추가 가능한 우리 모양이 제한됨
(우리 모양: 비어 있음, 왼쪽에 배치, 오른쪽에 배치)
3. 따라서 가장 하단의 우리의 모양마다 경우의 수를 따로 세어준다.

모양을 E, L, R로 정의한다.
E: 좌우가 모두 비어 있음
L: 왼쪽에 사자를 배치
R: 오른쪽에 사자를 배치

f(N, '우리 모양')을 2*N 배열에서 최하단이 입력된 우리 모양일 때 
배치가능한 경우의 수라 할 때,

f(N, E) = f(N-1, E) + f(N-1, L) + f(N-1, R)
f(N, L) = f(N-1, E) + f(N-1, R)
f(N, R) = f(N-1, E) + f(N-1, L)
*/
#include <cstdio>

#define E 0
#define L 1
#define R 2
#define MOD 9901

int main()
{
    int n, dp[3] = { 1, 1, 1 }; // 각 방법의 수는 1가지

    scanf("%d", &n);

    for (int i = 2; i <= n; i++)
    {
        // 마지막 우리 모양에 따라 방법의 수를 다르게 세어준다.
        int e, l, r;
        e = dp[E] + dp[L] + dp[R];
        l = dp[E] + dp[R];
        r = dp[E] + dp[L];

        dp[E] = e % MOD;
        dp[L] = l % MOD;
        dp[R] = r % MOD;
    }
    printf("%d", (dp[E] + dp[L] + dp[R]) % MOD);
}