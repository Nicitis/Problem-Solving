#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string name, oldStr, weightStr;

    cin >> name >> oldStr >> weightStr;

    while (name[0] != '#')
    {
        int old = stoi(oldStr);
        int weight = stoi(weightStr);

        if (old > 17 || weight >= 80)
            cout << name << " Senior\n";
        else
            cout << name << " Junior\n";

        cin >> name >> oldStr >> weightStr;
    }

    return 0;
}