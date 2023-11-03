// 백준-2110 공유기 설치
#include <cstdio>
#include <algorithm>

int is_installable(int *begin, int *end, int min_dist, int c);
// begin, end : inclusive
int binary_search(int *begin, int *end, int upper_limit, int c);
// void qsort(int *begin, int *end);
// int *partition(int *begin, int *end);
// void swap(int *a, int *b);

int main(void)
{
    int N, C, max_dist, i;

    int pos[200000];
    
    scanf("%d %d", &N, &C);

    for (i = 0; i < N; i++)
        scanf("%d", &pos[i]);

    // qsort(pos, pos + N - 1); // 오름차순 정렬
    std::sort(pos, pos + N);

    max_dist = (pos[N-1] - pos[0]) / (C - 1); // 이론상 최대거리
    max_dist = binary_search(pos, pos + N - 1, max_dist, C);

    printf("%d", max_dist);

    return 0;
}

int is_installable(int *begin, int *end, int min_dist, int c)
{
    int prev = *(begin++);
    c--;
    while (begin <= end)
    {
        if (*begin - prev >= min_dist)
        {
            c--;
            prev = *begin;
            if (c == 0)
                return 1;
        }
        begin++;
    }
    return c <= 0;
}

int binary_search(int *begin, int *end, int upper_limit, int c)
{
    int min = 0, max = upper_limit, result = 1;
    while (min <= max)
    {
        int mid = (min + max) / 2;

        if (is_installable(begin, end, mid, c))
        {
            result = mid;
            min = mid + 1;
        }
        else
            max = mid - 1;
    }

    return result;
}

// void qsort(int *begin, int *end)
// {
//     int *mid = begin + (end - begin) / 2;

//     if (begin >= mid)
//         return;

//     int *pivot = partition(begin, end);

//     qsort(begin, pivot - 1);
//     qsort(pivot + 1, end);
// }

// int *partition(int *begin, int *end)
// {
//     int *left = begin, *right = end - 1, *pivot = end;
//     while (left < right)
//     {
//         while (*left < *pivot && left < end) left++;
//         while (*right > *pivot && right >= begin) right--;

//         if (left < right) // 교차하지 않았을 경우 교환
//             swap(left, right);
//     }
//     swap(pivot, left);

//     return left; // return pivot position
// }

// void swap(int *a, int *b)
// {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }