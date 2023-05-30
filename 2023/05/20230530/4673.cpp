// 2023.05.30., 백준 4673 셀프 넘버, https://www.acmicpc.net/problem/4673
// 간만에 코딩 시작하기!
#include <cstdio>

bool selfNum[10000];

int d(int n)
{
    int result = n;
    do
    {
        result += n % 10;
        n /= 10;
    } while (n > 0);

    return result;
}

int main()
{
    int n;
    for (int i = 0; i < 10000; i++)
        selfNum[i] = true;

    for (int i = 1; i < 10000; i++)
        selfNum[d(i)] = false;
    
    for (int i = 1; i < 10000; i++)
        if (selfNum[i])
            printf("%d\n", i);

    return 0;
}