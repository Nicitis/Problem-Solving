#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

#define POINT pair<int, int>

using namespace std;

double PI;
POINT pivot;

double getAngle(const POINT& p)
{
    int x = p.first - pivot.first;
    int y = p.second - pivot.second;
    if (x == 0)
    {
        return y > 0 ? PI * 0.5 : -PI * 0.5;
    }

    double angle = atan2(y, x);
    if (angle < 0)
        angle += 2 * PI;
    return angle;
}

struct PointComparer
{
public:
    bool operator()(const POINT& a, const POINT& b) const
    {
        double radA = getAngle(a);
        double radB = getAngle(b);
        if (radA == radB)
        {
            long long sqrDistA = (long long)(a.first - pivot.first) * (a.first - pivot.first) +
                (long long)(a.second - pivot.second) * (a.second - pivot.second);
            long long sqrDistB = (long long)(b.first - pivot.first) * (b.first - pivot.first) +
                (long long)(b.second - pivot.second) * (b.second - pivot.second);
            return sqrDistA < sqrDistB;
        }
        return radA < radB;
    }
};

bool IsCCW(const POINT& a, const POINT& b, const POINT& c)
{
    long long x1 = b.first - a.first;
    long long x2 = c.first - b.first;
    long long y1 = b.second - a.second;
    long long y2 = c.second - b.second;

    return (x1 * y2 - x2 * y1) > 0;
}

int main()
{
    int n, x, y;
    // <angle, <x, y>>
    POINT points[100000];
    PI = acos(-1.0);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int pivotIdx;

    cin >> n;

    // 1. Pivot 구하기
    for (int i = 0; i < n; i++)
    {
        cin >> points[i].first >> points[i].second;

        // 가장 우측(x가 같다면 y가 작은 쪽)의 점을 pivot으로 설정
        if (i == 0 ||
            points[pivotIdx].first < points[i].first ||
            points[pivotIdx].first == points[i].first && 
            points[pivotIdx].second > points[i].second)
            pivotIdx = i;
    }

    pivot = points[pivotIdx];
    // pivot은 리스트에서 제외
    if (pivotIdx != n - 1)
    {
        points[pivotIdx] = points[n - 1];
        points[n - 1] = pivot;
    }

    // 2. 각도에 따라 정렬(n - 1개)
    sort(points, points + (n - 1), PointComparer());

    // 3. 마지막 세 점이 반시계 방향이 맞는지 검사
    vector<int> convex;
    convex.push_back(n - 1); // push pivot
    for (int i = 0; i < n; i++) // pivot까지 검사하기 위해 i < n
    {
        while(convex.size() >= 2 && 
            !IsCCW(points[convex[convex.size() - 2]], 
                points[convex[convex.size() - 1]], 
                points[i]))
        {
            convex.pop_back();
        }
        convex.push_back(i);
    }

    cout << convex.size() - 1;
    
    return 0;
}