#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t, n;
    cin >> t;

    map<string, int> wordPosMap;
    int originalWordIndices[1000];
    string message[1000];
    
    while (t--)
    {
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            string word;
            cin >> word;
            wordPosMap[word] = i;
        }
        for (int i = 0; i < n; i++)
        {
            string word;
            cin >> word;
            originalWordIndices[i] = wordPosMap[word];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> message[originalWordIndices[i]];
        }
        for (int i = 0; i < n; i++)
        {
            if (i != 0)
                cout << ' ';
            cout << message[i];
        }
        cout << '\n';
    }

    return 0;
}