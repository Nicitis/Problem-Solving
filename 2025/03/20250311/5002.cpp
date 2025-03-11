#include <iostream>

#define C_TO_VAL(c) ((c) == 'M' ? 1 : -1)

using namespace std;

int main()
{
    int maxGap, gap = 0, first = 0;
    string line;
    int answer = 0;

    cin >> maxGap;
    cin >> line;

    for (char c : line)
    {
        if (first != 0 && (gap + first <= maxGap && gap + first >= -maxGap))
        {
            gap += first;
            first = 0;
            answer++;
        }
        int val = C_TO_VAL(c);
        if (gap + val > maxGap || gap + val < -maxGap)
        {
            if (first != 0)
                break;
            first = val;
        }
        else
        {
            gap += val;
            answer++;
        }
    }
    cout << answer << '\n';
    
    return 0;
}