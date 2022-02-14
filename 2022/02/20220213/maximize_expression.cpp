// 프로그래머스: 수식최대화(https://programmers.co.kr/learn/courses/30/lessons/67257)
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <cctype>
#include <cstdlib>

using namespace std;

int curIndex = 0; // 문자열 내 읽고 있는 인덱스

enum ExpType
{
    NUMBER, PLUS, MINUS, MULT, NONE
};

struct ExpNode
{
    long long number;
    ExpType type;
};

long long GetNextNumber(string expression)
{
    long long number = 0;
    do
    {
        number = number * 10 + (expression[curIndex] - '0');
        curIndex++;
    } while (curIndex < expression.length() && isdigit(expression[curIndex]));
    cout << "number " << number << '\n';
    return number;
}

ExpType GetNextOperator(string expression)
{
    ExpType type;
    if (curIndex >= expression.length())
        return NONE;
    else if (expression[curIndex] == '+')
        type = PLUS;
    else if (expression[curIndex] == '-')
        type = MINUS;
    else
        type = MULT;
    cout << "Operator " << type << '\n';
    curIndex++;
    return type;
}

long long CalcExp(long long left, long long right, ExpType op)
{
    switch(op)
    {
        case PLUS:
            left += right;
            break;
        case MINUS:
            left -= right;
            break;
        case MULT:
            left *= right;
            break;
    }
    return left;
}

long long solution(string expression) {
    long long answer = 0;
    ExpType lastOperator = NONE;
    ExpType nextOperator = NONE;
    int priority[5] = { 0, 1, 2, 3, 10 };

    // 모든 연산자 케이스별로 반복한다.
    do
    {
        curIndex = 0;
        stack<ExpNode> expStack;
        
        // 숫자 노드 하나 받는다.
        long long number = GetNextNumber(expression);
        // 연산자가 있으면 받는다.
        nextOperator = GetNextOperator(expression);
        
        expStack.push({number, NUMBER});
        if (nextOperator != NONE)
            expStack.push({0, nextOperator});

        while (nextOperator != NONE && curIndex < expression.length()) // 다음 연산자가 없을 때까지 반복
        {
            // 숫자 노드 하나 받는다.
            number = GetNextNumber(expression);
            // 연산자가 있으면 받는다.
            lastOperator = nextOperator;
            nextOperator = GetNextOperator(expression);
            
            expStack.push({number, NUMBER});
            
            while (priority[lastOperator] <= priority[nextOperator] &&
                expStack.size() >= 3) // 다음 연산자의 우선순위가 높거나 stack이 1개 남을 때까지 연산
            {
                long long left, right;
                right = expStack.top().number;
                expStack.pop(); expStack.pop();
                left = expStack.top().number;
                expStack.pop();
                
                long long result = CalcExp(left, right, lastOperator);
                
                lastOperator = expStack.empty() ? NONE : expStack.top().type;
                
                expStack.push({result, NUMBER});
            }
            
            if (nextOperator != NONE)
                expStack.push({0, nextOperator});
        }
        
        answer = max(answer, abs(expStack.top().number));
    } 
    while (std::next_permutation(priority + PLUS, priority + MULT + 1));
    
    return answer;
}

int main()
{
    std::string s;
    std::cin >> s;
    std::cout << solution(s) <<'\n';

    return 0;
}