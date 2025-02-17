#include <iostream>

using namespace std;

int cardPositions[100001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, claps = 0, input;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> input;
        cardPositions[input] = i;
    }

    int prev = cardPositions[1];
    for (int i = 2; i <= n; i++)
    {
        if (cardPositions[i] < prev)
            claps++;
        prev = cardPositions[i];
    }
    cout << claps;

    return 0;
}