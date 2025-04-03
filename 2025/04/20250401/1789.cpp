#include <iostream>
#include <climits>

using namespace std;

int main()
{
    long long sum = 0, s, nextSum;

    cin >> s;

    for (int n = 1; n <= INT_MAX; n++)
    {
        nextSum = sum + n;
        if (sum <= s && s < nextSum)
        {
            cout << n - 1 << "\n";
            break;
        }
        sum = nextSum;
    }

    return 0;
}