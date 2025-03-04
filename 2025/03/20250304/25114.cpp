#include <cstdio>

int a[1000000]

int main()
{
    int n, x, b;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    scanf("%d", &b);
    x = a[0] ^ b;

    // a ^ x = b
    // b ^ x = a
    // 01 -> 11
    // x=10


    return 0;
}