// 분할 정복법으로 부분 구간의 합 구하기(알고리즘 수업 참고)
// #include <cstdio>

// int maxSum(int array[], int start, int end)
// {
//     if (start == end)
//         return array[start];

//     int m = (start + end)/2;
//     int sum = maxSum(array, start, m);
//     int temp = maxSum(array, m + 1, end);
//     if (sum < temp)
//         sum = temp;
    
//     int leftSum = array[m];
//     temp = array[m];
//     for (int i = m - 1; i >= start; i--)
//     {
//         temp += array[i];
//         if (leftSum < temp)
//             leftSum = temp;
//     }
//     int rightSum = array[m + 1];
//     temp = array[m + 1];
//     for (int i = m + 2; i <= end; i++)
//     {
//         temp += array[i];
//         if (rightSum < temp)
//             rightSum = temp;
//     }

//     if (leftSum + rightSum > sum)
//         sum = leftSum + rightSum;
//     return sum;
// }

// int main(void)
// {
//     int n, data[100000];
//     scanf("%d", &n);

//     for (int i = 0; i < n; i++)
//         scanf("%d", &data[i]);
    
//     printf("%d", maxSum(data, 0, n - 1));
// }

// 부분합을 모두 구하면서 최대 부분합 구하기
#include <cstdio>

int main()
{
    int n, data[100000], i, max_sum = -1000, sum = 0;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &data[i]);

        sum += data[i];
        
        if (sum > max_sum)
            max_sum = sum;
        if (sum < 0)
            sum = 0;
    }

    printf("%d\n", max_sum);
}