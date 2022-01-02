// 백준 2261: 가장 가까운 두 점
// 반례: https://www.acmicpc.net/board/view/74769 나중에 살펴보자
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

#define MIN(X, Y) ((X)<=(Y)?(X):(Y))

using namespace std;

vector<pair<int, int>> points;

int GetDistance(pair<int, int> point1, pair<int, int> point2)
{
    return (point2.first - point1.first) * (point2.first - point1.first) +
        (point2.second - point1.second) * (point2.second - point1.second);
}

// int GetNearestDistanceByONSquare(int start, int end)
// {
//     int l = start;
//     int r = start + 1;
//     int nearest = 987654321;
//     while (l < end)
//     {
//         r = l + 1;
//         while (r <= end)
//         {
//             int temp = nearest;
//             nearest = MIN(nearest, GetDistance(points[l], points[r]));
//             if (temp != nearest)
//                 cout << "refresh! (" << points[l].first << ", " << points[l].second << "), (" << points[r].first << ", " << points[r].second << ") distance : " << nearest << '\n';
//             r++;
//         }
//         l++;
//     }
//     return nearest;
// }

// 인덱스를 받아 영역을 반으로 나누고, 분할정복 방식으로 최근접쌍을 구한다.
// end는 inclusive
int GetNearestDistance(int start, int end)
{
    if (start + 1 == end)
    {
        return GetDistance(points[start], points[end]);
    }

    // 왼쪽 오른쪽 분할
    int mid = (start + end) / 2;
    int minDist = 987654321;
    if (start < mid)
    {
        minDist = MIN(minDist, GetNearestDistance(start, mid));
    }
    if (mid < end)
    {
        minDist = MIN(minDist, GetNearestDistance(mid, end));
    }

    // 병합
    for (int l = start; l <= mid; l++)
    {
        int r = mid + 1;
        while (r <= end)
        {
            // x의 차가 최단 거리보다 작은 점에 대해서만 검사한다.(시간초과 발생)
            if ((points[r].first - points[l].first) * (points[r].first - points[l].first) < minDist)
                minDist = MIN(minDist, GetDistance(points[l], points[r]));
            else
                break;
            r++;
        }
    }

    return minDist;
}

int main()
{
    int n;
    cin >> n;
    points = vector<pair<int, int>>(n + 1, make_pair(0, 0));

    for (int i = 1; i <= n; i++)
    {
        cin >> points[i].first >> points[i].second;
    }

    sort(points.begin() + 1, points.end()); // 0번 점을 제외

    // cout << "=== after sorting ===\n";

    // for (int i = 1; i <= n; i++)
    // {
    //     cout << "(" << points[i].first << ", "<< points[i].second << ")\n";
    // }

    // cout << "what was actually got " << GetNearestDistance(1, n) << '\n';
    // cout << "what was expected " << GetNearestDistanceByONSquare(1, n);
    
    cout << GetNearestDistance(1, n);

    return 0;
}