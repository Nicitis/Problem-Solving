#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

const double PI = std::acos(-1);

int px, py;

struct Point
{
    int x;
    int y;

    Point(int newX, int newY) : x(newX), y(newY) {}
};

double Compare(const Point & p1, const Point & p2)
{
    if (p1.x == px)
        cout << "p1.x == px\n";
    if (p2.x == px)
        cout << "p2.x == px\n";

    double rad1 = atan2(p1.y - py, p1.x - px);
    double rad2 = atan2(p2.y - py, p2.x - px);
    if (rad1 < 0) rad1 += 2 * PI;
    if (rad2 < 0) rad2 += 2 * PI;
    // double gap = rad1 < rad2 ? rad2 - rad1 : (rad2 - rad1 + PI);
    double gap = rad2 - rad1;
    cout << "rad1 : " << rad1 << ", rad2 : " << rad2 << ", gap = " << gap << '\n';
    gap = p2.x - p1.x;
    // if (rad1 == rad2)
    // {
    //     int sqrDist1 = (p1.x - px) * (p1.x - px) + (p1.y - py) * (p1.y - py);
    //     int sqrDist2 = (p2.x - px) * (p2.x - px) + (p2.y - py) * (p2.y - py);
    //     return sqrDist2 - sqrDist1;
    // }
    return gap;
}

bool ccw(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
    Point p1(x1, y1);
    Point p2(x2, y2);
    Point q1(x3, y3);
    Point q2(x4, y4);
    
    vector<Point> points;
    points.push_back(p1);
    points.push_back(p2);
    points.push_back(q1);
    points.push_back(q2);

    int pivotIdx = 0;

    // for (int i = 1; i < points.size(); i++)
    // {
    //     if (points[i].x > points[pivotIdx].x)
    //         pivotIdx = i;
    //     else if (points[i].x == points[pivotIdx].x && 
    //         points[i].y < points[pivotIdx].y)
    //         pivotIdx = i;
    // }
    pivotIdx = 1;
    px = points[pivotIdx].x;
    py = points[pivotIdx].y;
    
    sort(points.begin(), points.end(), Compare);

    cout << pivotIdx << '\n';
    for (int i = 0; i < points.size(); i++)
    {
        cout << i << ": (" << points[i].x << ", " << points[i].y << "), angle = " << 
            atan2(points[i].y - py, points[i].x - px) << "\n";
    }

    return false;
}

int main()
{
    int x1, x2, x3, x4, y1, y2, y3, y4;

    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;

    if (ccw(x1, y1, x2, y2, x3, y3, x4, y4))
        cout << "1\n";
    else
        cout << "0\n";

    return 0;
}