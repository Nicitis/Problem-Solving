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

    // int lcs[1001][1001];
    vector<vector<int>> lcs(len2, vector<int>(len1, 0));

    for (int idx2 = 0; idx2 < len2; idx2++)
    {
        for (int idx1 = 0; idx1 < len1; idx1++)
        {
            // 같을 때
            if (str1[idx1] == str2[idx2])
            {
                if (idx1 > 0 && idx2 > 0)
                    lcs[idx2][idx1] = lcs[idx2-1][idx1-1] + 1;
                else
                    lcs[idx2][idx1] = 1;
            }
            // 다를 때: 위, 혹은 왼쪽 참조
            else
            {
                int upper = idx2 > 0 ? lcs[idx2-1][idx1] : 0;
                int left = idx1 > 0 ? lcs[idx2][idx1-1] : 0;
                lcs[idx2][idx1] = max(upper, left);
            }
        }
    }

    // 문자 찾기
    int idx2 = len2 - 1;
    int idx1 = len1 - 1;

    int lcs_cnt = idx1 >= 0 && idx2 >= 0 ? lcs[idx2][idx1] : 0;
    cout << lcs_cnt << '\n';
    if (lcs_cnt == 0)
    {
        cout << '\n';
        return 0;
    }
        
    vector<char> reversed;
    int upper, left;
    while (idx2 >= 0 && idx1 >= 0)
    {
        upper = idx2 > 0 ? lcs[idx2-1][idx1] : 0;
        left = idx1 > 0 ? lcs[idx2][idx1-1] : 0;

        if (str1[idx1] == str2[idx2])
        {
            reversed.push_back(str1[idx1]);
            idx1--;
            idx2--;
        }
        else if (upper > left)
            idx2--;
        else
            idx1--;
    }
    reverse(reversed.begin(), reversed.end());
    reversed.push_back('\0');

    cout << reversed.data() << "\n";

    return 0;
}