#include <iostream>

void APlusB_5()
{
    int a, b;

    while (true)
    {
        std::cin >> a >> b;
        
        if (a == 0 && b == 0)
            break;
        
        std::cout << a + b << std::endl;
    }
}

void APlusB_6()
{
    int n, a, b;

    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        std::cin >> a;
        std::cin.ignore(1);
        std::cin >> b;

        std::cout << a + b << std::endl;
    }
}

void APlusB_7()
{
    int n, a, b;

    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        std::cin >> a >> b;

        std::cout << "Case #" << (i + 1) << ": " << a + b << std::endl;
    }
}

void APlusB_8()
{
    int n, a, b;

    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        std::cin >> a >> b;

        std::cout << "Case #" << (i + 1) << ": " << a << " + " << b << " = " << a + b << std::endl;
    }
}

int main()
{
    //APlusB_5();
    //APlusB_6();
    //APlusB_7();
    APlusB_8();
}
