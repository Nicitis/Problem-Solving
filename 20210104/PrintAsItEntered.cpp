#include <iostream>

using namespace std;

// Backjoon 11718 �״�� ����ϱ�(https://www.acmicpc.net/problem/11718)
int main()
{
    const int LINE_SIZE = 101;
    char line[LINE_SIZE];

    for (int i = 0; i < 100; i++)
    {
        cin.getline(line, LINE_SIZE);
        
        if (cin.eof()) // cin.clear() ���ִ� ����
            break;

        cout << line << endl;
    }

    return 0;
}