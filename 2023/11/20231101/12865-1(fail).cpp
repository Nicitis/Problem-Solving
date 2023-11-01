// 백준-12865 평범한 배낭
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int,int> int_pair;
typedef vector<int_pair> item_vector; // (W, V) 쌍

int backtracking(item_vector& v, int cur_idx, int remain_w)
{
    int max_val = 0;
    for (int i = cur_idx + 1; i < v.size(); i++)
    {
        int weight = v[i].first;
        if (weight > remain_w) // 선택시 무게를 넘으면 종료
            break;
        
        int value = v[i].second + backtracking(v, i, remain_w - weight);
        max_val = value > max_val ? value : max_val;
    }

    return max_val;
}

int main()
{
    int n, k;
    cin >> n >> k;

    item_vector items;
    int max_val = 0;

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

    for (int i = 0; i < n; i++)
    {
        // 모든 물건을 하나씩 선택해본다.
        int weight = items[i].first;
        if (weight > k) // 선택시 무게를 넘으면 종료
            break;
        
        int value = items[i].second + backtracking(items, i, k - weight);
        max_val = value > max_val ? value : max_val;
    }

    cout << max_val << '\n';

    return 0;
}