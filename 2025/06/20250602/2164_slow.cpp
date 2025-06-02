#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }

    while (q.size() > 1)
    {
        q.pop();
        int top = q.front();
        q.pop();
        q.push(top);
    }

    cout << q.front();

    return 0;
}