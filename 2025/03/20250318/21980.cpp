#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <algorithm>

#define ALPHABETS 26

using namespace std;

map<pair<string, int>, int> m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, n, k, answer;

    cin >> T;

    for (int t = 0; t < T; t++)
    {
        cin >> n >> k;

        // get strings
        m.clear();
        for (int i = 0; i < n; i++)
        {
            string str = string();

            cin >> str;

            int uppercases = 0;

            for (int i = 0; i < k; i++)
            {
                if (isupper(str[i]))
                    uppercases++;
                str[i] = std::tolower(str[i]);
            }
            sort(str.begin(), str.end());
            
            pair<string, int> key = make_pair(str, uppercases);
            m[key]++;
        }

        // count similar fairs.
        answer = 0;
        for (auto p : m)
        {
            int n = p.second;
            answer += n * (n - 1) / 2;
        }
        
        cout << answer << '\n';
    }

    return 0;
}