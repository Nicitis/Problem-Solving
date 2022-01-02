// 백준 10610: 30
#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    string strNumber;
    int total = 0;
    int numbers[10] = { 0 };

    cin >> strNumber;

    for (int i = 0; i < strNumber.length(); i++)
    {
        numbers[strNumber[i] - '0']++;
        total += strNumber[i] - '0';
    }

    // 0이 없거나 3의 배수가 아닐 때 30의 배수가 아님
    if (numbers[0] == 0 || total % 3 != 0)
    {
        cout << "-1";
        return 0;
    }
    
    for (int i = 9; i >= 0; i--)
    {
        while (numbers[i]-- > 0)
            cout << i;
    }
    
    return 0;
}