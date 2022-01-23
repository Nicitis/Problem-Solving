// 백준 3108: 로고(C++)
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

typedef struct
{
    int x1;
    int y1;
    int x2;
    int y2;
} Rect;

vector<Rect> rects;
vector<int> parents;

// 두 직사각형이 연결되어 있는지 확인한다.
bool IsConnected(Rect a, Rect b)
{
    // a에 b가 소속
    if (a.x1 < b.x1 && b.x2 < a.x2 && a.y1 < b.y1 && b.y2 < a.y2)
        return false;
    
    // b에 a가 소속
    if (b.x1 < a.x1 && a.x2 < b.x2 && b.y1 < a.y1 && a.y2 < b.y2)
        return false;
    
    // x가 밖임
    if (a.x2 < b.x1 || b.x2 < a.x1)
        return false;

    // y가 밖임
    if (a.y2 < b.y1 || b.y2 < a.y1)
        return false;

    return true;
}

// 집합의 부모를 찾는다.
int Find(int x)
{
    if (parents[x] != x)
        parents[x] = Find(parents[x]);
    return parents[x];
}

// 집합을 합친다.
void Union(int x, int y)
{
    int xRoot = Find(x);
    int yRoot = Find(y);

    parents[xRoot] = yRoot;
}

int NumberOfRectSet()
{
    int count = rects.size();
    int n = rects.size();

    Rect zeroPoint = {0, 0, 0, 0};

    // (0, 0)과 만나는 직사각형이 있을 경우 set 하나 감소
    for (int i = 0; i < n; i++)
    {
        if (IsConnected(rects[i], zeroPoint))
        {
            count--;
            break;
        }
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            // 같은 집합에 있지 않고 connected되어 있다면 합친다.
            if (Find(i) != Find(j) && IsConnected(rects[i], rects[j]))
            {
                Union(i, j);
                count--;
            }
        }
    }

    return count;
}

int main()
{
    int n;

    cin >> n;

    rects = vector<Rect>(n, {0, 0, 0, 0});
    parents = vector<int>(n);

    for (int i = 0; i < n; i++)
    {
        cin >> rects[i].x1 >> rects[i].y1 >> rects[i].x2 >> rects[i].y2;
        parents[i] = i;
    }


    cout << NumberOfRectSet() << '\n';

    return 0;
}