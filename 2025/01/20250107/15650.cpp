#include <iostream>

using namespace std;

int seq[8];

void NextSequence(int lastNumber, int n, int m, int index)
{
    if (index == m)
    {
        for (int i = 0; i < m; i++)
        {
            if (i != 0)
                cout << ' ';
            cout << seq[i];
        }
        cout << '\n';
        return;
    }

    int remained = m - index;
    for (int i = lastNumber + 1; i <= n - remained + 1; i++)
    {
        seq[index] = i;
        NextSequence(i, n, m, index + 1);
    }
}

int main()
{
    int N, M;

    ios_base::sync_with_stdio(false);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 1; i <= N - M + 1; i++)
    {
        seq[0] = i;
        NextSequence(i, N, M, 1);
    }

    return 0;
}