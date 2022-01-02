// 백준 1744: 수 묶기
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, arr[50] = { 0 };
    long long total = 0;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n, [](int a, int b) { return a >= b; });

    for (int i = 0; i < n; i++)
    {
        if (i + 1 == n)
        {
            total += arr[i];
            break;
        }
        int mul = arr[i] * arr[i + 1];
        // 둘 다 양수
        if (arr[i] > 0 && arr[i + 1] > 0)
        {
            total += max(mul, arr[i] + arr[i + 1]);
            i++;
        }
        // 둘 다 음수
        else if (arr[i] < 0 && arr[i + 1] < 0)
        {
            // 음수가 홀수 개 남았으면 하나를 더한다
            if ((n - i) % 2 == 1)
                total += arr[i];
            else
            {
                total += mul;
                i++;
            }
        }
        // 하나가 0이면...
        else if (arr[i] == 0 || arr[i + 1] == 0)
        {
            // 첫 번째 수가 0이고 두 번째 수가 음수라면, 음수가 홀수개라면 곱하고 짝수개라면 무시한다.
            if (arr[i] == 0 && arr[i + 1] < 0)
            {
                if ((n - (i + 1)) % 2 == 1)
                {
                    total += mul;
                    i++;
                }
            }
            // 그 경우가 아니라면 더한다.
            else
            {
                total += arr[i];
            }
        }
        // 양수, 음수
        else
        {
            total += arr[i];
        }
    }

    cout << total << '\n';

    return 0;
}