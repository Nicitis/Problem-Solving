#include <iostream>
#include <string>

using namespace std;

int main()
{
    int height = 0, prev = -1;

    string line;

    cin >> line;

    for (char c : line)
    {
        height += c == prev ? 5 : 10;
        prev = c;
    }
    cout << height;

    return 0;
}