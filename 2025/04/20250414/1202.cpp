#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> parents;

int find(int elem)
{
    int parent = elem, temp;
    while (parent != parents[parent])
        parent = parents[parent];

    // 붕괴
    while (elem != parent)
    {
        temp = elem;
        elem = parents[elem];
        parents[temp] = parent;
    }
    return parent;
}

void union_set(int a, int b)
{
    int parentA = find(a);
    int parentB = find(b);
    parents[parentA] = parentB;
}

int main()
{
    int n, k, m, v, c;
    long long maximumValues = 0;

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    vector<pair<int, int>> gems(n); // <가치, 무게>
    vector<int> bags(k);

    // initialize disjoint set
    parents = vector<int>(k + 1); // k개 가방 + 빈 요소 1개

    for (int i = 0; i < n; i++)
    {
        cin >> gems[i].second >> gems[i].first;
    }
    for (int i = 0; i < k; i++)
    {
        cin >> bags[i];
        parents[i] = i;
    }
    parents[k] = k;

    sort(gems.begin(), gems.end(), std::greater<pair<int, int>>()); // 가치 내림차순 정렬
    sort(bags.begin(), bags.end()); // 무게 오름차순

    for (pair<int, int> p : gems)
    {
        m = p.second;
        v = p.first;

        auto it = lower_bound(bags.begin(), bags.end(), m);
        int idx = it - bags.begin();
        idx = find(idx);

        if (idx < k) // 담을 수 있는 가방이라면 담기
        {
            maximumValues += v;
            union_set(idx, idx + 1);
        }
    }

    cout << maximumValues;

    return 0;
}