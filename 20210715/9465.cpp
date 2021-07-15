#include <cstdio>
#define MAX(X, Y) ((X)>(Y)?(X):(Y))

int main()
{
    int T, N;
    int scores[2][100001];
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        scanf("%d", &N);
        for (int y = 0; y < 2; y++)
            for (int x = 1; x <= N; x++)
                scanf("%d", &scores[y][x]);
        
        // printf("----------N=%d---------\n", N);
        int maxScore = 0;
        int upperMaxScores[2] = {scores[0][1], scores[1][1] + scores[0][2]};
        int lowerMaxScores[2] = {scores[1][1], scores[0][1] + scores[1][2]};
        // printf("x=%d->upper = %d(%d), lower = %d(%d)\n", 1, upperMaxScores[0], upperMaxScores[0], lowerMaxScores[0], lowerMaxScores[0]);
        // printf("x=%d->upper = %d(%d), lower = %d(%d)\n", 2, upperMaxScores[1], upperMaxScores[1], lowerMaxScores[1], lowerMaxScores[1]);
        if (N == 1)
            maxScore = MAX(upperMaxScores[0], lowerMaxScores[0]);
        else if (N == 2)
            maxScore = MAX(upperMaxScores[1], lowerMaxScores[1]);
        else
        {
            for (int x = 3; x <= N; x++)
            {
                int upper = MAX(lowerMaxScores[0], lowerMaxScores[1]) + scores[0][x];
                int lower = MAX(upperMaxScores[0], upperMaxScores[1]) + scores[1][x];
                upperMaxScores[0] = upperMaxScores[1];
                upperMaxScores[1] = upper;
                lowerMaxScores[0] = lowerMaxScores[1];
                lowerMaxScores[1] = lower;
                // printf("x=%d->upper = %d(%d), lower = %d(%d)\n", x, upper, upperMaxScores[1], lower, lowerMaxScores[1]);
            }
            maxScore = MAX(upperMaxScores[1], lowerMaxScores[1]);
        }
        printf("%d\n", maxScore);
        // printf("-----------------------\n");
    }
}