// 백준 2186: 문자판
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> map;

// 현재 위치에서 d 거리 이내에 이전 문자 prevC가 몇 개만큼 존재하는지 찾는다.
int CorrectCharInRange(int x, int y, int n, int m, int k, int prevC, vector<vector<int>>& pathMap)
{
    int numberOfPath = 0;
    for (int d = 1; d <= k; d++)
    {
        if (x - d >= 0 && prevC == map[y][x - d])
            numberOfPath += pathMap[y][x - d];
        if (x + d < m && prevC == map[y][x + d])
            numberOfPath += pathMap[y][x + d];
        if (y - d >= 0 && prevC == map[y - d][x])
            numberOfPath += pathMap[y - d][x];
        if (y + d < n && prevC == map[y + d][x])
            numberOfPath += pathMap[y + d][x];
    }
    return numberOfPath;
}

// 문자 수를 한 글자씩 늘려가며 단어 경로의 수를 찾는다.
int NumberOfWordPath(int n, int m, int k, string word)
{
    int paths = 0;
    int len = word.length();
    vector<vector<int>> pathMap(n, vector<int>(m, 0));
    vector<vector<int>> tempMap(n, vector<int>(m, 0));

    // 한 글자씩 늘려가며 메모이제이션한다
    for (int i = 0; i < len; i++)
    {
        char c = word[i];
        char prevC = i > 0 ? word[i - 1] : 0;

        for (int y = 0; y < n; y++)
        {
            for (int x = 0; x < m; x++)
            {
                if (map[y][x] != c)
                {
                    tempMap[y][x] = 0;
                    continue;
                }
                
                if (i == 0)
                    tempMap[y][x] = 1;
                else
                    tempMap[y][x] = CorrectCharInRange(x, y, n, m, k, prevC, pathMap);
            }
        }

        // 복제한다
        pathMap = vector<vector<int>>(tempMap);
    }

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            paths += pathMap[y][x];
        }
    }

    return paths;
}

int main()
{
    int n, m, k;
    string word;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;

    map = vector<string>(n);

    for (int i = 0; i < n; i++)
        cin >> map[i];
    
    cin >> word;
    
    int paths = NumberOfWordPath(n, m, k, word);

    cout << paths;

    return 0;
}