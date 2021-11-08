/*
#include <stdio.h>

4int main()
{
    int a, b;

    // scanf: EOF�� ��ȯ�� ��� �Է��� �ߴ��Ѵ�.
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
        if (std::cin.eof()) // C++���� std::cin.eof() �Լ��� ���� �Է��� ���� Ȥ�� ������ ���Ḧ �����Ѵ�.
            break;
        std::cout << a + b << '\n';
    }
    return 0;
}