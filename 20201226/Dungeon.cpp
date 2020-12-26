#include <iostream>

bool CanCompleteWithEnhancedShot(int a, int b, int c);

int main()
{
    int test_case;
    int *points_a, *points_b, *points_c;
    
    std::cin >> test_case;
    
    points_a = (int *)malloc(sizeof(int) * test_case);
    points_b = (int *)malloc(sizeof(int) * test_case);
    points_c = (int *)malloc(sizeof(int) * test_case);

    for (int i = 0; i < test_case; i++)
    {
        std::cin >> points_a[i];
        std::cin >> points_b[i];
        std::cin >> points_c[i];
    }

    for (int i = 0; i < test_case; i++)
    {
        std::cout << (CanCompleteWithEnhancedShot(points_a[i], points_b[i], points_c[i]) ? "YES" : "NO") << std::endl;
    }

    free(points_a);
    free(points_b);
    free(points_c);
}

bool CanCompleteWithEnhancedShot(int a, int b, int c)
{
    // i) (a + b + c) % 9 == 0
    // ii) a, b, c >= n (n = (a + b + c) / 9)
    int d = (a + b + c) / 9;
    int r = (a + b + c) % 9;

    return r == 0 && a >= d && b >= d && c >= d;
}