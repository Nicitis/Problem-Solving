#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<pair<int, int>> dirs = {{ -1, -1 }, { 0, -1 }, { 1, -1 }, { -1, 1 }, { 0, 1 }, { 1, 1 }};
int aMatch[50], bMatch[50];
bool visit[50];

bool findMatch(int id, vector<int> adj[50])
{
    visit[id] = true;
    for (int b : adj[id])
    {
        if (bMatch[b] == -1 || 
            (!visit[bMatch[b]] && findMatch(bMatch[b], adj)))
        {
            aMatch[id] = b;
            bMatch[b] = id;
            return true;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int c;
    
    cin >> c;

    while (c--)
    {
        int n, m;
        cin >> n >> m;    

        string map[10];
        for (int i = 0; i < n; i++)
            cin >> map[i];

        vector<int> adj[50];
        int id[10][10];

        // 정점별로 번호를 매긴다.
        int a, b;
        a = b = 0;
        int broken = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (map[i][j] == 'x')
                {
                    id[i][j] = -1;
                    broken++;
                }
                else
                    id[i][j] = j % 2 == 0 ? a++ : b++;
            }
        }

        for (int i = 0; i < n; i++)
        {
            // 홀수열에 대해 A 집합으로 묶는다.
            for (int j = 0; j < m; j += 2)
            {
                if (map[i][j] == 'x')
                    continue;
                
                for (pair<int, int> dir : dirs)
                {
                    int ny = i+dir.first, nx = j+dir.second;
                    if (ny < 0 || ny >= n || nx < 0 || nx >= m || 
                        id[ny][nx] == -1)
                        continue;
                    adj[id[i][j]].push_back(id[ny][nx]);
                }
            }
        }
        
        int match = 0;
        memset(aMatch, -1, sizeof(aMatch));
        memset(bMatch, -1, sizeof(bMatch));
        for (int i = 0; i < a; i++)
        {
            memset(visit, 0, sizeof(visit));
            if (findMatch(i, adj))
            {
                match++;
            }
        }
        cout << n * m - broken - match << "\n";
    }

    return 0;
}