// 백준 3003: 킹, 퀸, 룩, 비숍, 나이트, 폰
#include <iostream>

int main()
{
    int pieces[] = { 1, 1, 2, 2, 2, 8 };
    int currentPiece;

    for (int i = 0; i < 6; i++)
    {
        std::cin >> currentPiece;
        std::cout << pieces[i] - currentPiece << ' ';
    }

    return 0;
}