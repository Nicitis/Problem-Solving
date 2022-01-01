// 프로그래머스 레벨 1: 신규 아이디 추천
#include <iostream>

#include <string>
#include <vector>

using namespace std;

string solution(string new_id) 
{
    string answer = "";
    int i;

    // 1~3단계
    string temp = "";
    bool doubleFullStop = false;
    for (auto iter = new_id.begin(); iter != new_id.end(); iter++)
    {
        if (*iter >= 'A' && *iter <= 'Z')
            *iter -= 'A' - 'a';
        
        if ((*iter >= 'a' && *iter <= 'z') ||
            (*iter >= '0' && *iter <= '9') ||
            *iter == '-' ||
            *iter == '_' || 
            *iter == '.')
        {

            if (*iter == '.')
            {
                if (!doubleFullStop)
                {
                    doubleFullStop = true;
                    temp.push_back(*iter);
                }
            }
            else
            {
                temp.push_back(*iter);
                doubleFullStop = false;
            }
        }
    }

    // 4단계
    if (*temp.begin() == '.')
        temp.erase(temp.begin());
    if (*(temp.end() - 1) == '.')
        temp.erase(temp.end() - 1);
    
    // 5단계
    if (temp.empty())
    {
        temp = "aaa";
    }
    // 6단계
    else if (temp.length() >= 16)
    {
        temp.erase(15, temp.length()-15);
        // . 지우기
        if (*temp.begin() == '.')
            temp.erase(temp.begin());
        if (*(temp.end() - 1) == '.')
            temp.erase(temp.end() - 1);
    }
    else if (temp.length() <= 2)
    {
        while (temp.length() != 3)
            temp.push_back(temp.back());
    }

    answer = temp;

    return answer;
}

int main()
{
    string new_id;
    cin >> new_id;
    cout << solution(new_id);
    return 0;
}