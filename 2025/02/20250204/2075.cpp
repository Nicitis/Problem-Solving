#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int mat[1500][1500];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> mat[i][j];
        }
    }

    priority_queue<int, vector<int>, greater<int>> minPQ;

    for (int col = 0; col < N; col++)
    {
        minPQ.push(mat[N-1][col]);
    }

    for (int col = 0; col < N; col++)
    {
        int row = N - 2;

        while (row >= 0 && mat[row][col] > minPQ.top())
        {
            minPQ.pop();
            minPQ.push(mat[row][col]);
            row--;
        }
    }
    cout << minPQ.top() << '\n';
    
    return 0;
}