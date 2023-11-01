// 백준-12865 평범한 배낭
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int,int> int_pair;
typedef vector<int_pair> item_vector; // (W, V) 쌍

/*
 * dp로 문제를 해결한다.
 * 단, 모든 물건은 최대 한 번씩만 담을 수 있으므로 모든 물건마다 다음 작업을 수행한다.
 * 아이템의 무게가 w, 가치가 v일 때
 * 무게 (x + w)일때 최대 가치 dp[x + w] = max(dp[x + w], dp[x] + v) if x = 0, 1, ... , k - w
 */
int maximum_value(item_vector& items, int k)
{
    vector<int> dp(k + 1, 0);
    int max_val = 0;

    // 0부터 모든 K에 대해 (W, V)의 값을 갖는 물건에 대해 dp[x + w] = max(dp[x] + v, dp[x + w])
    for (int i = 0; i < items.size(); i++)
    {
        int w = items[i].first;
        int v = items[i].second;
        for (int x = k - w; x >= 0; x--) // 물건을 단 한 번만 카운팅하도록 역순으로 찾는다
        {
            int new_val = dp[x] + v;
            if (new_val > dp[x + w])
            {
                dp[x + w] = new_val;
                max_val = new_val > max_val ? new_val : max_val;
            }
        }
    }

    return max_val;
}

int main()
{
    int n, k;
    cin >> n >> k;

    item_vector items;

    for (int i = 0; i < n; i++)
    {
        int w, v;
        cin >> w >> v;
        items.push_back(int_pair(w, v));
    }

    cout << maximum_value(items, k) << '\n';

    return 0;
}