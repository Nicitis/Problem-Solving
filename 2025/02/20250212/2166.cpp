#include <iostream>
#include <cmath>

using namespace std;

long double AreaOfTriangle(long double xa, long double ya, long double xb, long double yb, 
    long double xc, long double yc)
{
    return 0.5L * ((xb - xa) * (yc - ya) - (xc - xa) * (yb - ya));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, xp, yp, xa, ya, xb, yb;
    long double area = 0.0L;
    
    cin >> N;
    
    cin >> xp >> yp;
    cin >> xa >> ya;

    for (int i = 2; i < N; i++)
    {
        cin >> xb >> yb;

        area += AreaOfTriangle(xp, yp, xa, ya, xb, yb);

        xa = xb;
        ya = yb;
    }

    if (area < 0.0L)
        area = -area;
    area = roundl(area * 10L) * 0.1L;

    cout << fixed;
    cout.precision(1);
    cout << area;
    
    return 0;
}