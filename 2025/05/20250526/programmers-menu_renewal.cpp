/*
A, C, E
A, C, D
이렇게 주문이 들어왔다 치면...
다른 주문과 공통점을 찾아서 기록해야 한다.
주문의 종류는 총 26개이므로, BOOL 배열 같은 것으로도 충분히 구별이 가능할 듯싶다.
그보다는 INT 비트 필드를 사용하는 게 베스트다.

예시
ABCFG
AC -> AC 중복 발견(기록)
[AC(2)]
CDE -> ABCFG에서 C 중복 -> 무시, AC에서 중복 C -> 무시
ACDE -> ABCFG에서 AC 중복 발견(기록), AC에서 AC 중복 발견(기록), CDE에서 CDE 중복 발견(기록)
[AC(3), CDE(2)]
BCFG -> ABCFG에서 BCFG 중복 발견(기록), AC 무시, CDE 무시, 
[AC(3), CDE(2), BCFG(2)]
ACDEH -> ABCFG에서 AC 중복 발견(기록), AC에서 AC 중복(기록), ACDE에서 ACDE 중복(기록), **CDE 중복 발견(기록)
[AC(4), CDE(3), ACDE(2), BCFG(2)]
이때, 2개에서는 AC, 3개에서는 CDE, 4개에서는 ACDE, BCFG가 공동으로 가장 길었으므로 이를 리스트에 추가한다.
-> 정렬 시 [AC, ACDE, BCFG, CDE]
- 주의점: 앞의 리스트를 검사하는 과정에서, 발견한 세트는 단 한번만 기록해야 한다. AC를 한번에 여러 번 발견해도 한 번만 기록해야 함.
- 세트의 길이가 2인데 course 개수가 2개인 게 없을 경우 이는 무시한다.
- 그런데 만약, 세트의 길이가 5인데 받을 수 있는 세트가 4라면?
    - 예를 들어, 결과에 딱 cde (3) 하나만 있는데, course에 2가 있다면, cd도 되고 ce도 되고 de도 되는 거 아닌가?
- 앞의 리스트뿐만 아니라, 

예시 2
abcde
ab -> ab 발견(abcde) [ab(2)]
cd -> cd 발견(abcde) [ab(2), cd(2)]
ade -> ade 발견(abcde) [ab(2), cd(2), ade(2)]
xyz
xyz -> xyz 발견(xyz) [ab(2), cd(2), ade(2), xyz(2)]
acd -> ad 발견(abcde), cd 발견 [ab(2), ad(2), cd(3), ade(2), xyz(2)]
이때 결과에서, 글자수가 많은 쪽에서 글자수 낮은 쪽을 추려낼 수가 있다. ade에서 ad를 증가시킬 수 있다.
그런데 빈도 수는 그렇지 않다. ad가 나타난 횟수는 3번이다.
그런데, 생각해보면 매번 추가할 때마다 course의 수에 해당하는 원소를 추가하면 되는 거 아닌가?
이게 되는 이유는, 각 원소가 길이가 최대 10이므로,
추가 원소의 최대 개수
= 10 C 2 * 20 + 10 C 3 * 20 + ... + 10 C 9 * 20 + 10 C 10 * 20
<= 10 C 5 * 20 * 20 = 10 9 8 7 6 / 5 4 3 2 1 * 400 = 3 * 2 * 7 * 6 * 400 정도밖에 안된다.
이런 거 10번 해도 충분히 계산 가능하다.
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

string currentMenu = "";

void AddAllSets(const string& str, int start, int length, map<string, int>& m)
{
    if (currentMenu.size() == length)
    {
        m[currentMenu]++;
        // cout << "m[" << currentMenu << "] = " << m[currentMenu] << "\n";
        return;
    }

    for (int i = start; i < str.size(); i++)
    {
        currentMenu += str[i];
        AddAllSets(str, i + 1, length, m);
        currentMenu.erase(currentMenu.end() - 1, currentMenu.end());
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    // sort order's string
    for (string& order : orders)
    {
        std::sort(order.begin(), order.end());
    }
    
    for (int length: course)
    {
        map<string, int> frequency;
        for (const string& str : orders)
        {
            AddAllSets(str, 0, length, frequency);
        }
        
        int maximumFreq = 2;
        vector<string> subresult;
        for (const auto& p : frequency)
        {
            if (p.second >= maximumFreq)
            {
                if (p.second > maximumFreq)
                {
                    subresult.clear();
                    maximumFreq = p.second;
                }
                subresult.push_back(p.first);
                // cout << "push : " << p.first << "(" << p.second << ")\n";
            }
        }
        
        for (string& str : subresult)
        {
            answer.push_back(str);
        }
        frequency.clear();
    }
    std::sort(answer.begin(), answer.end());
    
    return answer;
}