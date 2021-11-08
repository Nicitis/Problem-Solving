// 백준 1149: RGB 거리(C++)
// 이전 집을 칠하는 색마다 최소 비용을 통해, 새로운 집을 칠하는 최소 비용을
// 계산한다.
// 이전 집에 대한 계산을 차곡차곡 쌓아가므로 dp를 통해 해결한다 할 수 있다.
#include <cstdio>
#define MIN(X, Y) ((X)<(Y)?(X):(Y))

#define R 0
#define G 1
#define B 2

int main()
{
    int n;
    int minCosts[3] = {0, 0, 0};

    scanf("%d", &n);

    // 각 집의 비용을 입력받을 때마다 최소 비용을 재계산한다.
    for (int i = 0; i < n; i++)
    {
        int r, g, b;
        scanf("%d %d %d", &r, &g, &b);
        
        // 칠하는 색마다 별도로 비용을 계산
        r += MIN(minCosts[G], minCosts[B]);
        g += MIN(minCosts[R], minCosts[B]);
        b += MIN(minCosts[R], minCosts[G]);

        // 계산이 끝난 후 최소 비용을 업데이트
        minCosts[R] = r;
        minCosts[G] = g;
        minCosts[B] = b;
    }

    printf("%d\n", MIN(minCosts[R], MIN(minCosts[G], minCosts[B])));
}