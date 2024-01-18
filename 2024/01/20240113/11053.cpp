#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n, 0);
    vector<int> mem(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        int maxlen = 0;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i] && mem[j] > maxlen)
            {
                maxlen = mem[j];
            }
        }
        mem[i] = maxlen + 1;
    }

    int maximum = 0;
    for (int i = 0; i < n; i++)
        if (maximum < mem[i])
            maximum = mem[i];

    cout << maximum << '\n';

    return 0;
}