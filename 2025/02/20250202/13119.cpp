#include <iostream>
#include <vector>
#include <string>

#define MOUNTAIN 35
#define TUNNEL 42
#define BRIDGE 45
#define EMPTY 46
#define SUPPORT 124

using namespace std;

vector<string> map;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, X;

    cin >> N >> M >> X;

    map = vector<string>(N, string(M, EMPTY));

    int mHeight;
    for (int j = 0; j < M; j++)
    {
        cin >> mHeight;

        for (int i = 0; i < N; i++)
        {
            int h = N - i;
            if (h <= mHeight)
            {
                if (h == X)
                    map[i][j] = TUNNEL;
                else
                    map[i][j] = MOUNTAIN;
            }
            else if (h == X)
                map[i][j] = BRIDGE;
            else if (h < X && j % 3 == 2)
                map[i][j] = SUPPORT;
        }
    }

    for (int i = 0; i < N; i++)
        cout << map[i] << '\n';

    return 0;
}