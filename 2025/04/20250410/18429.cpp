#include <iostream>

#define THRESHOLD 500

using namespace std;

int n, k;
int a[50];
bool canUse[50];

int FindCases(int idx, int currentWeight)
{
    if (idx >= n)
        return 1;
    int cases = 0;
    currentWeight -= k;

    for (int i = 0; i < n; i++)
    {
        if (!canUse[i] || currentWeight + a[i] < THRESHOLD)
            continue;
        canUse[i] = false;
        cases += FindCases(idx + 1, currentWeight + a[i]);
        canUse[i] = true;
    }
    return cases;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        canUse[i] = true;
    }

    cout << FindCases(0, 500) << "\n";

    return 0;
}