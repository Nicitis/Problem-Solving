#include <cstdio>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int main()
{
    int N, temp;

    vector<int> liquid;
    
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &temp);
        liquid.push_back(temp);
    }

    int left = 0, right = N - 1;
    int ans_left, ans_right;
    long long sum, ans = LLONG_MAX;
    
    while (left < right)
    {
        sum = liquid[left] + liquid[right];
        if (abs(sum) < ans)
        {
            ans = abs(sum);
            ans_left = left;
            ans_right = right;
        }
        if (sum < 0)
            left++;
        else if (sum > 0)
            right--;
        else
            break;
    }

    printf("%d %d", liquid[ans_left], liquid[ans_right]);

    return 0;
}