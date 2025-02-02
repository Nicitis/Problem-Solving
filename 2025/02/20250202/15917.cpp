#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int Q, a;

    cin >> Q;

    for (int i = 0; i < Q; i++)
    {
        cin >> a;
        cout << ((a&(-a)) == a) << '\n';
    }

    return 0;
}