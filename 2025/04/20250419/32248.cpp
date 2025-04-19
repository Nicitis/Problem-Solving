#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main()
{
    vector<int> cycle;
    int n;
    long long t;

    int a[101];
    bool visited[101];

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> t;
    long long startT = t;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    memset(visited, (int)false, sizeof(visited));   

    // 1. cycle을 찾을 때까지 진행
    int x = 1;
    while (!visited[x])
    {
        if (t <= 0)
        {
            cout << x;
            return 0;
        }
        visited[x] = true;
        x = a[x];
        t--;
    }

    // 2. cycle의 길이 및 구성요소 계산
    int start = x;
    do
    {
        cycle.push_back(x);
        x = a[x];
    } while (x != start);

    // 3. cycle의 시작보다 t가 크거나 같으면, 적절히 계산
    cout << cycle[t % cycle.size()];
    

    return 0;
}