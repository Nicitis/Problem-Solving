#include <iostream>
#include <string>

// Backjoon 11719 그대로 출력하기(https://www.acmicpc.net/problem/11719)
int main()
{
    std::string line;
    while (true)
    {
        std::getline(std::cin, line);
        if (std::cin.eof())
            break;
        std::cout << line << std::endl;
    }
    return 0;
}

/* C Style
#include <stdio.h>

int main()
{
    char data[101];
    while (gets(data) != NULL)
    {
        puts(data);
    }
    return 0;
}
*/