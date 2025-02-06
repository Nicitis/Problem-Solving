#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool CompareGemsValueDesc(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second)
        // 가치 같으면 가벼운 것 우선
        return a.first < b.first;
    // 가치순 비교
    return a.second > b.second;
}

bool CompareBagsAsc(int a, int b)
{
    return a < b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;

    cin >> N >> K;

    vector<pair<int, int>> gems;
    vector<int> bags;
    vector<int> nextBagIdx;

    for (int i = 0; i < N; i++)
    {
        int m, v;
        cin >> m >> v;
        gems.push_back(make_pair(m, v));
    }

    for (int i = 0; i < K; i++)
    {
        int c;
        cin >> c;
        bags.push_back(c);
        nextBagIdx.push_back(i+1);
    }
    nextBagIdx[K-1] = -1;

    sort(gems.begin(), gems.end(), CompareGemsValueDesc);
    sort(bags.begin(), bags.end(), CompareBagsAsc);

    // // print gems
    // cout << "gems\n";
    // for (int i = 0; i < gems.size(); i++)
    //     cout << i << ": " << gems[i].first << "," << gems[i].second <<'\n';

    // cout << "bags\n";
    // for (int i = 0; i < bags.size(); i++)
    //     cout << i << ": " << bags[i] <<'\n';
    
    int startBagIdx = 0, endBagIdx = K-1;
    long long maxPrice = 0LL;

    for (int i = 0; i < N; i++)
    {
        if (startBagIdx > endBagIdx)
            break;
        if (bags[endBagIdx] < gems[i].first) // 가장 큰 가방에도 안 들어가면 무시
            continue;
        // 가벼운 가방부터 시도
        int prevBagIdx = -1;
        int bagIdx = startBagIdx;
        // cout << "Target Gem[" << i << "]=(" << gems[i].first << "," << gems[i].second << ") (bag idx=" << bagIdx << ")\n";
        while (bagIdx <= endBagIdx && bagIdx != -1)
        {
            if (gems[i].first <= bags[bagIdx])
            {
                // cout << "gems["<<i<<"].first <= bags["
                    // <<bagIdx<<"]" <<'\n';
                maxPrice += gems[i].second;
                if (prevBagIdx != -1)
                {
                    nextBagIdx[prevBagIdx] = nextBagIdx[bagIdx];
                    if (bagIdx == endBagIdx)
                        endBagIdx = prevBagIdx;
                }
                else // first element
                    startBagIdx = nextBagIdx[bagIdx];
                // nextBagIdx[bagIdx] = -1;
                // cout << "get (m,v)=(" << gems[i].first <<","<<gems[i].second
                    // <<")(startBagIdx, bagIdx, endBagIdx)=(" << startBagIdx << "," << bagIdx <<"," << endBagIdx << ")\n";
                break;
            }
            prevBagIdx = bagIdx;
            bagIdx = nextBagIdx[bagIdx];
        }
    }

    cout << maxPrice << '\n';

    return 0;
}