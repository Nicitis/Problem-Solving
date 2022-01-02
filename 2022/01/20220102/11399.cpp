// 백준 11399: ATM
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int MinTotalTime(vector<int>& times)
{
    int currTime = 0;
    int total = 0;

    sort(times.begin(), times.end());
    
    for (int i = 0; i < times.size(); i++)
    {
        currTime += times[i];
        total += currTime;
    }
    
    return total;
}

int main()
{
    int n;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    vector<int> timesPerPerson = vector<int>(n);

    for (int i = 0; i < n; i++)
        cin >> timesPerPerson[i];
    
    cout << MinTotalTime(timesPerPerson);

    return 0;
}