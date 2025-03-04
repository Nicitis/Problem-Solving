#include <iostream>
#include <unordered_map>
#include <bitset>
#include <queue>

#define BITSET bitset<500>

using namespace std;

size_t FindNextBit(BITSET& state, size_t start, int n)
{
    for (size_t i = start; i < n; i++)
    {
        if (state.test(i) == true)
        {
            return i;
        }
    }
    return n;
}

int main()
{
    int n, answer = -1;
    unordered_map<BITSET, int> stateMap, nextStateMap;
    // queue<BITSET> q;

    int rows[500];
    int cols[500];

    cin >> n;

    BITSET initialSet;
    for (int i = 0; i < n; i++)
    {
        cin >> rows[i] >> cols[i];
        initialSet.set((size_t)i);
    }

    if (n == 1)
    {
        cout << "0\n";
        return 0;
    }

    // q.push(initialSet);
    nextStateMap[initialSet] = 0;

    while (!nextStateMap.empty())
    {
        if (answer != -1)
            break;
        stateMap = nextStateMap;
        nextStateMap.clear();
        for (auto statePair : stateMap)
        {
            cout << "Check State: " << statePair.first.to_string() << '\n';
            // 상태 방문
            size_t prev = -1, cur, next;
            BITSET state = statePair.first;
            cur = FindNextBit(state, 0, n-1); // 곱할 수 있는 자리는 n-1개 존재
            if (cur >= n-1) // 모두 0일 때
            {
                cout << "End! " << answer << "\n";
                answer = statePair.second;
                break;
            }

            // 모든 다음 상태에 대해 계산
            while (cur < n-1)
            {
                next = FindNextBit(state, cur + 1, n-1); // 곱할 수 있는 자리는 n-1개 존재
                
                cout << "prev, cur, next = " << prev, cur, next << '\n';

                // 다음 상태의 비용을 체크
                int cost = rows[prev + 1] * cols[cur] * cols[next];
                BITSET nextState(state);
                nextState.reset(cur);
                
                // nextStateMap에 삽입 혹은 갱신
                auto nextIt = nextStateMap.find(nextState);
                if (nextIt != nextStateMap.end())
                {
                    if (statePair.second + cost < nextIt->second)
                    {
                        nextIt->second = statePair.second + cost;
                        cout << nextState.to_string() << " cost = " << statePair.second + cost << "\n";
                    }
                }
                else
                {
                    cout << nextState.to_string() << "(New) cost = " << statePair.second + cost << "\n";
                    nextStateMap[nextState] = statePair.second + cost;
                }

                prev = cur;
                cur = next;
            }
            
        }
    }
    

    return 0;
}