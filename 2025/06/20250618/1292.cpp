#include <iostream>

using namespace std;

int main()
{
    int a, b;
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> a >> b;

    int n = 1;
    int sum = 0;
    int cnt = 0;
    for (int i = 1; i <= b; i++)
    {
        if (i >= a)
        {
            sum += n;
        }
        cnt++;
        if (cnt >= n)
        {
            n++;
            cnt = 0;
        }
    }
    cout << sum;

    return 0;
}