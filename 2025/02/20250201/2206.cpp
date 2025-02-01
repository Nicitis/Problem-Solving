#include <iostream>
#include <vector>
#include <string>
#include <queue>

#define INF 987654321

#define DIST_POS pair<int, pair<int, int>> 

using namespace std;

int dx[4] = { 0, -1, 1, 0 };
int dy[4] = { -1, 0, 0, 1 };

void printMap(vector<vector<int>> distMap, int N, int M)
{
    cout << "===== Print Map Distance =====\n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << distMap[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<string> map;
    vector<vector<int>> distMap(N, vector<int>(M, INF));

    for (int i = 0; i < N; i++)
    {
        string line;
        cin >> line;
        map.push_back(line);
    }
    
    // <dist, <row, col>>
    queue<DIST_POS> q;
    priority_queue<DIST_POS, vector<DIST_POS>, greater<DIST_POS>> wall_pq;

    q.push(make_pair(1, make_pair(0, 0)));
    distMap[0][0] = 1;

    // 시작점에서 BFS(벽은 거리만 조사)
    while (!q.empty())
    {
        int dist = q.front().first;
        int row = q.front().second.first;
        int col = q.front().second.second;
        q.pop();

        // cout << "dist, row, col(qsize) : " << dist << ", (" << row << ", " << col << "), qsize = " << q.size() << "\n";

        for (int i = 0; i < 4; i++)
        {
            int nextRow = row + dy[i];
            int nextCol = col + dx[i];

            if (nextRow < 0 || nextRow >= N ||
                nextCol < 0 || nextCol >= M)
                continue;
            if (distMap[nextRow][nextCol] != INF)
                continue;

            distMap[nextRow][nextCol] = dist + 1;
            DIST_POS next = make_pair(dist + 1, make_pair(nextRow, nextCol));

            if (map[nextRow][nextCol] == '0') // empty
            {
                q.push(next);
            }
            else // wall
            {
                wall_pq.push(next);
            }
        }
    }

    // printMap(distMap, N, M);

    // 벽을 뚫는 경우 조사
    while (!wall_pq.empty())
    {
        // 최단 경로만 조사하기
        int dist = wall_pq.top().first;
        int row = wall_pq.top().second.first;
        int col = wall_pq.top().second.second;
        wall_pq.pop();

        if (distMap[row][col] < dist)
            continue;

        for (int i = 0; i < 4; i++)
        {
            int nextRow = row + dy[i];
            int nextCol = col + dx[i];

            if (nextRow < 0 || nextRow >= N ||
                nextCol < 0 || nextCol >= M)
                continue;
            if (distMap[nextRow][nextCol] <= dist + 1)
                continue;
            if (map[nextRow][nextCol] == '1')
                continue;
            
            distMap[nextRow][nextCol] = dist + 1;
            DIST_POS next = make_pair(dist + 1, make_pair(nextRow, nextCol));

            wall_pq.push(next);
        }
    }

    // cout << "After searching walls \n";
    // printMap(distMap, N, M);

    int answer = -1;
    if (distMap[N-1][M-1] != INF)
        answer = distMap[N-1][M-1];

    cout << answer <<'\n';

    return 0;
}