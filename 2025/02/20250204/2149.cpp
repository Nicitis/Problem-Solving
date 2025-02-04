#include <cstdio>
#include <cstring>
#include <algorithm>

#define CIPair std::pair<char, int>
// CIPair: <char, index>

bool compare(CIPair a, CIPair b)
{
    if (a.first == b.first)
    {
        return a.second < b.second;
    }
    return a.first < b.first;
}

int main()
{
    char key[11];
    char cipher[101];
    char plain[101];
    int n, h;

    scanf("%s", &key);
    scanf(" %s", &cipher);

    n = strlen(key);
    h = strlen(cipher) / n;

    CIPair keyIndex[10];
    for (int i = 0; i < n; i++)
    {
        keyIndex[i] = std::make_pair(key[i], i);
    }
    std::sort(keyIndex, keyIndex + n);

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int newJ = keyIndex[j].second;
            plain[i*n+newJ] = cipher[j*h+i];
        }
    }
    plain[n*h] = '\0';
    printf("%s\n", plain);

    return 0;
}