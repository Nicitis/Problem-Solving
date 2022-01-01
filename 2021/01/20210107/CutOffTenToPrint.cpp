#include <iostream>
#include <iomanip>

int main()
{
    char data[11];
    while(true)
    {
        std::cin >> std::setw(11) >> data;
        if (std::cin.eof())
            break;
        std::cout << data << std::endl;
    }
    return 0;
}

/*#include <stdio.h>

int main()
{
    int i;
    char data[11], c;
    while(scanf("%10s", data) != EOF)
    {
        puts(data);
    }
    return 0;
}*/

/*
#include <stdio.h>

int main()
{
    int i;
    char data[101], c;
    gets(data);
    while (data[i] != 0)
    {
        if (i != 0 && i % 10 == 0) puts("");
        putchar(data[i++]);
    }
    puts("");
    return 0;
}
*/