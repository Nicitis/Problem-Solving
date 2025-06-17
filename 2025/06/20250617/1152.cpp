#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    string line, word;

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    getline(cin, line);
    istringstream ss(line);

    int count = 0;
    while (getline(ss, word, ' '))
    {
        if (word != "")
            count++;
    }
    cout << count;

    return 0;
}