#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 첫 글자 
    char str1[1001], str2[1001];
    char lcs[1001];
    int prevpos[1001]; // str2 기준 최대 길이 및 직전 문자

    cin >> str1 >> str2;

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    fill(lcs, lcs + 1001, 0);
    fill(prevpos, prevpos + 1001, -1);

    int temp[1001];
    int longestPrevPos = -1;
    for (int i = 0; i < len1; i++)
    {
        cout << str1[i] << "] ";
        for (int j = 0; j < len2; j++)
        {
            // 같으면 갱신
            int prev = longestPrevPos == -1 ? 0 : lcs[longestPrevPos];
            temp[j] = lcs[j];
            if (str1[i] == str2[j])
            {
                temp[j] = longestPrevPos + 1;
                if (prev != 0)
                    prevpos[j] = longestPrevPos;
                if ()
            }
            // 다르면, 이전 문자 temp와 현재 lcs 중 비교
            else if (j != 0 && temp[j - 1] > lcs[j])
            {
                temp[j] = temp[j - 1];
                prevpos[j] = prevpos[j - 1];
            }

            cout << temp[j] << " ";
        }
        cout << '\n' << "pre";
        for (int j = 0; j < len2; j++)
        {
            if (prevpos[j] == -1)
            {
                cout << "_ ";
            }
            else
                cout << str2[prevpos[j]] << ' ';
        }
        cout << '\n';

        // 갱신
        for (int j = 0; j < len2; j++)
        {
            lcs[j] = temp[j];
        }
    }

    vector<char> reverseAnswer;
    int pos = len2 - 1;
    reverseAnswer.push_back(str1[pos]);
    while (prevpos[pos] != -1)
    {
        pos = prevpos[pos];
        reverseAnswer.push_back(str1[pos]);
    }

    reverse(reverseAnswer.begin(), reverseAnswer.end());

    cout << reverseAnswer.data() << '\n';

    return 0;
}