#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    string str;

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    cin >> str;

    for (int i = 0; i < str.size() - 2; i++)
    {
        while (i + 2 < str.size() && (str.compare(i, 3, "PS4") == 0 || str.compare(i, 3, "PS5") == 0))
        {
            if (i + 3 < str.size())
                str = str.substr(0, i + 2) + str.substr(i + 3);
            else
                str = str.substr(0, i + 2);
        }
    }

    cout << str << "\n";

    return 0;
}