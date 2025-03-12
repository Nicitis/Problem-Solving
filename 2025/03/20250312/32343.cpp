#include <iostream>

using namespace std;

int main()
{
    // x의 개수 : a개
    // y의 개수 : b개
    // x^y의 최댓값?
    // 1이 최대 min((a+b), N) = k개!
    // k개의 1을 가질 때, 최댓값은 얼마인가?
    // k개의 1 -> 2^(n-1) + 2^(n-2) + ... + 2^(n-k)
    //즉, 2^(n-k)(1+2+4+...+2^{(n-1) - (n-k) = k-1})
    // = 2^(n-k) * (2^k-1)

    // 1 + 2 + 4 = 8 - 1 = 2^3-1

    int n, a, b, k, answer;
    cin >> n >> a >> b;

    k = (a + b < n) ? (a + b) : (2 * n - a - b);
    answer = (1 << (n-k)) * ((1 << k) - 1);

    cout << answer;

    return 0;
}