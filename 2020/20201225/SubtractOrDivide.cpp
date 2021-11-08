#include <iostream>

int GetMinimumOfMoves(int n);

int main()
{
    int test_case;
    std::cin >> test_case;

    int* input = (int*)malloc(sizeof(int) * test_case);

    for (int i = 0; i < test_case; i++)
        std::cin >> input[i];
    
    for (int i = 0; i < test_case; i++)
        std::cout << GetMinimumOfMoves(input[i]) << std::endl;

    free(input);

    return 0;
}

int GetMinimumOfMoves(int n)
{
    int move = 0;

    while (n != 1)
    {
        int i;
        if (n != 2 && n % 2 == 0) n = 2;
        else
            n--;
        move++;
    }

    return move;
}