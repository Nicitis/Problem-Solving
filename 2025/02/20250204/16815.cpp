#include <iostream>
#include <string>

using namespace std;

int main()
{
    int parentheses = 0;
    string input;

    cin >> input;

    for (char c : input)
    {
        if (c == '(')
            parentheses++;
        else if (c == ')')
            parentheses--;
        else if (c == '*')
        {
            cout << parentheses << '\n';
            break;
        }
    }

    return 0;
}