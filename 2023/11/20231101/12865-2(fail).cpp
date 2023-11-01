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
 * 현재 물건의 무게가 i, 가치가 v인데 k만큼의 무게를 채울 수 있다면, * 
 * 다음과 같이 구할 수 있다.
 * 1부터 K-1까지의 무게 i에 대해
 * 모든 아이템에 대해서, 아이템의 무게가 w, 가치가 v일 때
 * dp[i + w] = max(dp[i] + v, dp[i+w]) if i + w <= k로 최선의 값을 확장할 수 있다.
 */
int maximum_value(item_vector& items, int k)
{
    vector<int> dp(k + 1, 0);
    int max_val = 0;

    // 0부터 모든 K에 대해 (W, V)의 값을 갖는 물건에 대해 dp[x + w] = max(dp[x] + v, dp[x + w])
    for (int x = 0; x < k; x++)
    {
        for (int i = 0; i < items.size(); i++)
        {
            int w = items[i].first;
            int v = items[i].second; 

            if (x + w > k)
                break;

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

    // 무게 순으로 오름차순 정렬한다.
    sort(items.begin(), items.end(), 
        [](int_pair a, int_pair b)
        {
            return a.first < b.first;
        });

    cout << maximum_value(items, k);

    return 0;
}