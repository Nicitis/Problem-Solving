#include <iostream>
/*
21:33~22:01

N % P1 = X1,
N % P2 = X2,
N % P3 = X3
인 가장 작은 정수 N을 찾으시오.
이때 N은 10억 미만의 자연수이다.

즉,
P1 * p + X1 = N
P2 * q + X2 = N
P3 * r + X3 = N
(단, p, q, r은 음이 아닌 정수)

최소의 N이려면, p, q, r이 최소가 되는 값이어야 한다

서로소 같은데?

20 20 20 1 2 3
-1

1. P1 == P2이고 X1 != X2, 또는 P2 == P3이고 X2 != X3, 
또는 P3 == P1이고 X3 != X1이면 해가 없음

2 3 5 1 1 1
2p + 1 = 3q + 1 = 5r + 1
p = q = r = 0일 때 N=1

2 4 8 1 2 3
2p + 1 = 4q + 2 = 8r + 3

최소공배수를 구하면 안된다.

모두 탐색? 안돼. 10억개를 모두 찾을 순 없어.

수학적 규칙을 찾자.
첫 번째. P1, P2를 만족하는 p, q의 규칙은?
P1 * p + X1 = P2 * q + X2
P1 * p - P2 * q = X2 - X1

N = P1 * p + X1을 만족하는 모든 N에 대해서...
N % P2 = X2이고 N % P3 = X3인가?

X1, P1+X1, P1*2+X1, ..., 10억

시간 복잡도: 

중국인의 나머지 정리... 문제다




*/

using namespace std;

int main()
{



    return 0;
}