#include <iostream>

using namespace std;

#define MOD 10

int ModMult(int a, int b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return (a - 1) % MOD + 1;
    if (b % 2 == 0)
    {
        int mod = ModMult(a, b / 2);
        return (mod * mod - 1) % MOD + 1;
    }
    else
    {
        int mod = ModMult(a, b - 1);
        return (mod * a - 1) % MOD + 1;
    }
}

int main()
{
    int t, a, b;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> a >> b;
        int mod = ModMult(a, b);
        // a = (a - 1) % MOD + 1;
        // int mod = 1;
        // for (int j = 1; j <= b; j++)
        //     mod = (mod * a - 1) % MOD + 1;
        cout << mod << "\n";
    }

    return 0;
}