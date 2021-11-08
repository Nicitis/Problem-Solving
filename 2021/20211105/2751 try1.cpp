// 백준 2751: 수 정렬하기 2(C++)
#include <iostream>

#define MIN(X, Y) ((X)<(Y)?(X):(Y))

int N[1000000];

// int endpoint;

// void printlist()
// {
//     std::cout << "====" << '\n';

//     int i;
//     for (i = 0; i < endpoint; i++)
//         std::cout << N[i] << ' ';
//     std::cout << '\n';
// }

void swap(int* pa, int* pb)
{
    int temp = *pa;
    *pa = *pb;
    *pb = temp;
}

// 퀵정렬을 사용해보자.
/*
퀵정렬 방식
1. 좌측, 가운데, 우측 수 중 중앙값을 pivot으로 정함
    우측 수가 중앙 값이 아니라면
    pivot 수를 최우측 수와 바꾸고 최우측 값을 pivot으로 결정
2. 우측 ptr와 좌측 ptr을 움직이며 pivot보다 작은 값은 좌측, 크거나 같은 값은 우측에 둔다.
    (단, 같은 값은 없을 예정)
3. 우측 ptr와 좌측 ptr가 교차될 경우 pivot과 우측 ptr을 바꿈
4. 좌측 구간, 우측 구간을 분할하여 다시 정렬함
*/
// s: inclusive, e: exclusive
void qsort(int s, int e)
{
    int l, r, m, p, temp;
    l = s;
    r = e - 2;
    m = (s + e) / 2;

    if (s >= e - 1)
        return;
    // decide pivot
    temp = MIN(N[s], MIN(N[m], N[e - 1]));
    if (temp == N[s]) // 좌측값 최소
    {
        if (N[m] < N[e - 1]) // 중앙 중앙
            swap(&N[m], &N[e - 1]);
    }
    else if (temp == N[m]) // 중간 최소
    {
        if (N[l] < N[e - 1]) // 좌측 중앙
            swap(&N[l], &N[e - 1]);
    }
    else // 우측값 최소
    {
        if (N[l] < N[m]) // 좌측 중앙
            swap(&N[l], &N[e - 1]);
        else // 중앙 중앙
            swap(&N[m], &N[e - 1]);
    }
    p = e - 1;
    // std::cout << "p = " << p << '\n';
    // printlist();

    while(l <= r)
    {
        while(N[l] < N[p])
            l++;
        while(N[r] >= N[p])
            r--;
        if (l < r)
            swap(&N[l++], &N[r--]);
    }
    swap(&N[l], &N[p]);

    // print
    // printlist();

    qsort(s, l);
    qsort(l + 1, e);
}

int main()
{
    int T, i;
    std::ios_base::sync_with_stdio(false);
    std::cin >> T;

    // endpoint = T;

    for (i = 0; i < T; i++)
        // std::cin >> N[i];
        N[i] = T - i;

    qsort(0, T);

    for (i = 0; i < T; i++)
        std::cout << N[i] << '\n';
    return 0;
}