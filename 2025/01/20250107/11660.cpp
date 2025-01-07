#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    cin >> n >> m;

    // 적분 영상 방법 처리
    vector<vector<int>> integralImage(n + 1, vector<int>(n + 1, 0));

    int in, acc;
    for (int i = 1; i <= n; i++)
    {
        acc = 0;
        for (int j = 1; j <= n; j++)
        {
            cin >> in;
            acc += in;
            integralImage[i][j] = integralImage[i - 1][j] + acc;
        }
    }

    // A - B
    // |   |
    // C - D
    // 합 = A - B - C + D
    for (int i = 0; i < m; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int area = integralImage[x1 - 1][y1 - 1]
                - integralImage[x1 - 1][y2]
                - integralImage[x2][y1 - 1]
                + integralImage[x2][y2];
        cout << area << '\n';
    }

    return 0;
}