#include <iostream>

using namespace std;

// Backjoon 11718 그대로 출력하기(https://www.acmicpc.net/problem/11718)
int main()
{
    const int LINE_SIZE = 101;
    char line[LINE_SIZE];

    for (int i = 0; i < 100; i++)
    {
        cin.getline(line, LINE_SIZE);
        
        if (cin.eof()) // cin.clear() 없애니 성공
            break;

        cout << line << endl;
    }

    return 0;
}