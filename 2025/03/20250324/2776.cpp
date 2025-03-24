#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int BinarySearch(int n, int arr[], int target)
{
    int low = 0, high = n - 1, mid;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (arr[mid] > target)
        {
            high = mid - 1;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else // arr[mid] == target
        {
            return 1;
        }
    }
    return 0;
}

int arr[1000000];
int main()
{
    int t, n, m, input;

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;

    while (t--)
    {
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr + n);

        cin >> m;

        for (int i = 0; i < m; i++)
        {
            cin >> input;
            cout << BinarySearch(n, arr, input) << '\n';
        }
    }

    return 0;
}