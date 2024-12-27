#include <stdio.h>

int main()
{
    int T;
    char str[51];
    scanf("%d", &T);
    int cnt;
    for (int t = 0; t < T; t++)
    {
        scanf("%s", str);
        char* target = str;
        // stack count로 추적
        cnt = 0;
        while (*target != '\0')
        {
            if (*target++ == '(')
                cnt++;
            else
                cnt--;
            if (cnt < 0)
                break;
        }
        printf("%s", cnt == 0 ? "YES\n" : "NO\n");

    }

    return 0;
}