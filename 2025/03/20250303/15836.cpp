#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n, p, q, cases = 1;

    int matA[20][20], matB[20][20];

    while (true)
    {
        cin >> m >> n >> p >> q;
    
        if (m == 0 && n == 0 && p == 0 && q == 0)
            break;
        
        cout << "Case #" << cases++ << ":\n";
            
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                cin >> matA[i][j];
            
        for (int i = 0; i < p; i++)
            for (int j = 0; j < q; j++)
                cin >> matB[i][j];
        
        if (n != p)
        {
            cout << "undefined\n";
            continue;
        }

        for (int i = 0; i < m; i++)
        {
            cout << "| ";
            for (int j = 0; j < q; j++)
            {
                int c = 0;
                for (int k = 0; k < n; k++)
                {
                    c += matA[i][k] * matB[k][j];
                }
                cout << c << ' ';
            }
            cout << "|\n";
        }
    }

    return 0;
}