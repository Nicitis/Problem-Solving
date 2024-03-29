# 2021.08.02 문제 풀이

## 2133 타일 채우기

### 아이디어

3 x N에서 N이 홀수일 때는 타일 하나가 2칸이므로 메울 방법이 없다.

3 x N에서 N이 짝수일 때는 순차적으로 구할 수 있다.

f(n)을 3 x n에서 타일을 채우는 경우의 수라 하자.

3 x 2는 f(2) = 3으로 3개의 경우의 수가 있다.

3 x 4는 f(4) = f(2) x 3 + 2이다.

f(2) x 3인 것은 3 x 2에서 우측 3 x 2를 채우는 경우의 수는 3이기 때문이고, 2를 더하는 이유는 타일을 엇갈리게 놓는 방법이 2가지이기 때문이다. 여기서 타일을 엇갈리게 놓는 것은 3 x 4에서도 2가지, 3 x 6에서도 2가지, 3 x 2N에서도 2가지이다.

이를 이용하면 다음과 같은 점화식을 도출할 수 있다.

N = 2k - 1(단, k는 정수)일 때, f(N) = 0

N = 2k(단, k는 정수)일 때, f(N) = f(N - 2) x 3 + f(N - 4) x 2 + f(N - 6) x 2 + ... + f(2) x 2 + 2

정리하면 f(N) = f(N - 2) x 3 + (f(N - 4) + f(N - 6) + ... + f(2) + 1) x 2

### 축약형

f(N - 2) = f(N - 4) x 3 + (f(N - 6) + ... + f(2) + 1) x 2

f(N) - f(N-2) = f(N-2) x 3 - f(N-4)

마지막으로 정리하면 다음과 같다.

f(N) = f(N-2) x 4 - f(N-4)

## 9461 파도반 수열

### 아이디어

9번째 수까지는 다소 불규칙적이지만 10번째 수부터는

P(N) = P(N-1) + P(N-5)

로 정의할 수 있다.

### 되돌아보기

실제 테스트 결과 마지막 항이 888855064897까지 증가하여 long long으로 바꿔주어야 했다.

이렇게 첫 항, 마지막 항에 대한 테스트를 거치지 않고 진행하면 문제가 발생할 수 있다. 모든 항을 테스트할 수 없다면 극단적인 경우라도 테스트하는 것을 잊지 말자.

그리고 풀어보니 테스트 케이스가 여러 개가 있다면 아예 dp를 처음부터 끝까지 모두 계산해놓고 푸는 방법도 유용한 듯하다.

dp는 그리 많은 연산 시간이 걸리지 않고 c++ 자체도 최적화가 잘 되어 있어서 모든 범위에 대해 미리 계산하는 것도 도움이 될 것이다.
