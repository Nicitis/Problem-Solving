#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int accHighScore = 0, highScoreDelta = 100, accScore = 0, delta;
    int score = 0;

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < 10; i++)
    {
        cin >> score;
        accScore += score;

        delta = abs(100 - accScore);

        if (delta <= highScoreDelta)
        {
            accHighScore = accScore;
            highScoreDelta = delta;
        }
    }

    cout << accHighScore;

    return 0;
}