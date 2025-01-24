#include <iostream>
#include <climits>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, S;
    cin >> N >> S;

    int accArr[100001];
    accArr[0] = 0;
    int seqTotal = 0;

    for (int i = 1; i <= N; i++)
    {
        cin >> accArr[i];
        accArr[i] += accArr[i - 1];
    }

    int start = 0, shortestLength = INT_MAX;
    for (int i = 1; i <= N; i++)
    {
        while (accArr[i] - accArr[start] >= S)
        {
            if (i - start < shortestLength)
            {
                shortestLength = i - start;
            }
            start++;
        }
    }
    if (shortestLength == INT_MAX)
    {
        cout << "0\n";
    }
    else
    {
        cout << shortestLength << '\n';
    }

    return 0;
}