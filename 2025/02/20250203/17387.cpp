#include <iostream>
#include <algorithm>

using namespace std;

long long cross(int x1, int y1, int x2, int y2, int x3, int y3)
{
    long long z = 1LL * (x2-x1) * (y3-y1) - 1LL * (x3-x1) * (y2-y1);
    return z;
}

bool is_in_line(int x1, int y1, int x2, int y2, int x, int y)
{
    if (x == x1 && y == y1 || x == x2 && y == y2)
    {
        // cout << "x == x1 && y == y1 || x == x2 && y == y2: (x1, x2), (y1, y2), (x, y) = (" << x1 << ","<<y1 <<"),(" <<x2<<","<<y2<<"),("<<x<<","<<y<<")\n";
        return true;
    }
    
    if (cross(x1, y1, x2, y2, x, y) == 0)
    {
        if (x1 != x2 && min(x1, x2) < x && x < max(x1, x2))
        {
            // cout << "x1 != x2 && min(x1, x2) < x && x < max(x1, x2): x1, x2, x = " << x1 << ", " << x2 << ", " << x <<'\n';
            return true;
        }
        if (y1 != y2 && min(y1, y2) < y && y < max(y1, y2))
        {
            // cout << "y1 != y2 && min(y1, y2) < y && y < max(y1, y2): y1, y2, y = " << y1 << ", " << y2 << ", " << y <<'\n';
            return true;
        }
    }
    return false;
}

int main()
{
    int x1, x2, x3, x4, y1, y2, y3, y4;

    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;

    int answer = 0;

    if (is_in_line(x1, y1, x2, y2, x3, y3) || is_in_line(x1, y1, x2, y2, x4, y4))
    {
        answer = 1;
    }
    else if (is_in_line(x3, y3, x4, y4, x1, y1) || is_in_line(x3, y3, x4, y4, x2, y2))
    {
        answer = 1;
    }
    else
    {
        long long crossA = cross(x1, y1, x2, y2, x3, y3);
        long long crossB = cross(x1, y1, x2, y2, x4, y4);
        long long crossC = cross(x3, y3, x4, y4, x1, y1);
        long long crossD = cross(x3, y3, x4, y4, x2, y2);
        // cout << "crossA = " << crossA << ", crossB = " << crossB <<'\n';
        // cout << "crossC = " << crossC << ", crossD = " << crossD <<'\n';

        if ((crossA > 0 && crossB < 0 || crossA < 0 && crossB > 0) &&
            (crossC > 0 && crossD < 0 || crossC < 0 && crossD > 0))
            answer = 1;
    }

    cout << answer << '\n';

    return 0;
}