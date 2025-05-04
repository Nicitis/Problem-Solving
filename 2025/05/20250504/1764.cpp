#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    set<string> unheardSet;
    string name;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> name;
        unheardSet.insert(name);
    }

    vector<string> unheardAndUnseenList;
    for (int i = 0; i < m; i++)
    {
        cin >> name;
        // 중복 요소 기록
        if (unheardSet.find(name) != unheardSet.end())
            unheardAndUnseenList.push_back(name);
    }

    // 사전순 출력
    cout << unheardAndUnseenList.size() << "\n";

    sort(unheardAndUnseenList.begin(), unheardAndUnseenList.end());

    for (string name : unheardAndUnseenList)
    {
        cout << name << "\n";
    }

    return 0;
}