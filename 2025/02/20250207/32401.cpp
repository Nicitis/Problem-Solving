#include <iostream>
#include <string>

using namespace std;

int main()
{
    int N;
    string str;
    cin >> N;
    cin >> str;

    int startPos = -1;
    bool existN = false;
    bool existMultipleN = false;
    int answer = 0;

    for (int i = 0; i < N; i++)
    {
        if (str[i] == 'A')
        {
            if (startPos != -1)
                answer += existN && !existMultipleN;
            startPos = i;
            existN = false;
            existMultipleN = false;
        }
        else if (str[i] == 'N')
        {
            if (existN)
                existMultipleN = true;
            existN = true;
        }
    }

    cout << answer << '\n';

    return 0;
}