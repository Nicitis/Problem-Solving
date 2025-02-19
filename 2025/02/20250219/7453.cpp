#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

vector<int> pair1, pair2;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int numarr[4000][4];
    long long answer = 0LL;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> numarr[i][0] >> numarr[i][1] >> numarr[i][2] >> numarr[i][3];
    }
    // 1. a+b 쌍과 c+d의 쌍을 구한다(중복 허용)
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            pair1.push_back(numarr[i][0] + numarr[j][1]);
            pair2.push_back(numarr[i][2] + numarr[j][3]);
        }
    }
    // 2. c+d 쌍을 정렬한다.
    sort(pair1.begin(), pair1.end());
    sort(pair2.begin(), pair2.end());

    // 3. a+b 쌍에 대해 대응되는 c+d 쌍을 찾아본다.
    auto next_end = pair2.end();
    for (int p : pair1)
    {
        auto it_lower = lower_bound(pair2.begin(), next_end, -p);
        auto it_upper = upper_bound(it_lower, next_end, -p);
        next_end = it_upper;

        long long count = (it_upper - it_lower);
        answer += count;
    }

    cout << answer << '\n';

    return 0;
}