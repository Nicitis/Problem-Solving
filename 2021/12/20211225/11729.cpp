// 백준 11729: 하노이 탑 이동 순서
#include <iostream>
#define MAX_MOVEMENT 1048575

using namespace std;

int startTowers[MAX_MOVEMENT];
int destTowers[MAX_MOVEMENT];

int count = 0;

// 하노이 탑의 이동 순서를 출력한다. n이 N일 때, 1부터 N번 원반까지를 destination으로 옮긴다.
void PrintHanoiTower(int n, int start, int mediation, int destination)
{
    if (n == 1)
    {
        startTowers[count] = start;
        destTowers[count++] = destination;
        return;
    }
    PrintHanoiTower(n - 1, start, destination, mediation);

    startTowers[count] = start;
    destTowers[count++] = destination;

    PrintHanoiTower(n - 1, mediation, start, destination);
}

int main()
{
    int n;

    ios_base::sync_with_stdio(false);

    cin >> n;

    PrintHanoiTower(n, 1, 2, 3);

    cout << count << '\n';
    for (int i = 0; i < count; i++)
        cout << startTowers[i] << ' ' << destTowers[i] << '\n';

    return 0;
}