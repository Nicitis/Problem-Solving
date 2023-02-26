// 2023.02.25., 택배상자, https://school.programmers.co.kr/learn/courses/30/lessons/131704
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    int conv_index = 1;
    stack<int> stk;
    
    for (int i = 0; i < order.size(); i++)
    {
        while (order[i] > conv_index)
        {
            stk.push(conv_index++);
        }
        
        if (order[i] == conv_index)
        {
            answer++;
            conv_index++;
        }
        else // 컨베이어 벨트에 원하는 상자가 없을 경우
        {
            if (!stk.empty() && order[i] == stk.top())
            {
                answer++;
                stk.pop();
            }
            else
            {
                break;
            }
        }
    }
    
    return answer;
}