#include <iostream>
#include <string>
#include <map>

using namespace std;

// 장비의 수가 A, B, C일 때
// (A+1)(B+1)(C+1) - 1

int main()
{
    int t, n;
    string clothes, type;

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;

    map<string, int> clothesPerType;

    while (t--)
    {
        cin >> n;
        
        clothesPerType.clear();
        for (int i = 0; i < n; i++)
        {
            cin >> clothes >> type;
            clothesPerType[type]++;
        }

        int cases = 1;
        for (auto p : clothesPerType)
        {
            cases *= p.second + 1;
        }
        cout << cases - 1 << '\n';
    }

    return 0;
}