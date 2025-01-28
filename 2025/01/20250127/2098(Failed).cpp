#include <cstdio>
#include <climits>
#include <vector>
#include <algorithm>

bool visit[16];
int w[16][16];
int N;
int minCost = INT_MAX, minEdge = INT_MAX;
const int START_CITY = 0;

void tsp(int v, int remained, int accCost)
{
    // printf("tsp(%d, %d, %d)\n", v, remained, accCost);

    if (remained == 0) // last
    {
        if (w[v][START_CITY] != 0)
        {
            if (accCost + w[v][START_CITY] < minCost)
            {
                minCost = accCost + w[v][START_CITY];
                // printf("Find min result = %d\n", minCost);
            }
        }
        return;
    }

    visit[v] = true;
    for (int i = 1; i < N; i++)
    {
        if (!visit[i] && w[v][i] != 0 && 
            accCost + w[v][i] + minEdge * remained < minCost)
        {
            tsp(i, remained - 1, accCost + w[v][i]);
        }
    }
    visit[v] = false;
}

int main()
{
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &w[i][j]);
            if (w[i][j] < minEdge)
                minEdge = w[i][j];
        }
    }

    tsp(START_CITY, N-1, 0);

    printf("%d", minCost);

    return 0;
}