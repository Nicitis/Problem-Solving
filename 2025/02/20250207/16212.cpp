#include <iostream>
#include <algorithm>

using namespace std;

int arr[500000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) cin >> arr[i];
    
    sort(arr, arr + N);
    
    for (int i = 0; i < N; i++)
    {
        if (i != 0) cout << ' ';
        cout << arr[i];
    }
    cout << '\n';

    return 0;
}