#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;

    // 1부터 N이라는 수까지 수가 나오면 2와 5의 몇 거듭제곱인지 더하고, 
    // 정답은 2와 5의 거듭제곱 수의 합에 대해서 2와 5의 거듭제곱 수 중 최솟값을 반환하면 된다.

    int powerOf2 = 0, powerOf5 = 0;
    for (int i = 1; i <= N; i++)
    {
        int num = i;
        while (num % 2 == 0)
        {
            num /= 2;
            powerOf2++;
        }
        while (num % 5 == 0)
        {
            num /= 5;
            powerOf5++;
        }
    }
    cout << min(powerOf2, powerOf5) << '\n';

    return 0;
}