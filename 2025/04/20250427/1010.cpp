#include <iostream>

using namespace std;

int main()
{
    int n, m, T;

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    
    for (int t = 0; t < T; ++t)
    {
        long long result = 1LL;
        cin >> n >> m;
        // calculate mCn
        if (n > m - n)
            n = m - n;
        int div = n;
        
        for (int i = m; i > m - n; --i)
        {
            result *= i;
            while (div > 0 && result % div == 0)
            {
                result /= div;
                --div;
            }
        }
    
        cout << result << "\n";
    }

    return 0;
}