// 백준 5014: 스타트링크(C++)
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#define FAIL -1

using namespace std;

int MinButton(int f, int start, int dst, int up, int down)
{
    queue<pair<int, int>> q;

    q.push(make_pair(start, 0));
    vector<bool> mark(f + 1, false);
    mark[start] = true;

    while (!q.empty())
    {
        int cur = q.front().first;
        int count = q.front().second;
        q.pop();

        if (cur == dst)
            return count;

        // 위층으로
        if (cur + up <= f && !mark[cur + up])
        {
            q.push(make_pair(cur + up, count + 1));
            mark[cur + up] = true;
        }

        // 아래층으로
        if (cur - down >= 1 && !mark[cur - down])
        {
            q.push(make_pair(cur - down, count + 1));
            mark[cur - down] = true;
        }
    }
    return FAIL;
}

int main()
{
    int f, s, g, u, d;
    cin >> f >> s >> g >> u >> d;

    int minCount = MinButton(f, s, g, u, d);

    if (minCount != FAIL)
        cout << minCount;
    else
        cout << "use the stairs";

    return 0;
}