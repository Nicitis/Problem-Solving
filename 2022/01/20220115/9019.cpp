// 백준 9019: DSLR
#include <iostream>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

struct InstructNode
{
    int number;
    int length;
    string instruct;
};

bool visit[10000];

int GetDouble(int number)
{
    return (number * 2) % 10000;
}

int GetSubtract(int number)
{
    number--;
    if (number < 0)
        number = 9999;
    return number;
}

int GetLShift(int number)
{
    return (number * 10) % 10000 + number / 1000;
}

int GetRShift(int number)
{
    return number / 10 + (number % 10) * 1000;
}

// BFS 방식으로 탐색한다.
void ShortestDSLR(int start, int end, string& result)
{
    queue<struct InstructNode> q;
    int next;

    visit[start] = true;
    struct InstructNode node = { start, 0, "" };
    q.push(node);

    while (!q.empty())
    {
        struct InstructNode node = q.front();
        q.pop();

        if (node.number == end)
        {
            result = string(node.instruct);
            return;
        }
        
        next = GetDouble(node.number); // D
        if (visit[next] == false)
        {
            visit[next] = true;
            q.push({ next, node.length + 1, node.instruct + "D" });
        }
        next = GetSubtract(node.number); // S
        if (visit[next] == false)
        {
            visit[next] = true;
            q.push({ next, node.length + 1, node.instruct + "S" });
        }
        next = GetLShift(node.number); // L
        if (visit[next] == false)
        {
            visit[next] = true;
            q.push({ next, node.length + 1, node.instruct + "L" });
        }
        next = GetRShift(node.number); // R
        if (visit[next] == false)
        {
            visit[next] = true;
            q.push({ next, node.length + 1, node.instruct + "R" });
        }
    }
}

int main()
{
    int t, start, end;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> start >> end;
        string instruct;
        ShortestDSLR(start, end, instruct);
        cout << instruct << '\n';

        memset(visit, (int)false, sizeof(visit));
    }

    return 0;
}