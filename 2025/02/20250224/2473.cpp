#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int liquid[5000];
int first, second, third;

long long FindMinimumCombination(int begin, int end)
{
    long long dest = -liquid[begin];
    long long minCost = LLONG_MAX;
    int left = begin + 1, right = end - 1;

    first = liquid[begin];

    while (left < right)
    {
        long long sum = liquid[left] + liquid[right];
        long long cost = sum - dest;
        if (abs(cost) < minCost)
        {
            minCost = abs(cost);
            second = liquid[left];
            third = liquid[right];
        }

        if (cost < 0)
            left++;
        else if (cost > 0)
            right--;
        else
            return cost;
    }
    return minCost;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, answer[3];
    long long minCost = LLONG_MAX;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> liquid[i];
    }

    sort(liquid, liquid + n);

    for (int i = 0; i < n - 2; i++)
    {
        long long cost = FindMinimumCombination(i, n);
        if (cost < minCost)
        {
            minCost = cost;
            answer[0] = first;
            answer[1] = second;
            answer[2] = third;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        cout << answer[i] << ' ';
    }
    cout << '\n';

    return 0;
}