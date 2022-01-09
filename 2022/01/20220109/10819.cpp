// 백준 10819: 차이를 최대로
#include <iostream>
#include <vector>
#include <algorithm>

#define IGNORE_VAL -987654321

using namespace std;

int MaxSubtract(vector<int>& list, int prevElem, int size)
{
    int maxSum = 0;
    for (int i = 0; i < size; i++)
    {
        if (list[i] == IGNORE_VAL)
            continue;
        int currElem = list[i];
        list[i] = IGNORE_VAL;
        maxSum = max(maxSum, abs(prevElem - currElem) + MaxSubtract(list, currElem, size));
        list[i] = currElem;
    }

    return maxSum;
}

int main()
{
    int n, maxSum = 0;

    cin >> n;

    vector<int> list(n, 0);

    for (int i = 0; i < n; i++)
        cin >> list[i];

    for (int i = 0; i < n; i++)
    {
        int elem = list[i];
        list[i] = IGNORE_VAL;
        maxSum = max(maxSum, MaxSubtract(list, elem, n));
        list[i] = elem;
    }
    cout << maxSum;

    return 0;
}