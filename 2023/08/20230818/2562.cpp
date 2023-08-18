// 2023.08.18., 백준 2562 최댓값, https://www.acmicpc.net/problem/2562
#include <iostream>

using namespace std;

int main()
{
    int i, n, max = 0, max_order;
    for (i = 1; i <= 9; i++)
    {
        cin >> n;
        if (n > max)
        {
            max = n;
            max_order = i;
        }
    }
    cout << max << '\n' 
        << max_order << '\n';
}