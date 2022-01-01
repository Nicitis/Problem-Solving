// 백준 2110: 공유기 설치(C++)
// 1. 정답 값이 유한하고(특히 정수 범위),
// 2. 정답 값에 따라 가정이 참이 되거나 거짓이 되며
// 3. 가정 값에 비례하여 가정이 참이 될 가능성이 높아진다면 '이진탐색' 문제일 가능성이 있다.
// 해당 문제는 인접 최소 거리를 최대로 하는 문제이다.
// 1. 인접 최소 거리의 값이 정해져 있고 2. 인접 최소 거리가 충분히 짧을 때 인접 최소 거리가 유효해지며, 3. 인접 최소 거리를 짧게 잡을수록 공유기를 배치할 가능성도 높아진다.
// 따라서 이진탐색 문제로 해결할 수 있다.
#include <iostream>
#include <vector>
#include <algorithm>

#define LEN 200000
#define MAX 1000000000
#define UNDEFINED -1

using namespace std;

int arr[LEN];

bool CanSetup(int adj, int n, int c)
{
    int last = 0; // 첫 집에는 무조건 공유기 설치
    c--;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] - arr[last] >= adj)
        {
            last = i;
            c--;
            if (c == 0)
                return true;
        }
    }
    return false;
}

int BinarySearch(int n, int c)
{
    // 최단 인접거리 값을 가정하고 가능한지를 계속 테스트한다.
    int answer = 0;
    int low = 0, high = MAX, mid;

    while (low <= high)
    {
        mid = (high + low) / 2;
        // 가능한가?

        if (CanSetup(mid, n, c))
        {
            low = mid + 1;
            answer = mid;
        }
        else
            high = mid - 1;
    }

    return answer;
}

int main()
{
    int n, c;
    cin >> n >> c;
    
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);

    cout << BinarySearch(n, c);

    return 0;
}