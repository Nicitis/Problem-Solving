#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int dir[][2] = { { -1, 0 }, { 0, -1 }, { 0, 1 }, { 1, 0 } }; // {행, 열}로의 이동방향

int getDistanceToTarget(vector<int> startPos, vector<string> maps, const char target, vector<int>& outPos)
{
    int result = -1;
    queue<vector<int>> q; // 큐에는 {row, col, dist}의 데이터가 저장된다.
    vector<vector<bool>> visit(maps.size(), vector<bool>(maps[0].size(), false));
    
    q.push({startPos[0], startPos[1], 0});
    visit[startPos[0]][startPos[1]] = true;
    
    while (!q.empty())
    {
        int row = q.front()[0];
        int col = q.front()[1];
        int dist = q.front()[2];
        q.pop();
        
        if (maps[row][col]==target)
        {
            result = dist;
            outPos = { row, col };
            break;
        }
        
        for (int i = 0; i < 4; i++)
        {
            int nextRow = row + dir[i][0];
            int nextCol = col + dir[i][1];
            if (nextRow < 0 || nextRow >= maps.size() ||
                nextCol < 0 || nextCol >= maps[0].size())
                continue;

            if (!visit[nextRow][nextCol] && maps[nextRow][nextCol] != 'X')
            {
                q.push({nextRow, nextCol, dist+1});
                visit[nextRow][nextCol] = true;
            }
        }
    }
    
    return result;
}

int solution(vector<string> maps) {
    int answer = 0;
    int dist;
    // 미로 탐색을 위해 bfs를 사용한다.
    // 시작 위치 탐색
    vector<int> startPos;
    for (int i = 0; i < maps.size(); i++)
    {
        if (startPos.size() != 0)
            break;
        for (int j = 0; j < maps[0].size(); j++)
        {
            if (maps[i][j] == 'S') // 시작지점 설정
            {
                startPos.push_back(i);
                startPos.push_back(j);
                break;
            }
        }
    }
    cout << startPos[0] << ", " << startPos[1] << endl;

    dist = getDistanceToTarget(startPos, maps, 'L', startPos); // 레버를 찾아 이동한다.
    if (dist == -1) return -1;
    answer += dist;
    dist = getDistanceToTarget(startPos, maps, 'E', startPos); // 문을 찾아 이동한다.
    if (dist == -1) return -1;
    answer += dist;
    
    return answer;
}

int main()
{
    vector<string> maps = {"SOOOL","XXXXO","OOOOO","OXXXX","OOOOE"};
    // vector<string> maps = {"LOOXS","OOOOX","OOOOO","OOOOO","EOOOO"};

    cout << solution(maps);

    return 0;
}