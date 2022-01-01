// 백준 2447: 별 찍기 - 10
#include <iostream>
#include <vector>

using namespace std;

vector<vector<bool>> map;

// 패턴 계산
void CalculatePattern(int x, int y, int size)
{
    if (size == 3)
    {
        map[y][x] = true;
        map[y][x+1] = true;
        map[y][x+2] = true;
        map[y+1][x] = true;
        map[y+1][x+2] = true;
        map[y+2][x] = true;
        map[y+2][x+1] = true;
        map[y+2][x+2] = true;
    }
    else
    {
        int nextSize = size/3;
        CalculatePattern(x, y, nextSize);
        CalculatePattern(x+nextSize, y, nextSize);
        CalculatePattern(x+2*nextSize, y, nextSize);
        CalculatePattern(x, y+nextSize, nextSize);
        CalculatePattern(x+2*nextSize, y+nextSize, nextSize);
        CalculatePattern(x, y+2*nextSize, nextSize);
        CalculatePattern(x+nextSize, y+2*nextSize, nextSize);
        CalculatePattern(x+2*nextSize, y+2*nextSize, nextSize);
    }
}

// 패턴 출력
void PrintPattern(int n)
{
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            if (map[y][x])
                cout << "*";
            else
                cout << " ";
        }
        cout << "\n";
    }
}

int main()
{
    int n;
    ios::sync_with_stdio(false);

    cin >> n;
    map = vector<vector<bool>>(n, vector<bool>(n));

    CalculatePattern(0, 0, n);
    PrintPattern(n);
}