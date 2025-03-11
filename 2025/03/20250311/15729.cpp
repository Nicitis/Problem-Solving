#include <iostream>

using namespace std;

int buttons[1000000];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, answer = 0;

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> buttons[i];

    for (int i = 0; i < n; i++)
    {
        if (buttons[i])
        {
            buttons[i] = !buttons[i];
            if (i + 1 < n)
                buttons[i+1] = !buttons[i+1];
            if (i + 2 < n)
                buttons[i+2] = !buttons[i+2];
            answer++;
        }
    }

    cout << answer << '\n';

    return 0;
}