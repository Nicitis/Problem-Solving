// 백준 11047: 동전 0
#include <iostream>

using namespace std;

int coinValues[10];

// 탐욕법으로 total 원을 만드는 데 필요한 동전 개수의 최소값를 센다.
int MinimumAmountOfCoins(int n, int total)
{
    int coin = 0;
    int index = n - 1; // 마지막 인덱스부터 시작
    
    while (total > 0)
    {
        coin += total / coinValues[index];
        total = total % coinValues[index];
        index--;
    }

    return coin;
}

int main()
{
    int n, k;

    cin >> n >> k;

    for (int i = 0; i < n; i++)
        cin >> coinValues[i];
    
    cout << MinimumAmountOfCoins(n, k);

    return 0;
}