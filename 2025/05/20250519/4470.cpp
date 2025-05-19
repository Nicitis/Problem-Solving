#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;
    string str;
    getline(cin, str);

    for (int i = 0; i < n; i++)
    {
        getline(cin, str);
        cout << (i + 1) << ". " << str << "\n";
    }

    return 0;
}