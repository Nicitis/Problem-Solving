#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char str1[1001], str2[1001];

    cin >> str1;
    cin >> str2;

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    vector<vector<int>> lcs(len2 + 1, vector<int>(len1 + 1, 0));

    for (int idx2 = 1; idx2 <= len2; idx2++)
    {
        for (int idx1 = 1; idx1 <= len1; idx1++)
        {
            // 같을 때
            if (str1[idx1 - 1] == str2[idx2 - 1])
            {
                lcs[idx2][idx1] = lcs[idx2-1][idx1-1] + 1;
            }
            // 다를 때: 위, 혹은 왼쪽 참조
            else
            {
                lcs[idx2][idx1] = max(lcs[idx2-1][idx1], lcs[idx2][idx1-1]);
            }
        }
    }
    
    // 문자 찾기
    int idx2 = len2;
    int idx1 = len1;

    cout << lcs[idx2][idx1] << '\n';
    if (lcs[idx2][idx1] == 0)
        return 0;
        
    string reversed;
    
    while (idx1 > 0 && idx2 > 0)
    {
        if (str1[idx1 - 1] == str2[idx2 - 1])
        {
            reversed.push_back(str1[idx1-1]);
            idx1--;
            idx2--;
        }
        else if (lcs[idx2-1][idx1] > lcs[idx2][idx1-1])
            idx2--;
        else
            idx1--;
    }

    reverse(reversed.begin(), reversed.end());

    cout << reversed << "\n";

    return 0;
}