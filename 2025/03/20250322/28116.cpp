#include <iostream>
#include <cstring>

using namespace std;

void swap(int* pa, int* pb)
{
    int temp = *pa;
    *pa = *pb;
    *pb = temp;
}

int main()
{
    int n;
    int arr[500001];
    int posArr[500001];
    int movementsArr[500001];
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    memset(movementsArr, 0, sizeof(int) * (n+1));

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        posArr[arr[i]] = i;
    }

    for (int i = 1; i < n; i++)
    {
        int move = posArr[i] - i;
        int temp = arr[i];
        swap(&arr[i], &arr[posArr[i]]);
        swap(&posArr[temp], &posArr[i]);

        movementsArr[i] += move;
        movementsArr[temp] += move;
    }

    for (int i = 1; i <= n; i++)
        cout << movementsArr[i] << " ";

    return 0;
}