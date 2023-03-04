// 2023.03.04., 백준 1654 랜선 자르기, https://www.acmicpc.net/problem/1654
// 이분 탐색 알고리즘이 기억이 나지 않아서 기억을 되살릴 겸 한 번 풀었음.
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

bool canMake(const vector<int> v, int n, long long length)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (length <= v[i])
            n -= (int)(v[i] / length);
    }

    return n <= 0;
}

long long binary_search(vector<int> v, int n, long long minimum, long long maximum)
{
    // 만들 수 있으면 더 길게 해서 잘라본다. 만약 자를 수 없다면 길이를 짧게 한다.
    long long mid = (minimum + maximum) / 2LL;
    long long length = -1;

    if (minimum == maximum)
    {
        if (canMake(v, n, minimum))
            length = minimum;
        return length;
    }

    if (canMake(v, n, mid))
        length = max({mid, binary_search(v, n, mid + 1, maximum)});
    else
        length = binary_search(v, n, minimum, mid);

    return length;
}

int main()
{
    int k, n;
    cin >> k >> n;

    vector<int> lines(k, 0);
    
    for (int i = 0; i < k; i++)
    {
        cin >> lines[i];
    }

    cout << binary_search(lines, n, 1, INT_MAX);

    return 0;
}