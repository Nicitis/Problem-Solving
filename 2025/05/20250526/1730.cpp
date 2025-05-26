// 5.26 21:50~22:05(15분)
#include <iostream>
#include <string>
#include <vector>

#define EMPTY 46
#define VERT 124
#define HORIZ 45
#define ALL 43

using namespace std;

inline void Draw(vector<string>& map, bool isVertical, int x, int y)
{
    if (isVertical)
    {
        if (map[y][x] == EMPTY)
            map[y][x] = VERT;
        else if (map[y][x] == HORIZ)
            map[y][x] = ALL;
    }
    else
    {
        if (map[y][x] == EMPTY)
            map[y][x] = HORIZ;
        else if (map[y][x] == VERT)
            map[y][x] = ALL;
    }
}

int main()
{
    int n;
    string input;
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    cin >> input;
    
    vector<string> map(n, string(n, EMPTY));
    int x = 0, y = 0;
    
    for (char c : input)
    {
        if (c == 'U')
        {
            if (y == 0) continue;
            Draw(map, true, x, y);
            y--;
            Draw(map, true, x, y);
        }
        else if (c == 'D')
        {
            if (y == n - 1) continue;
            Draw(map, true, x, y);
            y++;
            Draw(map, true, x, y);
        }
        else if (c == 'L')
        {
            if (x == 0) continue;
            Draw(map, false, x, y);
            x--;
            Draw(map, false, x, y);
        }
        else if (c == 'R')
        {
            if (x == n - 1) continue;
            Draw(map, false, x, y);
            x++;
            Draw(map, false, x, y);
        }
    }
    
    for (string line : map)
        cout << line << "\n";
    
    return 0;
}