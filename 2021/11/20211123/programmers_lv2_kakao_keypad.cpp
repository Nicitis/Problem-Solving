// 프로그래머스 레벨 1: [카카오 인턴] 키패드 누르기
#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

#define STAR    -1 // *
#define POUND   -2 // #

using namespace std;

// 키패드의 row를 구함
int GetRow(int key)
{
    if (key == 0 || key == STAR || key == POUND)
        return 4;
    else
        return (key - 1) / 3 + 1; // 3 단위로 row를 다르게 계산
}

// 키패드의 col을 구함
int GetCol(int key)
{
    if (key == STAR)
        return 1;
    else if (key == 0)
        return 2;
    else if (key == POUND)
        return 3;
    else
        return (key-1) % 3 + 1;
}

string solution(vector<int> numbers, string hand)
{
    string answer = "";
    int l = STAR, r = POUND, leftDist, rightDist, num;

    for (int i = 0; i < numbers.size(); i++)
    {
        // 왼손일 경우
        num = numbers[i];
        if (num == 1 || num == 4 || num == 7)
        {
            l = num;
            answer.push_back('L');
        }
        // 오른손일 경우
        else if (num == 3 || num == 6 || num == 9)
        {
            r = num;
            answer.push_back('R');
        }
        else
        {
            // 거리 = col 차이 + row 차이
            leftDist = abs(GetCol(num) - GetCol(l)) 
                + abs(GetRow(num) - GetRow(l));
            rightDist = abs(GetCol(num) - GetCol(r)) 
                + abs(GetRow(num) - GetRow(r));

            // 거리가 짧은 쪽을 누르도록 한다.
            if (leftDist < rightDist || 
                leftDist == rightDist && hand == "left")
            {
                l = num;
                answer.push_back('L'); // 왼손
            }
            else
            {
                r = num;
                answer.push_back('R'); // 오른손
            }
        }
    }

    return answer;
}

int main()
{
    vector<int> numbers;
    int n, i;
    string hand;
    cin >> n;
    while (n--)
    {
        cin >> i;
        numbers.push_back(i);
    }
    cin >> hand;

    cout << "===\n";

    for (i = 0; i < numbers.size(); i++)
    {
        cout << numbers[i] << " : " << GetCol(numbers[i]) << ", " << GetRow(numbers[i]) << '\n';
    }
    cout << "===\n";

    cout << solution(numbers, hand);
}