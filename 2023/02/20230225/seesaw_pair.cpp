// 2023.02.25., 시소 짝꿍, https://school.programmers.co.kr/learn/courses/30/lessons/152996
#include <string>
#include <vector>

using namespace std;

long long solution(vector<int> weights) 
{
    long long answer = 0;
    vector<int> people(1001, 0); // 무게별 해당하는 사람의 수를 저장한다.
    
    // 무게별 인원 수를 기록한다.
    for (int i = 0; i < weights.size(); i++)
    {
        people[weights[i]]++;
    }
    // 비율에 맞는 쌍의 수를 계산한다.
    for (int i = 100; i <= 1000; i++)
    {
        // 1:1, 2:3, 3:4, 2:4에 해당하는 쌍의 수를 계산
        if (people[i] >= 2)
            answer += (long long)people[i] * (people[i] - 1) / 2; // nC2
        if (i % 3 == 0)
            answer += (long long)people[i * 2 / 3] * people[i];
        if (i % 4 == 0)
            answer += (long long)people[i * 3 / 4] * people[i];
        if (i % 2 == 0)
            answer += (long long)people[i / 2] * people[i];
    }
    
    return answer;
}