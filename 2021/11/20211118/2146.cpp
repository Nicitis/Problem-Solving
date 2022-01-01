// 백준 2146: 다리 만들기(C++)
#include <iostream>
#include <queue>
#include <utility>
#define MAXSIZE 100
#define MIN(X, Y) ((X)<(Y)?(X):(Y))

using namespace std;

int _map[MAXSIZE + 1][MAXSIZE + 1]; // 지도
int distanceMap[MAXSIZE + 1][MAXSIZE + 1]; // 거리 정보
int continentMap[MAXSIZE + 1][MAXSIZE + 1]; // 대륙 번호

int xMove[] = { 0, -1, 1, 0 };
int yMove[] = { -1, 0, 0, 1 };

// dfs 방식으로 대륙 번호를 정한다.
void SetContinent(int x, int y, int n, int num)
{
    int i, nextX, nextY;
    continentMap[y][x] = num;

    for (i = 0; i < 4; i++)
    {
        nextX = x + xMove[i];
        nextY = y + yMove[i];

        // 맵 밖일 경우 스킵
        if (nextX < 1 || nextX > n ||
            nextY < 1 || nextY > n)
            continue;

        if (_map[nextY][nextX] == 1 &&
            continentMap[nextY][nextX] == 0)
            SetContinent(nextX, nextY, n, num);
    }
}

void SetAllContinent(int n)
{
    int x, y, k = 1;
    for (y = 1; y <= n; y++)
    {
        for (x = 1; x <= n; x++)
        {
            if (_map[y][x] == 1 &&
                continentMap[y][x] == 0)
                SetContinent(x, y, n, k++);
        }
    }
}

int bfs(int n)
{
    int x, y, i, nextX, nextY, continentNum, minDist = 987654321;
    queue<pair<int, int>> q;
    bool isFound = false;


    // 거리 정보 초기화
    for (y = 1; y <= n; y++)
    {
        for (x = 1; x <= n; x++)
        {
            if (_map[y][x] == 1)
            {
                // 바다를 이웃한 해안가일 경우 방문 후보로 지정
                if (_map[y-1][x] == 0 ||
                    _map[y][x-1] == 0 ||
                    _map[y][x+1] == 0 ||
                    _map[y+1][x] == 0)
                    q.push(make_pair(x, y));
            }
        }
    }

    // bfs 방문
    // 다른 대륙으로부터 계산된 위치를 발견될 때까지 거리를 기록한다.
    while (!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        int dist = distanceMap[y][x];
        int cont = continentMap[y][x];

        for (i = 0; i < 4; i++)
        {
            nextX = x + xMove[i];
            nextY = y + yMove[i];
            
            if (nextX < 1 || nextX > n ||
                nextY < 1 || nextY > n)
                continue;

            // 바다이고 거리가 0이며 아직 탐색하지 않았을 경우(대륙 번호 = 0) 방문
            if (_map[nextY][nextX] == 0 &&
                distanceMap[nextY][nextX] == 0 &&
                continentMap[nextY][nextX] == 0)
            {
                continentMap[nextY][nextX] = cont;
                distanceMap[nextY][nextX] = dist + 1;
                if (!isFound)
                    q.push(make_pair(nextX, nextY));
            }
            else if (continentMap[nextY][nextX] != 0 &&
                cont != continentMap[nextY][nextX])
            {
                // 다른 대륙으로부터 계산된 위치를 발견하면 현재 큐 내에 있는 노드까지만 확인
                isFound = true; // 더이상 노드를 추가하지 않음
                minDist = MIN(distanceMap[y][x] + distanceMap[nextY][nextX],
                    minDist);
            }
        }
    }

    return minDist; // 오류
}

int main()
{
    int n, x, y;
    ios_base::sync_with_stdio(false);

    // 그래프 생성
    cin >> n;

    for (y = 1; y <= n; y++)
    {
        for (x = 1; x <= n; x++)
        {
            cin >> _map[y][x];
        }
    }

    // 대륙 번호 생성(K번으로 설정)
    SetAllContinent(n);

    // 최단 경로의 다리를 계산함
    cout << bfs(n) << '\n';
}