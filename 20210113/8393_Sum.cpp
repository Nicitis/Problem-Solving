// Backjoon 8393 합(https://www.acmicpc.net/problem/8393)
#include <iostream>
using namespace std;
int main()
{
    int n, sum = 0;

    cin >> n;

    for (int i = 1; i <= n; i++)
        sum += i;

    cout << sum << '\n';

    return 0;
}