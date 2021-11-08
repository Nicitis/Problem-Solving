#include <iostream>

// Backjoon 11720 숫자의 합(https://www.acmicpc.net/problem/11720)
int main()
{
    int n;
    int sum = 0;

    std::cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        char enter;
        std::cin >> enter;
        sum += enter - '0';
    }

    std::cout << sum << std::endl;

    return 0;
}

// C Style
// #include <stdio.h>

// int main()
// {
//     int n, sum = 0, i;
//     char data[101];
//     scanf("%d %s",&n,data);
//     for(i=0;i<n;i++)
//     {
//         sum += data[i]-'0';
//     }
//     printf("%d\n", sum);
//     return 0;
// }