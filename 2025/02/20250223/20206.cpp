#include <iostream>

using namespace std;

bool IsMovingOnDangerousArea(int a, int b, int c, 
    int x1, int x2, int y1, int y2)
{
    if (a == 0)
    {
        double y = -c / (double)b;
        return y1 < y && y < y2;
    }
    if (b == 0)
    {
        double x = -c / (double)a;
        return x1 < x && x < x2;
    }

    double y_left, y_right;
    y_left = (a * x1 + c) / -b;
    y_right = (a * x2 + c) / -b;

    return (y_left < y2 && y_right > y1) ||
        (y_left > y1 && y_right < y2);
}

int main()
{
    int a, b, c, x1, x2, y1, y2;

    cin >> a >> b >> c;
    cin >> x1 >> x2 >> y1 >> y2;

    if (IsMovingOnDangerousArea(a, b, c, x1, x2, y1, y2))
        cout << "Poor\n";
    else
        cout << "Lucky\n";

    return 0;
}