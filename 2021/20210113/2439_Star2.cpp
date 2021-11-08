// 백준 2439 별 찍기 - 2 (https://www.acmicpc.net/problem/2439)
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string out = "";
        for (int j = 0; j <= i; j++)
        {
            out += "*";
        }
        cout << setw(n) << out << "\n";
    }

    return 0;
}