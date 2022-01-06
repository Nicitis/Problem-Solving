// 백준 2261 틀린 문제 재풀이: 가장 가까운 두 점
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <climits>

using namespace std;

vector<pair<int, int>> points;
vector<pair<int, int>> candidate = vector<pair<int, int>>();

int GetSqrDistance(pair<int, int> point1, pair<int, int> point2)
{
    return (point2.first - point1.first) * (point2.first - point1.first) +
        (point2.second - point1.second) * (point2.second - point1.second);
}

int Compare(pair<int, int> a, pair<int, int> b) 
{
    return a.second < b.second;
}

int BruteForce(int start, int end)
{
    int nearest = INT_MAX;
    for (int i = start; i <= end - 1; i++)
    {
        for (int j = i + 1; j <= end; j++)
        {
            nearest = min(nearest, GetSqrDistance(points[i], points[j]));
        }
    }
    return nearest;
}

// 인덱스를 받아 영역을 반으로 나누고, 분할정복 방식으로 최근접쌍을 구한다.(end는 inclusive)
int GetNearestDistance(int start, int end)
{
    if (end - start + 1 <= 3)
    {
        return BruteForce(start, end);
    }

    // 왼쪽 오른쪽 분할
    int mid = (start + end) / 2;
    int minDist = min(GetNearestDistance(start, mid), 
        GetNearestDistance(mid + 1, end));

    // 가운데 점으로부터 x 방향으로 minDist 거리 내에 있는 모든 점을 후보군에 추가한다.
    int center = (points[mid].first + points[mid + 1].first) / 2;

    candidate.clear();

    for (int i = start; i <= end; i++)
    {
        int xDist = points[i].first - center;
        if (xDist * xDist < minDist)
            candidate.push_back({points[i].first, points[i].second});
    }

    sort(candidate.begin(), candidate.end(), Compare);

    // y 값의 차가 minDist 이상이 되면 거리 비교를 중단한다. 그렇지 않은 점에 대해 최단거리를 계산한다.
    int len = candidate.size();
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            int yDist = candidate[j].second - candidate[i].second;
            if (yDist * yDist >= minDist)
                break;
            minDist = min(minDist, GetSqrDistance(candidate[i], candidate[j]));
        }
    }

    return minDist;
}

int main()
{
    int n;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    points = vector<pair<int, int>>(n);

    for (int i = 0; i < n; i++)
    {
        cin >> points[i].first >> points[i].second;
    }

    sort(points.begin(), points.end()); // 0번 점을 제외

    cout << GetNearestDistance(0, n - 1);

    return 0;
}