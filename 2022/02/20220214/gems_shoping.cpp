#include <string>
#include <vector>
#include <unordered_map>

#include <iostream>

using namespace std;

// 모든 보석이 존재하는지 판별한다.
bool ExistAllGems(unordered_map<string, int>& gemMap)
{
    for (auto elem : gemMap)
    {
        if (elem.second == 0)
            return false;
    }
    return true;
}

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    unordered_map<string, int> gemMap; // 범위 내의 각 보석의 개수
    int left = 0, right = gems.size() - 1;
    int curLeft = 0, curRight = 0;
    
    // 종류를 추가하기
    for (string s : gems)
    {
        if (gemMap.count(s) == 0) // 존재하지 않을 경우 추가
            gemMap.insert({s, 0});
    }

    // 모든 범위가 나타날 때까지 우측 범위를 하나씩 늘린다.
    for (curRight = 0; curRight < gems.size(); curRight++)
    {
        gemMap[gems[curRight]]++;

        if (ExistAllGems(gemMap))
            break;
    }
    
    right = curRight;

    // 오른쪽으로 한 칸씩 증가시키며 최적의 해를 선택한다.
    while (curRight < gems.size())
    {
        while (curLeft < curRight && gemMap[gems[curLeft]] > 1)
        {
            gemMap[gems[curLeft]]--;
            curLeft++;
        }

        cout << "new (left, right) = (" << curLeft << ", " << curRight << ")\n";

        if (curRight - curLeft < right - left)
        {
            left = curLeft;
            right = curRight;
        }

        curRight++;
        if (curRight < gems.size())
        {
            gemMap[gems[curRight]]++;
        }
    }
    answer = { left + 1, right + 1 };
    
    return answer;
}

int main()
{
    vector<string> gems;
    int n;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        gems.push_back(s);
    }
    
    auto pair = solution(gems);

    cout << pair[0] << "~" << pair[1];

    return 0;
}