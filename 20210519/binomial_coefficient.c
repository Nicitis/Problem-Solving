#include <stdio.h>
#define N 30

int bin(int n, int k) {
  int bin_arr[N][N] = { 0 }; 
  // 배열 bin_arr의 모든 값을 0으로 초기화(N은 상수, n<N)
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= i; j++) {
      if (j == 0 || i == j)
        bin_arr[i][j] = 1;
      else
        bin_arr[i][j] = bin_arr[i-1][j-1] + bin_arr[i-1][j];
    }
  }
  return bin_arr[n][k];
}

int bin_memo[N][N] = { 0 };
// 배열 bin_arr의 모든 값을 0으로 초기화(N은 상수, n<N)
int bin_mem(int n, int k) {
    if (bin_memo[n][k] != 0) // 값이 메모되어 있을 경우 메모된 값을 반환
        return bin_memo[n][k];  
    if (k == 0 || n == k)
        bin_memo[n][k] = 1;
    else
        bin_memo[n][k] = bin_mem(n-1, k-1) + bin_mem(n-1, k);
    return bin_memo[n][k];
}

int main()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= i; j++)
            printf("%d ", bin(i, j));
        printf("\n");
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= i; j++)
            printf("%d ", bin_mem(i, j));
        printf("\n");
    }
}