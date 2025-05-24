/*
그 행에 배치된 경비병이 0이라는 것은
그 행의 어디든 좋으니 경비병 하나를 배치해야 한다
는 것이다. 그 점을 생각하면,
비어 있는 열이 있다면 그게 어떤 열이든 하나의 열을
채울 수 있다.
즉, 하나의 행을 채우면 비어있는 열 하나를 무조건
채울 수 있고, 반대로 빈 열 하나를 채우면 빈 행
하나를 무조건 채울 수 있다.
따라서, 비어 있는 행의 수와 비어 있는 열의 수 중
더 큰 쪽이 경비원의 최솟값이라고 볼 수 있다.
*/
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n, m;
    string line;

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    int rowCount[50] = { 0 }, colCount[50] = { 0 };

    for (int i = 0; i < n; i++)
    {
        cin >> line;
        for (int j = 0; j < m; j++)
        {
            if (line[j] == 'X')
            {
                rowCount[i]++;
                colCount[j]++;
            }
        }
    }

    int emptyRows = 0, emptyCols = 0;

    for (int i = 0; i < n; i++)
        if (rowCount[i] == 0)
            emptyRows++;
    for (int i = 0; i < m; i++)
        if (colCount[i] == 0)
            emptyCols++;

    cout << max(emptyRows, emptyCols);

    return 0;
}