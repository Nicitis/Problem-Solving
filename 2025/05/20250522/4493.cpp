#include <iostream>

using namespace std;

inline int GetId(char c)
{
    switch (c)
    {
        case 'R':
            return 0;
        case 'P':
            return 1;
        case 'S':
            return 2;
    }
    return -1;
}

int main()
{
    int t, n, w1, w2;
    char a, b;

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;

    for (; t > 0; --t)
    {
        cin >> n;
        w1 = 0;
        w2 = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> a >> b;

            int a_id = GetId(a);
            int b_id = GetId(b);

            if ((a_id + 1) % 3 == b_id)
                w2++;
            else if ((b_id + 1) % 3 == a_id)
                w1++;
        }
        if (w1 > w2)
            cout << "Player 1\n";
        else if (w1 < w2)
            cout << "Player 2\n";
        else
            cout << "TIE\n";
    }

    return 0;
}