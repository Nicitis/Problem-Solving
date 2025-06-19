#include <iostream>

using namespace std;

int main()
{
    int n, a, b;
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> a >> b;
    
    int x[1001][1001];
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> x[i][j];
        }
    }
    
    for (int i = 1; i <= n; i++)
    {
        if (x[a][i] > x[a][b] || x[i][b] > x[a][b])
        {
            cout << "ANGRY";
            return 0;
        }
    }
    
    cout << "HAPPY";
    
    return 0;
}