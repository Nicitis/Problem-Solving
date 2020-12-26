/*
#include <stdio.h>

4int main()
{
    int a, b;

    // scanf: EOF를 반환할 경우 입력을 중단한다.
    while (scanf("%d %d", &a, &b) != EOF)
    {
        printf("%d\n", a + b);
    }
    return 0;
}
*/

#include <iostream>
int main()
{
    int a, b;

    while (1)
    {
        std::cin >> a >> b;
        if (std::cin.eof()) // C++에서 std::cin.eof() 함수를 통해 입력의 종료 혹은 파일의 종료를 감지한다.
            break;
        std::cout << a + b << '\n';
    }
    return 0;
}