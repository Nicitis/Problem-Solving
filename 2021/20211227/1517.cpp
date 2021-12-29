// 백준 1517: 버블 소트
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;
vector<int> sortedArray;

// 병합 후 버블 소트 상에서 swap이 몇 번 일어나는지 분할정복 방법으로 계산한다.(start는 inclusive, end는 exclusive)
long long MergeAndCount(int start, int end)
{
    if (start + 1 == end)
    {
        sortedArray[start] = arr[start];
        return 0ll;
    }
    
    int mid = (start + end) / 2;
    long long count = MergeAndCount(start, mid) + MergeAndCount(mid, end);

    int l = start, r = mid;
    int currIdx = start;
    
    while (l < mid && r < end)
    {
        if (arr[l] <= arr[r])
        {
            sortedArray[currIdx++] = arr[l++];
        }
        else // 오른쪽이 더 작을 경우, 왼쪽의 남은 배열 길이만큼 count를 증가
        {
            count += mid - l;
            sortedArray[currIdx++] = arr[r++];
        }
    }
    while (l < mid)
    {
        sortedArray[currIdx++] = arr[l++];
    }
    while (r < end)
    {
        sortedArray[currIdx++] = arr[r++];
    }

    // arr에 붙여넣기
    copy(sortedArray.begin() + start, sortedArray.begin() + end, arr.begin() + start);

    return count;
}

int main()
{
    int n;
    cin >> n;
    arr = vector<int>(n);
    sortedArray = vector<int>(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << MergeAndCount(0, n);
    
    return 0;
}