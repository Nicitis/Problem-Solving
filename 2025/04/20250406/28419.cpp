#include <iostream>
#include <cmath>

using namespace std;

/*
연산은 '인접한 세 값을 1씩 증가시킨다.'이므로, n >= 4일 땐
- 홀수 번째 위치의 합이 +2, 짝수 번째 위치의 합이 +1 되게 하기
- 홀수 번째 위치의 합이 +1, 짝수 번째 위치의 합이 +2 되게 하기
둘 중 하나의 연산을 수행할 수 있다.
따라서

n >= 4 이상일 때
answer = abs(홀수 번째 위치의 합 - 짝수 번째 위치의 합)

n = 3일 때
홀수 번째 위치의 합은 2씩 증가하고, 짝수 번째 위치의 합은 1씩 증가한다.
따라서
i) 홀수 번째 위치의 합 > 짝수 번째 위치의 합 -> 출력 -1
ii) 홀수 번째 위치의 합 <= 짝수 번째 위치의 합 
-> 출력 (짝수 번째 위치의 합 - 홀수 번째 위치의 합)
*/

int main()
{
    int n, input;
    long long oddSum = 0, evenSum = 0;

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> input;
        if (i % 2 == 0)
            evenSum += input;
        else
            oddSum += input;
    }

    if (n == 3 && oddSum > evenSum)
    {
        cout << "-1\n";
    }
    else
    {
        cout << abs(evenSum - oddSum);
    }

    return 0;
}