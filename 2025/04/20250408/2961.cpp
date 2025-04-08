#include <iostream>
#include <cmath>

#define MAX 1000000000

using namespace std;

int sour[10], bitter[10];
int n;

int GetMinimumDeltaBetweenTaste(int currentIdx, int totalSour, int totalBitter, bool choose)
{
    if (currentIdx >= n)
    {
        return choose ? abs(totalSour - totalBitter) : MAX;
    }
    
    // choose this ingredient
    int minDelta = GetMinimumDeltaBetweenTaste(
        currentIdx + 1, 
        totalSour * sour[currentIdx], 
        totalBitter + bitter[currentIdx], true);
    // don't choose this ingredient
    int other = GetMinimumDeltaBetweenTaste(
        currentIdx + 1, totalSour, totalBitter, choose);
    if (other < minDelta)
        minDelta = other;
    return minDelta;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> sour[i] >> bitter[i];
    }

    cout << GetMinimumDeltaBetweenTaste(0, 1, 0, false) << "\n";

    return 0;
}