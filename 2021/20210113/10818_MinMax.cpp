// Backjoon 10818 최소, 최대(https://www.acmicpc.net/problem/10818)
#include <cstdio>
#include <climits>

using namespace std;

int main()
{
    int n;
    int min = INT_MAX;
    int max = INT_MIN;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int data;
        scanf("%d", &data);
        min = min <= data ? min : data;
        max = max >= data ? max : data;
    }
    printf("%d %d\n", min, max);
    return 0;
}