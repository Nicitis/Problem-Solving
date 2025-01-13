#include <iostream>
#include <cstring>

int lcs[1000];

int main()
{
    char strA[1001], strB[1001];
    int lenA, lenB;

    std::ios_base::sync_with_stdio(false);
    std::cin >> strA;
    std::cin >> strB;

    lenA = strlen(strA);
    lenB = strlen(strB);

    int temp[1001];
    for (int i = 0; i < lenA; i++)
    {
        for (int j = 0; j < lenB; j++)
        {
            int newLcs = j > 0 ? lcs[j - 1] : 0;
            if (strA[i] == strB[j])
                newLcs++;
            temp[j] = lcs[j] >= newLcs ? lcs[j] : newLcs;
        }
        for (int j = 0; j < lenB; j++)
        {
            int prev = j > 0 ? lcs[j - 1] : 0;
            if (prev >= temp[j])
                lcs[j] = prev;
            else
                lcs[j] = temp[j];
        }
    }

    printf("%d", lcs[lenB - 1]);

    return 0;
}