#include <iostream>
#include <queue>

#define PAIR pair<int, int>

using namespace std;

bool visit[100000];
int main()
{
    int n, k, minTime;
    cin >> n >> k;

    minTime = n >= k ? (n - k) : (k - n);
    
    priority_queue<PAIR, vector<PAIR>, greater<PAIR>> pq; // <pos, time>

    pq.push(make_pair(0, n));

    while (!pq.empty())
    {
        int time = pq.top().first;
        int pos = pq.top().second;
        pq.pop();

        visit[pos] = true;

        if (time >= minTime)
            break;
        if (pos >= k)
        {
            minTime = min(minTime, time + (pos - k));
            continue;
        }
        
        if ((pos * 2) >= k)
            minTime = min(minTime, time + ((pos * 2)-k));
        else if (!visit[pos * 2])
            pq.push(make_pair(time, pos * 2));
        
        if (!visit[pos - 1] && pos > 0)
            pq.push(make_pair(time + 1, pos - 1));
        if (!visit[pos + 1])
            pq.push(make_pair(time + 1, pos + 1));
    }

    cout << minTime << '\n';

    return 0;
}