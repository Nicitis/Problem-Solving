// 2023.02.08., 이모티콘 할인 행사, https://school.programmers.co.kr/learn/courses/30/lessons/150368
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int promotionRates[] = { 10, 20, 30, 40 };

// (플러스 이용자 수, 이모티콘 구매 비용)으로 구성된 벡터 중 목표를 더 성공적으로 달성하는 결과를 반환한다.
vector<int> maxResult(vector<int> result1, vector<int> result2)
{
    if (result1[0] > result2[0])
        return result1;
    else if (result1[0] < result2[0])
        return result2;
    else
    {
        if (result1[1] > result2[1])
            return result1;
        else
            return result2;
    }
}

vector<int> calculateResult(vector<vector<int>> users, vector<int> emoticons, vector<int> promotion)
{
    vector<int> prices(users.size(), 0);
    int subscribers = 0;
    int total = 0;
    
    for (int e = 0; e < emoticons.size(); e++)
    {
        for (int id = 0; id < users.size(); id++)
        {
            if (users[id][0] < promotion[e])
                prices[id] += emoticons[e] / 100 * (100 - promotion[e]);
        }
    }
    
    for (int id = 0; id < users.size(); id++)
    {
        // 일정 금액을 넘어가면 구독한다.
        if (prices[id] >= users[id][1])
            subscribers++;
        else
            total += prices[id];
    }
    
    vector<int> result(2, 0);
    result[0] = subscribers;
    result[1] = total;
    return result;
}

vector<int> bruteForce(vector<vector<int>> users, vector<int> emoticons, vector<int> promotion)
{
    vector<int> result(2, 0);
    if (emoticons.size() == promotion.size())
    {
        return calculateResult(users, emoticons, promotion); // 할인율을 모두 할당하고 나면 값을 계산
    }
    
    for (int i = 0; i < 4; i++)
    {
        promotion.push_back(promotionRates[i]);
        result = maxResult(result,
                    bruteForce(users, emoticons, promotion));
        promotion.pop_back();
    }
    return result;
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    return answer;
}

int main()
{
    vector

    return 0;

}