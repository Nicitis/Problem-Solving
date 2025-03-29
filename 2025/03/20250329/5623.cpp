#include <iostream>

using namespace std;

int s[2][1000];
int main()
{
    int n, a0;

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < n; j++)
            cin >> s[i][j];

    // n == 2일땐 오직 a1 = a2 = 1밖에 없다.
    if (n == 2)
        cout << "1 1\n";
    else
    {
        a0 = (s[0][1] - s[1][2] + s[0][2]) / 2;
        cout << a0;
        for (int i = 1; i < n; i++)
            cout << " " << s[0][i] - a0;
        cout << "\n";
    }
    

    return 0;
}