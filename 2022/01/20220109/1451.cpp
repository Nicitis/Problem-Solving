// 백준 1451: 직사각형으로 나누기 (오답노트)
// 완전 탐색 문제는 "모든 범위를 탐색하는 것"이 목적임을 생각하자.
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

vector<string> rect;

long long SumOfRect(int sx, int sy, int ex, int ey)
{
    int area = 0;
    for (int y = sy; y < ey; y++)
    {
        for (int x = sx; x < ex; x++)
        {
            area += rect[y][x] - '0';
        }
    }
    return area;
}

long long MaxRectMul(int n, int m)
{
    long long maxMul = 0;

    // 가로 분할(||)
    for (int i = 1; i < m - 1; i++)
    {
        for (int j = i + 1; j < m; j++)
        {
            // x의 범위: [0, i), [i, j), [j, m)
            maxMul = max(maxMul, SumOfRect(0, 0, i, n) * SumOfRect(i, 0, j, n) * SumOfRect(j, 0, m, n));
        }
    }

    // 혼합 분할(ㅏ, ㅓ, ㅜ, ㅗ)
    for (int midY = 1; midY < n; midY++)
    {
        for (int midX = 1; midX < m; midX++)
        {
            long long r1, r2, r3, r4;
            r1 = SumOfRect(0, 0, midX, midY);// 좌상
            r2 = SumOfRect(midX, 0, m, midY);// 우상
            r3 = SumOfRect(0, midY, midX, n);// 좌하
            r4 = SumOfRect(midX, midY, m, n);// 우하
            maxMul = max({maxMul,
                (r1 + r3) * r2 * r4, // ㅏ
                r1 * r3 * (r2 + r4), // ㅓ
                r1 * r2 * (r3 + r4), // ㅗ
                (r1 + r2) * r3 * r4} // ㅜ
                );
        }
    }

    // 세로 분할(==)
    for (int i = 1; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            // y의 범위: [0, i), [i, j), [j, n)
            maxMul = max(maxMul, SumOfRect(0, 0, m, i) * SumOfRect(0, i, m, j) * SumOfRect(0, j, m, n));
        }
    }

    return maxMul;
}

int main()
{
    int n, m;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    rect = vector<string>(n);

    for (int y = 0; y < n; y++)
    {
        cin >> rect[y];
    }

    cout << MaxRectMul(n, m);

    return 0;
}