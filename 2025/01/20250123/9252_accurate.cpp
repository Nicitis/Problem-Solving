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

    for (int row = 1; row <= len2; row++)
    {
        for (int col = 1; col <= len1; col++)
        {
            // 같을 때
            if (str1[col - 1] == str2[row - 1])
            {
                lcs[row][col] = lcs[row-1][col-1] + 1;
            }
            // 다를 때: 위, 혹은 왼쪽 참조
            else
            {
                lcs[row][col] = max(lcs[row-1][col], lcs[row][col-1]);
            }
        }
    }
    
    // 문자 찾기
    int row = len2;
    int col = len1;

    cout << lcs[row][col] << '\n';
    if (lcs[row][col] == 0)
        return 0;
        
    string reversed;
    
    while (lcs[row][col] > 0)
    {
        if (lcs[row][col-1] == lcs[row][col])
            col--;
        else if (lcs[row-1][col] == lcs[row][col])
            row--;
        else
        {
            reversed.push_back(str1[col-1]);
            col--;
            row--;
        }
    }

    reverse(reversed.begin(), reversed.end());
    cout << reversed << "\n";

    return 0;
}