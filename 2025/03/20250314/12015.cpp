#include <iostream>
#include <algorithm>

using namespace std;

int lis[1000000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, size = 0, last;
    cin >> n;

    cin >> lis[size++];

    for (int i = 1; i < n; i++)
    {
        cin >> last;
        if (lis[size - 1] < last)
        {
            lis[size++] = last;
        }
        else
        {
            int* it = lower_bound(lis, lis + size, last);
            *it = last;
        }
    }

    cout << size << '\n';

    return 0;
}