// 백준 1783: 병든 나이트
#include <iostream>
#define MIN(x, y) ((x)<(y)?(x):(y))

using namespace std;

int main()
{
    int n, m, visit;

    cin >> n >> m;

    if (n == 1)
        visit = 1;
    else if (n == 2)
        visit = MIN(1 + (m - 1) / 2, 4);
    else if (m < 7)
        visit = MIN(m, 4);
    else
        visit = m - 2;
    
    cout << visit;

    return 0;
}