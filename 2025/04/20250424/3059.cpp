#include <iostream>
#include <string>
#include <cstring>
#define START 65

using namespace std;

int main()
{
    int t, total;
    string s;
    bool exist[26];
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--)
    {
        cin >> s;
        memset(exist, 0, sizeof(exist));

        for (char c : s)
        {
            exist[c - START] = true;
        }
        total = 0;
        for (int i = 0; i < 26; i++)
        {
            if (!exist[i])
                total += i + START;
        }

        cout << total << "\n";
    }

    return 0;
}