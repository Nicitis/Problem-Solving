#include <cstdio>
#include <algorithm>
#include <vector>

// 이진탐색, 찾을 경우 1, 아닐 경우 0
int binSearch(std::vector<int>& arr, int num)
{
    int lo = 0; // inclusive
    int hi = arr.size() - 1; // exclusive
    int mid;

    while (lo < hi)
    {
        mid = (lo + hi) / 2;
        if (arr[mid] == num)
            return 1;
        // 좌측 영역 탐색
        else if (num < arr[mid])
            hi = mid - 1;
        else
            lo = mid + 1;
    }
    if (arr[lo] == num)
        return 1;
    else
        return 0;
}

int main()
{
    int N, M, num;

    scanf("%d", &N);
    std::vector<int> arr(N, 0);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }

    std::sort(arr.begin(), arr.end());

    scanf("%d", &M);
    for (int i = 0; i < M; i++)
    {
        scanf("%d", &num);
        printf("%d\n", binSearch(arr, num));
    }

    return 0;
}