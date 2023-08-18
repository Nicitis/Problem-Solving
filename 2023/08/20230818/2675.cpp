// 2023.08.18., 백준 2675 문자열 반복, https://www.acmicpc.net/problem/2675
#include <cstdio>

int main()
{
    char string[21];
    int T;

    scanf("%d", &T);

    while (T-- > 0)
    {
        int repeat;
        scanf("%d %s", &repeat, string);
        for (int i = 0; string[i] != '\0'; i++)
        {
            for (int r = 0; r < repeat; r++)
            {
                printf("%c", string[i]);
            }
        }
        printf("\n");
    }

    return 0;
}
