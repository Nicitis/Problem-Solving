// 2023.03.10., 강의실 배정, https://www.acmicpc.net/problem/11000
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> start(n, 0);
    vector<int> end(n, 0);

    for (int i = 0; i < n; i++)
        cin >> start[i] >> end[i];
    
    sort(start.begin(), start.end());
    sort(end.begin(), end.end());

    int j = 0;
    int maxLectures = 0;
    int lectures = 0;
    for (int i = 0; i < n; i++)
    {
        while (j < n && end[j] <= start[i])
        {
            lectures--;
            j++;
        }
        lectures++;
        if (maxLectures < lectures)
            maxLectures = lectures;
    }

    cout << maxLectures << '\n';

    return 0;
}