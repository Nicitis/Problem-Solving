// 프로그래머스 레벨 1: 숫자 문자열과 영단어
// 일부 영단어가 섞인 숫자들을 숫자로 바꾸기
#include <iostream>

#include <string>
#include <vector>

using namespace std;

string number[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

// 문자열을 숫자로 바꾸어준다. -1일 경우 실패
int StringToNumber(string s)
{
    // 숫자일 때
    if (s[0] >= '0' && s[0] <= '9')
    {
        return s[0] - '0';
    }
    // 영단어일 때
    int n;
    for (n = 0; n <= 9; n++)
    {
        if (s == number[n])
            return n;
    }
    return -1; // 실패
}

int solution(string s) 
{
    int answer = 0, i, num;
    string temp = "";

    for (i = 0; i < s.length(); i++)
    {
        temp.push_back(s[i]);
        num = StringToNumber(temp);
        if (num != -1)
        {
            // 새로운 자리를 추가한다.
            answer = answer * 10 + num;
            temp.clear();
        }
    }
    
    return answer;
}

// 이와 같이 바꿀 수도 있다.
// #include <regex>
// int solution(string s)
// {
//     int answer = 0, i;

//     for (i = 0; i <= 9; i++)
//     {
//         s = regex_replace(s, regex(number[i]), to_string(i));
//     }
//     answer = stoi(s);
//     return answer;
// }

int main()
{
    string s;

    cin >> s;
    cout << solution(s);

    return 0;
}