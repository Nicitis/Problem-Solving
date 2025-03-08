#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int frequency[26];

    string input;

    getline(cin, input);

    while (input.compare("*") != 0)
    {
        memset(frequency, 0, sizeof(frequency));

        for (char c : input)
        {
            if (c == ' ')
                continue;
            frequency[c - 'a']++;
        }

        // check
        bool isPangram = true;
        for (int i = 0; i < 26; i++)
        {
            if (frequency[i] <= 0)
            {
                isPangram = false;
                break;
            }
        }

        cout << (isPangram ? "Y\n" : "N\n");

        getline(cin, input);
    }

    return 0;
}