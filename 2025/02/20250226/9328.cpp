#include <iostream>
#include <string>
#include <queue>
#include <cstring>

#define DOOR_KEY(X) (((X) - 'A'))
#define KEYIDX(X) (((X) - 'a'))

using namespace std;

int h, w;
char map[100][101];
bool visit[100][100];
bool hasKey[26];

queue<pair<int, int>> doorQ;

int dir_x[4] = { 0, -1, 1, 0 };
int dir_y[4] = { -1, 0, 0, 1 };

int dfs(int row, int col)
{
    // 벽이면 무시
    int docs = 0;
    if (map[row][col] == '*')
        return 0;
    visit[row][col] = true;
    // 문인데 잠겨 있을 경우 킵
    if (map[row][col] >= 'A' && map[row][col] <= 'Z' &&
        hasKey[DOOR_KEY(map[row][col])] == false)
    {
        doorQ.push(make_pair(row, col));
        return 0;
    }
    // 문이 아닐 경우 진행
    if (map[row][col] >= 'a' && map[row][col] <= 'z')
    {
        hasKey[KEYIDX(map[row][col])] = true;
    }
    else if (map[row][col] == '$')
        docs++;

    for (int dir = 0; dir < 4; dir++)
    {
        int nextRow = row + dir_y[dir];
        int nextCol = col + dir_x[dir];

        if (nextRow < 0 || nextRow >= h ||
            nextCol < 0 || nextCol >= w)
            continue;
        if (visit[nextRow][nextCol])
            continue;
        docs += dfs(nextRow, nextCol);
    }

    return docs;
}

int SolveMaximumDocs(string keys)
{
    int docs = 0;
    
    memset(hasKey, 0, sizeof(hasKey));
    memset(visit, 0, sizeof(visit));

    if (keys[0] != '0')
    {
        for (char c : keys)
        {
            hasKey[KEYIDX(c)] = true;
        }
    }

    // 입구 조사
    doorQ = queue<pair<int, int>>();
    
    for (int j = 0; j < w; j++)
    {
        if (!visit[0][j])
            docs += dfs(0, j);
        if (!visit[h-1][j])
            docs += dfs(h-1, j);
    }
    for (int i = 1; i < h - 1; i++)
    {
        if (!visit[i][0])
            docs += dfs(i, 0);
        if (!visit[i][w - 1])
            docs += dfs(i, w - 1);
    }

    // 문 조사하기
    bool foundWays;
    do
    {
        foundWays = false;
        // 문에 해당하는 키가 있으면 들어갈 수 있다(visit이어도 통과)
        int qsize = doorQ.size();
        for (int i = 0; i < qsize; i++)
        {
            int row = doorQ.front().first;
            int col = doorQ.front().second;
            doorQ.pop();

            if (hasKey[DOOR_KEY(map[row][col])])
            {
                foundWays = true;
            }
            docs += dfs(row, col);
        }
    } while (foundWays);

    return docs;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    string keys;

    cin >> t;

    for (int test = 0; test < t; test++)
    {
        cin >> h >> w;

        for (int i = 0; i < h; i++)
        {
            cin >> map[i];
        }

        cin >> keys;

        cout << SolveMaximumDocs(keys) << '\n';
    }

    return 0;
}