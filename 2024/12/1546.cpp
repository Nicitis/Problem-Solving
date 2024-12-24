#include <stdio.h>
#include <vector>

using namespace std;

float RelativeScore(int score, int maxScore)
{
    return score / (float)maxScore * 100.0f;
}

int main()
{
    int N;
    int newScore, maxScore = -1;

    scanf("%d", &N);

    vector<int> scores;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &newScore);
        if (newScore > maxScore)
            maxScore = newScore;
        scores.push_back(newScore);
    }

    float relativeAvg = 0.0f;
    for (int i = 0; i < N; i++)
    {
        relativeAvg += RelativeScore(scores[i], maxScore);
    }
    relativeAvg /= N;

    printf("%f", relativeAvg);

    return 0;
}