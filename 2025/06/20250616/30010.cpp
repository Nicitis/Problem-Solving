#include <iostream>

int main()
{
    int n;

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n;

    std::cout << "2";
    for (int i = 1; i < n; i++)
    {
        std::cout << " 1";
    }
    
    return 0;
}