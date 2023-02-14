// 2023.02.08., 프로그래머스, 124 나라의 숫자(https://school.programmers.co.kr/learn/courses/30/lessons/12899)
#include <string>
#include <vector>
#include <iostream>

using namespace std;

char numberMap[] = { '4', '1', '2' };

string solution(int n)
{
    string answer = "";
    int numIndex;

    do
    {
        numIndex = n % 3;

        answer = numberMap[numIndex] + answer;
        
        if (n == 3) break;
        n = (n-1) / 3;
    } while (n > 0);

    return answer;
}

int main(void)
{
    int n;
    while (true)
    {
        cin >> n;
        cout << "sol: " << solution(n) << endl;
    }

    return 0;
}