#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int number;
    int digits[6], idx = 0;
    cin >> number;

    while (number > 0)
    {
        digits[idx++] = number % 10;
        number /= 10;
    }
    sort(digits, digits + idx);

    number = 0;
    for (int i = idx - 1; i >= 0; i--)
    {
        number = number * 10 + digits[i];
    }
    cout << number << '\n';

    return 0;
}