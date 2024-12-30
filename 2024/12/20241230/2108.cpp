#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

int main()
{
    std::vector<int> arr;
    std::map<int, int> frequency;
    int N, total = 0;

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        int data;
        scanf("%d", &data);
        total += data;
        arr.push_back(data);
        // calc frequency
        if (frequency.find(data) != frequency.end())
            frequency[data] += 1;
        else
            frequency.insert({data, 1});
    }
    std::sort(arr.begin(), arr.end());

    double average = (double)total / N;
    int median = arr[N / 2];
    int range = arr[N-1] - arr[0];
    // find mode
    int mode = arr[0];
    int maxFreq = frequency[arr[0]];
    bool findSecondElem = false;
    for (auto iter : frequency)
    {
        if (iter.first == mode)
            continue;
        
        if (iter.second > maxFreq)
        {
            mode = iter.first;
            maxFreq = iter.second;
            findSecondElem = false;
        }
        else if (iter.second == maxFreq && !findSecondElem) 
        {
            mode = mode = iter.first;
            maxFreq = iter.second;
            findSecondElem = true;
        }
    }

    printf("%d\n", (int)round(average));
    printf("%d\n", median);
    printf("%d\n", mode);
    printf("%d\n", range);

    return 0;
}