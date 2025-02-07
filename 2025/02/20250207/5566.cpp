#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;

    cin >> N >> M;

    int board[1000];

    for (int i = 0; i < N; i++)
    {
        cin >> board[i];
    }

    int cnt = 0;
    int pos = 0;
    int die = 0;
    
    for (int i = 1; i <= M; i++)
    {
        cin >> die;

        pos += die;
        if (pos < N)
            pos += board[pos];
        if (cnt == 0 && pos >= N - 1)
        {
            cnt = i;
        }
    }
    cout << cnt << '\n';

    return 0;
}