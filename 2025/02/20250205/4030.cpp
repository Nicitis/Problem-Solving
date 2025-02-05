/*
A, B가 주어질 때 a<x+1<b인 x+1의 개수를 구하여라
1. x은 삼각형 모양으로 나열할 수 있다
2. x+1은 m x m 트레이에 넣을 수 있어야 한다. 즉, 모든 공을 넣었을 때 빈칸이 있으면 안된다.

이때 삼각형 모양으로 나열할 수 있는 수 x는 다음과 같은 꼴이다
x = 1 + 2 + ... + (n-1) + n
= n(n-1)/2인 n

m x m 내에 넣을 수 있으려면 x + 1은 다음과 같은 수이다
x + 1 = m x m

x = n(n+1)/2일 때,
n(n-1)/2 + 1
= (n*n - n + 2)/2 = m x m 꼴이어야 한다.
좀 더 정리하면,
n*n - n + 2 = 2m x m
이때 a < b <= 10^9으로 a, b는 int의 최댓값보다 작은 1,000,000,000보다 작거나 같다.
문제는 2m * m이 되면 값의 범위가 int의 최댓값을 넘는다는 점이다(20억 정도)
즉, n(n-1)/2 + 1 = m * m으로 구해야 함

과정은 이렇다.
1. 우선 a < n(n-1)/2 + 1 < b인 모든 n을 구하고,
2. 이 값이 n(n-1)/2 + 1 = m * m으로 되는지 보기
아니면 역으로, x+1에 대해 n(n-1)/2 + 1로 구성되는지 볼 수도 있다
x = n(n-1)
아니면... 제곱수라는 점을 고려하면 n은 몇 개 안 구해도 되긴 한다
루트 n개니까 뭐... 다 구해도 될듯(결과를 long long으로 하는 게 안전)

그런데 여기서 잘 보면, 여러 번 같은 구간을 구하는 걸 볼 수 있다. 0 0 나오기 전까진 계속 봄
dp하는 게 낫나? x마다 모두 값 계산해서 저장하는 건 비효율적인데 ㅋㅋ;
a = n(n+1)/2 + 1부터 봐야 하니
(a - 1) * 2 = n(n-1)
그냥 n = sqrt(a - 1) + 1부터 보면 될듯

m * m?

  1101
* 1101
------
   1101
 1101
1101
------
10101001 관계가 없어 보이는데...
*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (int i = 1;;i++)
    {
        int a, b;
        cin >> a >> b;

        if (a == 0 && b == 0)
            break;
        
        int start = sqrt(a - 1) + 1;
        int answer = 0;
        for (long long n = start; (n * (n - 1) / 2 + 1) < b; n++)
        {
            // n(n+1)/2 + 1 = m * m?
            long long lhs = n * (n - 1LL) / 2LL + 1LL;
            if (lhs <= a)
                continue;
            
            double m = sqrt((double)lhs);
            if (m == (double)((int)m))
            {
                answer++;
            }
        }
        cout << "Case " << i << ": " << answer << '\n';
    }

    return 0;
}