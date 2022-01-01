// 백준 13398: 연속합 2
// 문제: 무슨 수를 제거해야 연속합이 최대가 되는가?
// 제거하기 이전의 값에서 이웃한 값을 제거한다고 하더라도 최대가 된다는 보장이 없다.
// 그러면 '모든 수를 제거해봐야' 아는 거 아닌가?
// O(N^2)의 알고리즘으로는 해결하기 벅찰 수 있으므로 최대한 최적화해야 함.
// (10만 * 10만 = 10억 > 1억. 보통 1억 번의 IO가 최대 maximum으로 잡힘).

// 수를 하나 추가할 때마다 연속합을 새로 구한다.
// dp 방식으로 1번째 원소부터 i번째 원소까지의 합을 저장한 sum 배열 사용
// 원소 하나를 추가할 때마다 그 수에 대한 연속합을 구하고,
// 범위 시작 지점부터 자기 원소 직전의 원소까지의 수를 제거했을 때의
// 연속합을 구한다.
// i번째 원소부터 j번째 원소까지의 연속합은 dp[i-1] + dp[j]로 구한다.
// dp[0]은 기본 값 0으로 설정한다(첫 원소부터 연속합을 구할 때 사용).
// sum 값이 가장 작아지는 지점을 min index로 지정하여, 연속합의 시작 직전
// 지점으로 정한다.
// 만약 min index에 있는 값을 제거한다면 그 이전 구간에 있는 sum 중 
// 최솟값을 찾아 연속합 구간의 시작 직전 지점으로 정한다.
// 연속합은 최대 1억이므로 int로 저장할 수 있다.
/* 테스트 케이스
10
10 -4 3 1 5 6 -35 12 21 -1

1
0

1
-1

1
1

5
-3 -2 -1 -2 -3

10
-1000 -1000 -1000 -1000 -1000 -1000 -1000 -1000 -1000 -1000

1000
1000 -1000 1000 -1000 ...
*/
#include <cstdio>
#define MAX(X, Y) ((X)>(Y)?(X):(Y))

int continuous_sum(int sum[], int start, int end)
{
    return sum[end] - sum[start - 1];
}

int main()
{
    int n, seq[100001] = { 0 }, sum[100001] = { 0 }, 
        min_idx = 0, max_cont_sum = -1000, prev_min_idx = 0;

    // 입력 및 sum 배열을 구함
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &seq[i]);
        sum[i] = sum[i - 1] + seq[i];
    }
    
    for (int i = 1; i <= n; i++)
    {
        // 연속합을 구한다.
        max_cont_sum = MAX(max_cont_sum, 
            continuous_sum(sum, min_idx + 1, i));

        // 수 하나를 제거했을 때의 연속합을 구함(min_idx부터 시작, 단 min_idx가 0이면 다음 원소부터 제거)
        for (int k = min_idx; k < i; k++)
        {
            // 0번째 원소이거나 양수인 원소는 넘어감(제거할 필요가 없음)
            if (k == 0 || seq[k] >= 0)
                continue;
            
            // 만약 min_idx의 원소를 제거한다면, 구간 시작지점을 재설정하고 구함
            if (k == min_idx)
                max_cont_sum = MAX(max_cont_sum, 
                    continuous_sum(sum, prev_min_idx + 1, i) 
                    - seq[k]);
            else
            {
                // 일반 원소 제거
                max_cont_sum = MAX(max_cont_sum, 
                    continuous_sum(sum, min_idx + 1, i) - seq[k]);
            }
        }

        // min_idx를 갱신한다.
        if (sum[i] <= sum[min_idx])
        {
            prev_min_idx = min_idx;
            min_idx = i;
        }
    }

    printf("%d", max_cont_sum);
}