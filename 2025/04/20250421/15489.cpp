#include <iostream>
#include <cstring>

using namespace std;

/*
현재 라인이 CR, 현재 열이 CC일 때
열 번호가 C <= CC <= C + (CR-R) 범위에 있다면
그 수의 합을 더한다.
*/

int main()
{
    int r, c, w;
    int pascal[31][31];
    int sum = 0;

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(pascal[0], 0, sizeof(pascal[0]));
    pascal[0][1] = 1;

    cin >> r >> c >> w;

    for (int i = 1; i < r + w; i++)
    {
        memset(pascal[i], 0, sizeof(pascal[i]));
        for (int j = 1; j <= i; j++)
        {
            if (j == 1)
                pascal[i][j] = 1;
            else
                pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
            
            if (c <= j && j <= c + (i-r))
                sum += pascal[i][j];
        }
    }

    cout << sum;

    return 0;
}