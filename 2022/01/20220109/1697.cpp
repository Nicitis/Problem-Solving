// 백준 1697: 숨바꼭질
#include <iostream>
#include <algorithm>
#include <queue>

#define MAX_POS 200000

using namespace std;

bool visited[MAX_POS + 1] = { false };

struct PosTime
{
    int pos;
    int time;
};

int MinTimeToMeet(int n, int m)
{
    visited[n] = true;

    queue<struct PosTime> posQ;

    posQ.push({n, 0});

    while (!posQ.empty())
    {
        struct PosTime posTime = posQ.front();
        posQ.pop();

        visited[posTime.pos] = true;

        if (posTime.pos == m)
            return posTime.time;
        
        if (posTime.pos < MAX_POS && !visited[posTime.pos + 1])
            posQ.push({posTime.pos + 1, posTime.time + 1});
        if (posTime.pos <= MAX_POS / 2 && !visited[posTime.pos * 2])
            posQ.push({posTime.pos * 2, posTime.time + 1});
        if (posTime.pos > 0 && !visited[posTime.pos - 1])
            posQ.push({posTime.pos - 1, posTime.time + 1});
    }
    return abs(m - n);
}

int main()
{
    int n, m;
    cin >> n >> m;

    cout << MinTimeToMeet(n, m);

    return 0;
}