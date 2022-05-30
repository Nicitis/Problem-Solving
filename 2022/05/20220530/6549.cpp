#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

long long biggest_histogram(vector<long long>& histogram, int left, int right)
{
    // 최소 조건
    if (left == right)
        return histogram[left];
    
    int mid = (left + right) / 2;
    long long rect_left = biggest_histogram(histogram, left, mid);
    long long rect_right = biggest_histogram(histogram, mid + 1, right);
    
    // 가운데 영역을 포함한 최대 넓이 히스토그램
    int area_left = mid, area_right = mid + 1;
    long long height = min(histogram[area_left], histogram[area_right]);
    long long rect_mid = height * (area_right - area_left + 1);

    while (area_left > left || area_right < right)
    {
        while (area_left > left && histogram[area_left - 1] >= height)
            area_left--;
        while (area_right < right && histogram[area_right + 1] >= height)
            area_right++;
        
        rect_mid = max(rect_mid, height * (area_right - area_left + 1));
        
        // 둘 중 상대적으로 큰 쪽으로 이동한다.
        if (area_left == left)
        {
            if (area_right < right)
            {
                area_right++;
                height = histogram[area_right];
            }
        }
        else if (area_right == right)
        {
            area_left--;
            height = histogram[area_left];
        }
        else
        {
            if (histogram[area_left - 1] >= histogram[area_right + 1])
            {
                area_left--;
                height = histogram[area_left];
            }
            else
            {
                area_right++;
                height = histogram[area_right];
            }
        }
    }
    rect_mid = max(rect_mid, height * (area_right - area_left + 1));

    return max({rect_left, rect_right, rect_mid});
}

int main()
{
    int n;
    vector<long long> histogram;

    while (true)
    {
        cin >> n;
        if (n == 0)
            break;
        
        histogram = vector<long long>(n, 0);
        for (int i = 0; i < n; i++)
            cin >> histogram[i];
        
        cout << biggest_histogram(histogram, 0, n - 1) << '\n';
    }

    return 0;
}