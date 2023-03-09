// 2023.03.09., 연산자 끼워넣기, https://www.acmicpc.net/problem/14888
#include <iostream>
#include <climits>

int minimum = INT_MAX;
int maximum = INT_MIN;

void intervene(int a[], int index, int n, int plus, int minus, int mult, int div, int result)
{
    if (index == n)
    {
        minimum = result < minimum ? result : minimum;
        maximum = result > maximum ? result : maximum;
        return;
    }

    if (plus > 0)
        intervene(a, index + 1, n, plus - 1, minus, mult, div, result + a[index]);
    if (minus > 0)
        intervene(a, index + 1, n, plus, minus - 1, mult, div, result - a[index]);
    if (mult > 0)
        intervene(a, index + 1, n, plus, minus, mult - 1, div, result * a[index]);
    if (div > 0)
        intervene(a, index + 1, n, plus, minus, mult, div - 1, result / a[index]);
}

int main(void)
{
    int n, a[11], plus, minus, mult, div;

    std::cin >> n;
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    
    std::cin >> plus >> minus >> mult >> div;

    intervene(a, 1, n, plus, minus, mult, div, a[0]);

    std::cout << maximum << '\n' << minimum << '\n';

    return 0;
}