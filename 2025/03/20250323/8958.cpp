#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t;

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;

    for (; t > 0; --t)
    {
        string s;
        cin >> s;

        int streakScore = 0;
        int score = 0;

        for (char c : s)
        {
            if (c == 'X')
                streakScore = 0;
            else
                score += ++streakScore;
        }
        cout << score << '\n';
    }

    return 0;
}