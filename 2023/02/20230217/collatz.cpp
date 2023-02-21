// 2022.02.17., 우박수열 정적분, https://school.programmers.co.kr/learn/courses/30/lessons/134239
#include <string>
#include <vector>

using namespace std;

vector<int> collatz(int number)
{
    vector<int> result;
    do
    {
        result.push_back(number);
        if (number % 2 == 0)
            number = number / 2;
        else
            number = number * 3 + 1;
    } while (number > 1);
    result.push_back(1);
    
    return result;
}

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    vector<int> heights = collatz(k);
    
    // x의 최댓값이 M일 때 구간 [a, b]에 대한 꺾은선 그래프의 정적분의 결과는 a <= x <= M + b에서의 정적분의 결과로,
    // (h(a) + 2sum_(x가 a + 1에서 M + b - 1까지일 때 h(x)) + h(b))/2이다.
    
    for (int i = 0; i < ranges.size(); i++)
    {
        int a = ranges[i][0];
        int b = ranges[i][1];
        int M = heights.size() - 1;
        
        int minX = a <= M + b ? a : M + b;
        int maxX = a <= M + b ? M + b : a;
        
        double sum = 0.0;
        
        if (minX < maxX)
        {
            sum = heights[minX] + heights[maxX];
        
            for (int x = minX + 1; x <= maxX - 1; x++)
                sum += 2 * heights[x];
            sum /= 2.0;
        }
        
        if (a > M + b)
            sum = -1.0;
        
        answer.push_back(sum);
    }
    
    return answer;
}