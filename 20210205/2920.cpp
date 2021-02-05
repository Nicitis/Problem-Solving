// COCI 2009/2010 Contest #1
// 1. 백준 2920 음계(https://www.acmicpc.net/problem/2920)
#include <iostream>

int main()
{
    int delta = 0, prev_delta;
    const int count = 8;

    int prev_input;
    std::cin >> prev_input;
    for (int i = 1; i < count; i++)
    {
        int input;
        std::cin >> input;
        delta = input - prev_input;
        if (delta != 0 && (i == 1 || delta == prev_delta))
        {
            prev_input = input;
            prev_delta = delta;
            continue;
        }
        else
        {
            delta = 0;
            break;
        }
    }

    if (delta == 1)
        std::cout << "ascending" << std::endl;
    else if (delta == -1)
        std::cout << "descending" << std::endl;
    else
        std::cout << "mixed" << std::endl;
    
    return 0;
}