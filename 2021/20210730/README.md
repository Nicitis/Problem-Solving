# 2021.07.30. 풀이

## 1912 연속합

### 아이디어

연속합 문제는 여러 방면으로 생각해볼 수 있다.

다양한 방법으로 해결할 수 있다는 것이다.

그러나 N <= 100,000이므로 O(N^2) 이상의 알고리즘은 택하기 어렵다.

1. 분할정복법 => O(nlogn) (성공 - 16ms)
    
    max(좌측 구간의 연속합, 우측 구간의 연속합, 중앙부터 좌측으로 최대 연속합 + 중앙부터 우측으로 최대 연속합)
    
2. 부분합을 배열로 구하고, max(가장 큰 수, i < j에 대하여 i번째 수와 j번째 수의 부분합의 차가 최대가 될 때)를 구한다. => O(N^2)
3. 처음부터 연속 부분합을 구한다. 
    
    연속 부분합이 음수가 되면 0으로 초기화한 뒤 다음 항부터 다시 구한다. 최대 부분 연속합이 최대 연속합이 된다. => O(N) (성공 - 13ms)

## 2579 계단 오르기

### 아이디어

최대 와인 마시기와 유사한 문제로 보이지만 조건이 까다로워서 경우의 수를 잘 생각해보아야 한다.

d(i)는 i번째 계단까지 왔고 i번째 계단을 밟았을 때 최대 점수이다.

이 경우, 다음과 같은 경우가 있다.

1. 한 계단만 오르는 경우
    
    d(i) = d(i - 3) + score(i - 1) + score(i)
    
2. 두 계단을 오를 경우
    
    d(i) = d(i - 2) + score(i)

결론적으로 n번째 계단을 밟을 때 최대 점수는 d(n)으로 구한다.