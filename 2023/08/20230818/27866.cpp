// 2023.08.18., 백준 27866 문자와 문자열, https://www.acmicpc.net/problem/27866
#include <iostream>
#include <string>

int main()
{
    std::string s;
    int i;
    std::cin >> s >> i;
    std::cout << s[i-1];
    return 0;
}