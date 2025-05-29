/*
100 * 99 * 98 < 1,000,000번의 연산에 세 개의 수를
구할 수 있다. 즉, N^3 알고리즘임
다만, N log N으로 일단 먼저 정렬한 다음에 계산하면
합이 M을 넘을 경우 중단하면 된다.
좀 더 빨리 할 방법이 있을까?
이진 탐색을 쓴다면 어떨까?
두 개 수를 고르고 난 후에는, 마지막 수는 logN의 시간에
탐색이 가능하다.
일단 N^3으로 만들고 최적화하자.
*/

#include <iostream>
#include <algorithm>

using namespace std;

int arr[100] = { 0 };
int n, m;

void choose3BelowM(int idx, int remained, int sum, int& maximumSum)
{
    if (remained == 0)
    {
        if (sum > maximumSum)
            maximumSum = sum;
        return;
    }

    for (int i = idx; i < n - remained + 1; i++)
    {
        if (sum + arr[i] > m)
            break;
        choose3BelowM(i + 1, remained - 1, sum + arr[i], maximumSum);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);
    
    int maximum = 0;
    choose3BelowM(0, 3, 0, maximum);

    cout << maximum;

    return 0;
}