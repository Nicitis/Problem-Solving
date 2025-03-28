#include <iostream>

using namespace std;

int main()
{
    int x, k, color;

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> x >> k;
    long long l[10001] = { 0 };
    long long r[10001] = { 0 };

    for (int i = 0; i < x; i++)
    {
        cin >> color;
        l[color]++;
    }
    for (int i = 0; i < x; i++)
    {
        cin >> color;
        r[color]++;
    }
    
    long long answer = (long long)x * (long long)x;
    for (int i = 1; i <= k; i++)
    {
        if (l[i] != 0 && r[i] != 0)
            answer -= l[i] * r[i];
    }
    cout << answer << "\n";

    return 0;
}