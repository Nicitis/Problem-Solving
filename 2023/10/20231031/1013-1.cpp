// 백준 1013번 Contact: 문자열을 통한 풀이
#include <iostream>
#include <string>

using namespace std;

bool IsValidPattern(string& s)
{
    int index = 0;

    // 패턴을 블럭 단위(하나의 완성된 패턴이 이뤄지는 단위)로 확인한다.
    while (index < s.length())
    {
        if (s[index] == '1')
        {
            // 1번 패턴
            if (index + 2 >= s.length() ||
                s[index + 1] != '0' ||
                s[index + 2] != '0')
                return false;
            
            index += 3;
            
            // 1이 나올 때까지 검사(100+)
            while (index < s.length() && s[index] == '0')
                index++;

            if (index >= s.length())
                return false;

            // 현재 인덱스에 1이 있으므로 0을 찾는다(100+1+)
            while (index < s.length() && s[index] == '1')
                index++;
            
            // 패턴 종료
            if (index >= s.length())
                break;
            
            // 현재 s[index] == '0'
            // 100+1으로 끝났다면 다음 패턴 검사로 넘어간다.
            if (s[index - 2] == '0')
                continue;

            // 100+1+ 뒤에 0이 하나라면 2번 패턴으로, 두 개라면 1번 패턴으로 간다.
            if (index + 1 >= s.length()) // 0으로 끝나면 실패
                return false;
            if (s[index + 1] == '0') // 여기는 0이니 다음도 0이면 1번 패턴으로
                index--;
        }
        else
        {
            // 2번 패턴: 다음이 1이 아니면 실패
            if (index + 1 >= s.length() || s[index + 1] != '1')
                return false;
            index += 2;
        }
    }

    return true;
}

int main()
{
    int T;
    string s;

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> s;
        if (IsValidPattern(s))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}