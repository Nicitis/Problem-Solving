#include <iostream>

using namespace std;

int main()
{
    int n, a, b, c;
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    
    bool existSide[1000001] = { false, };

    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> c;

        if (existSide[a] || existSide[b] || existSide[c])
        {
            cout << "1";
            return 0;
        }

        existSide[a] = true;
        existSide[b] = true;
        existSide[c] = true;
    }

    cout << "0";

    return 0;
}