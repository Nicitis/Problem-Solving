#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, m, d;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> d;
    int height[1000]; // 현재 행
    int prevHeight[1000]; // 이전 행의 높이

    for (int j = 0; j < m; j++)
        cin >> prevHeight[j];
    sort(prevHeight, prevHeight+m);

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> height[j];
            height[j] += i * d;
        }

        sort(height, height+m);
        
        for (int j = 0; j < m; j++)
        {
            if (!(prevHeight[j] < height[j]))
            {
                cout << "NO";
                return 0;
            }
            prevHeight[j] = height[j];
        }
    }
    cout << "YES";
    

    return 0;
}