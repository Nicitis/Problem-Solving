#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    bool check[501];
    int K, P, M;

    cin >> K;

    for (int i = 0; i < K; i++)
    {
        int unavailableSeats = 0, seat;
        memset(check, 0, sizeof(check));
        
        cin >> P >> M;

        for (int j = 0; j < P; j++)
        {
            cin >> seat;
            if (check[seat])
                unavailableSeats++;
            else
                check[seat] = true;
        }
        cout << unavailableSeats << '\n';
    }

    return 0;
}