// 백준 1013번 Contact: DFA(결정적 유한 오토마타) 방법
#include <iostream>
#include <string>

using namespace std;

bool PatternAutomata(string& s)
{
    int state = 0;
    int index = 0;

    while (true)
    {
        // 종료시
        if (index >= s.length())
            return (state == 0 || state == 5 || state == 6);
            
        switch(state)
        {
            case 0:
                state = s[index] == '0' ? 1 : 2;
                break;
            case 1:
                if (s[index] == '0') return false;
                state = 0;
                break;
            case 2:
                if (s[index] == '1') return false;
                state = 3;
                break;
            case 3:
                if (s[index] == '1') return false;
                state = 4;
                break;
            case 4:
                state = s[index] == '0' ? 4 : 5;
                break;
            case 5:
                state = s[index] == '0' ? 1 : 6;
                break;
            case 6:
                state = s[index] == '0' ? 7 : 6;
                break;
            case 7:
                state = s[index] == '0' ? 4 : 0;
                break;
        }
        index++;
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
        if (PatternAutomata(s))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}