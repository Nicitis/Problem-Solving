// 백준 1931: 회의실 배정
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

vector<pair<int, int>> schedules;

int MaxSchedules(int n)
{
    int result = 0;
    int lastTime = 0;

    // for (auto s : schedules) // segment fault 발생
    for (int i = 0; i < n; i++)
    {
        auto s = schedules[i];
        if (lastTime <= s.first)
        {
            lastTime = s.second;
            result++;
        }
    }

    return result;
}

int main()
{
    int n;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    schedules = vector<pair<int, int>>(n);

    for (int i = 0; i < n; i++)
        cin >> schedules[i].first >> schedules[i].second;

    sort(schedules.begin(), schedules.end(),
        [](pair<int, int> a, pair<int, int> b) 
        {
            if (a.second < b.second)
                return true;
            else if (a.second == b.second && a.first <= b.first)
                return true;
            return false;
        }); // 우선 second를 오름차순 정렬하고, second가 같으면 first를 오름차순으로 정렬한다.
    
    cout << MaxSchedules(n);

    return 0;
}