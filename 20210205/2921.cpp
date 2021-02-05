// 2. 백준 2921 도미노(https://www.acmicpc.net/problem/2921)
#include <cstdio>

int main()
{
    // a + b = i (1 <= i <= N)에 관해 모든 조합을 구하고 거기에서 i를 더한다.
    int N;
    scanf("%d", &N);
    // int result = 0;
    // for (int i = 1; i <= N; i++)
    // {
    //     for (int j = 0; j <= i; j++)
    //     {
    //         result += i + j;
    //     }
    // }
    // 기존 풀이법
    // printf("%d\n", result);

    // 수학적 풀이법
    // 식: 시그마 (i = 1 ~ N) 시그마 (j = 0 ~ i) (i+j) = N * (N + 1) * (2N + 4) / 4
    printf("%d\n", N * (N + 1) * (2 * N + 4) / 4);

    return 0;
}