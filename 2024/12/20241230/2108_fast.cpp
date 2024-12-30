#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

int freq[8001];
int main()
{
    std::vector<int> arr;
    int N, total = 0;

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        int data;
        scanf("%d", &data);
        total += data;
        arr.push_back(data);
        // calc frequency
        freq[data + 4000]++;
    }
    std::sort(arr.begin(), arr.end());

    double average = (double)total / N;
    int median = arr[N / 2];
    int range = arr[N-1] - arr[0];
    // find mode
    int mode = -4001;
    int maxFreq = -1;
    bool findSecondElem = false;
    for (int i = -4000; i <= 4000; i++)
    {
        if (freq[i + 4000] > maxFreq)
        {
            mode = i;
            maxFreq = freq[i + 4000];
            findSecondElem = false;
        }
        else if (freq[i + 4000] == maxFreq && !findSecondElem) 
        {
            mode = mode = i;
            maxFreq = freq[i + 4000];
            findSecondElem = true;
        }
    }

    printf("%d\n", (int)round(average));
    printf("%d\n", median);
    printf("%d\n", mode);
    printf("%d\n", range);

    return 0;
}