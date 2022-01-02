// 백준 2873: 롤러코스터
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector<vector<int>> map; // 각 칸의 기쁨도, 0일 경우 이동 불가

typedef struct _pos
{
    int x;
    int y;
} Pos;

void GetMinimalValuePos(int r, int c, Pos& result)
{
    int minValue = 987654321;

    for (int y = 1; y <= r; y++)
    {
        for (int x = 1; x <= c; x++)
        {
            if ((x + y) % 2 == 1 &&
                map[y][x] < minValue)
            {
                result.x = x;
                result.y = y;
                minValue = map[y][x];
            }
        }
    }
}

void PrintMovement(int r, int c)
{
    // 행열 모두 짝수일 때
    if (r % 2 == 0 && c % 2 == 0)
    {
        // 제거해야 할 칸을 먼저 선정
        Pos target = { 1, 1 };
        GetMinimalValuePos(r, c, target);
        map[target.y][target.x] = 0;

        // 가로/세로 우선 모드로 이동한다.
        bool horizontalPriorityMode = r > 2;

        int x = 1, y = 1;
        int thresholdY;
        if (target.y == 1 && target.x == 2)
        {
            thresholdY = r;
            map[y++][x] = 0;
            cout << 'D';
            if (y == thresholdY)
                horizontalPriorityMode = false;
        }
        else
            thresholdY = y + (r - y + 1) / 2;

        while (!(y == r && x == c))
        {
            if (x < 0 || x > c || y < 0 || y > r)
            {
                cout << "OUT OF BOUNDS\n";
                return;
            }
            map[y][x] = 0;
            if (horizontalPriorityMode)
            {
                // 상단, 왼쪽, 오른쪽, 아래 순
                if (map[y - 1][x] > 0)
                {
                    cout << 'U';
                    y--;
                }
                else if (map[y][x - 1] > 0)
                {
                    cout << 'L';
                    x--;
                }
                else if (map[y][x + 1] > 0)
                {
                    cout << 'R';
                    x++;
                }
                else
                {
                    cout << 'D';
                    y++;

                    if (y == thresholdY)
                    {
                        horizontalPriorityMode = false;
                    }
                }
            }
            else
            {
                // 왼쪽, 위, 아래, 오른쪽 순
                if (map[y][x - 1] > 0)
                {
                    cout << 'L';
                    x--;
                }
                else if (map[y - 1][x] > 0)
                {
                    cout << 'U';
                    y--;
                }
                else if (map[y + 1][x] > 0)
                {
                    cout << 'D';
                    y++;
                }
                else
                {
                    cout << 'R';
                    x++;
                }
            }
        }
    }
    // 행과 열 중 하나라도 홀수일 때
    else
    {
        if (r == 2)
        {
            for (int x = 1; x <= c; x++)
            {
                if (x == c)
                    cout << "D";
                else if (x % 2 == 1)
                    cout << "DR";
                else
                    cout << "UR";
            }
        }
        else
        {
            for (int y = 1; y <= r; y++)
            {
                for (int x = 1; x < c; x++)
                {
                    if (y % 2 == 1)
                        cout << 'R';
                    else
                        cout << 'L';
                }
                if (y != r)
                    cout << 'D';
            }
        }
    }
    cout << '\n';
}

int main()
{
    int r, c;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> r >> c;

    map = vector<vector<int>>(r + 2, vector<int>(c + 2, 0));

    for (int currY = 1; currY <= r; currY++)
    {
        for (int currX = 1; currX <= c; currX++)
        {
            cin >> map[currY][currX];
        }
    }

    PrintMovement(r, c);

    return 0;
}