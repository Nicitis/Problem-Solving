// 2023.02.14., 뒤에 있는 큰 수 찾기, https://school.programmers.co.kr/learn/courses/30/lessons/154539
// 두 번째 시도: 우선순위 큐를 이용하여 최소 숫자하고만 비교할 수 있게 한다.
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Number
{
    int mIndex;
    int mNumber;

    Number(int index, int number)
        : mIndex(index)
        , mNumber(number)
    {
    }

    bool operator<(const Number other) const
    {
        return this->mNumber > other.mNumber;
    }
};

vector<int> solution(vector<int> numbers) 
{
    vector<int> answer(numbers.size(), -1);
    priority_queue<Number> pq;

    // 힙: 뒤큰수를 구하지 못한 수를 priority queue에 넣는다.
    // numbers의 원소 하나마다 리스트를 한 번 순회하며 뒤큰수를 갱신한다.
    // 큐의 최소 원소가 현재 원소보다 크기가 크거나 같으면 이후 수를 갱신하지 않는다.

    for (int i = 0; i < numbers.size(); i++)
    {
        Number num(i, numbers[i]);

        while (!pq.empty())
        {
            Number top = pq.top();
            if (top.mNumber >= numbers[i])
                break;
            answer[top.mIndex] = numbers[i];
            pq.pop();
        } 
        pq.push(num);
    }


    return answer;
}

int main()
{
    vector<int> numbers = { 2, 3, 3, 5 };

    vector<int> result = solution(numbers);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
}

/* 최적의 코드: 굳이 우선순위 큐로 정렬할 필요없이 스택을 사용한다.
뒤큰수가 발견되지 않은 수들은 반드시 비감소 순서대로 수가 나타날 수밖에 없다는 점을 이용하면 굳이 정렬할 필요가 없기 때문!!!
#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1);
    stack<int> stk;

    for(int i=0; i<numbers.size(); i++) {
        while(!stk.empty() && numbers[stk.top()] < numbers[i]) {
            answer[stk.top()] = numbers[i];
            stk.pop();
        }
        stk.push(i);
    }

    return answer;
}

*/