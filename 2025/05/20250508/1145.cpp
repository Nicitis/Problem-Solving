#include <iostream>
#include <algorithm>

using namespace std;

int choose[3];
int inputs[5];

int gcd(int a, int b)
{
    int temp;

    if (a < b)
    {
        temp = a;
        a = b;
        b = temp;
    }

    while (b > 0)
    {
        temp = a % b;
        a = b;
        b = temp;
    }

    return a;
}

int lcd(int a, int b)
{
    return a * b / gcd(a, b);
}


int FindMinimumLcdOfThree(int startIdx, int idx)
{
    if (idx >= 3)
    {
        return lcd(lcd(choose[0], choose[1]), choose[2]);
    }

    int minLcd = 123456789;
    
    for (int i = startIdx; i < 5; i++)
    {
        choose[idx] = inputs[i];
        minLcd = min(minLcd, FindMinimumLcdOfThree(i + 1, idx + 1));
    }
    return minLcd;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < 5; i++)
        cin >> inputs[i];

    cout << FindMinimumLcdOfThree(0, 0);

    return 0;
}