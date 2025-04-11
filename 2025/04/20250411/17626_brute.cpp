#include <iostream>

using namespace std;

int main()
{
    int n;
    int sqrN[224], sqrtN;

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    // 1
    for (int i = 1; i * i <= n; i++)
    {
        sqrN[i] = i*i;
        sqrtN = i;
        if (sqrN[i] == n)
        {
            cout << "1\n";
            return 0;
        }
    }
    // 2
    for (int i = 1; i <= sqrtN; i++)
        for (int j = 1; j <= i; j++)
        {
            if (sqrN[i] + sqrN[j] == n)
            {
                cout << "2\n";
                return 0;
            }
            if (sqrN[i] + sqrN[j] > n)
                break;
        }
    // 3
    for (int i = 1; i <= sqrtN; i++)
        for (int j = 1; j <= i; j++)
            for (int k = 1; k <= j; k++)
            {
                if (sqrN[i] + sqrN[j] + sqrN[k] == n)
                {
                    cout << "3\n";
                    return 0;
                }
                if (sqrN[i] + sqrN[j] + sqrN[k] > n)
                    break;
            }
    
    cout << "4\n";

    return 0;
}