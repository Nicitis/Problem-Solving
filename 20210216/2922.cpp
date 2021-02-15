// 3. 백준 2922 즐거운 단어(https://www.acmicpc.net/problem/2922)
#include <cstdio>
#include <cstring>

char word[101];
long long makeword(int index)
{
    while(true)
    {
        if (word[index] == '\0')
        {
            int c = 0, v = 0;
            bool l = false;
            for (int i = 0; i < index; i++)
            {
                if (word[i] == 'C' || word[i] == 'L')
                {
                    c++;
                    v = 0;
                    if (word[i] == 'L') l = true;
                }
                else if (word[i] == 'V')
                {
                    v++;
                    c = 0;
                }
                
                if (c >= 3 || v >= 3)
                    return 0LL;
            }
            if (l == true) { return 1LL;}
            else return 0LL;
        }
        if (word[index] == '_')
        {
            long long result = 0LL;
            word[index] = 'C'; result += 20LL * makeword(index + 1);
            word[index] = 'V'; result += 5LL * makeword(index + 1);
            word[index] = 'L'; result += makeword(index + 1);
            word[index] = '_';
            return result;
        }
        index++;
    }
}

int main()
{
    scanf("%s", word);
    int len = strlen(word);
    for (int i = 0; i < len; i++)
    {
        char c = word[i];
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            word[i] = 'V';
        else if (c != '_' && c != 'L')
            word[i] = 'C';
    }
    printf("%lld\n", makeword(0));
}