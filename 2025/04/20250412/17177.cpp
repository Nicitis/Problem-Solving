#include <iostream>

using namespace std;


int main()
{
    int ans = -1, a, b, c;

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> a >> b >> c;

    for (int d = 1; d < a; d++)
    {
        int eq;
        // a와 d가 마주 보는 경우
        eq = (a * a - c * c) * (a * a - b * b) - (a * a * d * d + 2 * a * b * c * d + b * b * c * c);
        if (eq == 0)
        {
            ans = d;
            break;
        }
        
        // b와 d가 마주 보는 경우
        eq = (a * a - d * d) * (a * a - b * b) - (a * a * c * c  + 2 * a * b * c * d + b * b * d * d);
        if (eq == 0)
        {
            ans = d;
            break;
        }

        // c와 d가 마주 보는 경우
        eq = (a * a - c * c) * (a * a - d * d) - (a * a * b * b + 2 * a * b * c * d + c * c * d * d);
        if (eq == 0)
        {
            ans = d;
            break;
        }
    }
    
    cout << ans << "\n";

    return 0;
}