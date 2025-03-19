#include <iostream>

using namespace std;

int main()
{
    int n, p, t;
    int cur = 1 * 2, cnt = 1;

    cin >> n >> p >> t;

    int doubleN = 2 * n;
    bool increasePhase = true;
    for (int i = 0; i < t - 1; i++)
    {
        cur = (cur + cnt) % doubleN;
        cnt += increasePhase ? 1 : -1;
        if (increasePhase && cnt == doubleN)
        {
            increasePhase = false;
        }
        else if (!increasePhase && cnt == 1)
        {
            increasePhase = true;
        }
    }
    
    int s = cur;
    int e = (cur + cnt) % doubleN;
    bool isSuccess;
    if (s < e)
    {
        isSuccess = ((2*p+1)%doubleN >= s) && ((2*p) % doubleN < e);
    }
    else
    {
        isSuccess = ((2*p+1)%doubleN >= s) || ((2*p) % doubleN < e);
    }

    if (isSuccess)
        cout << "Dehet YeonJwaJe ^~^\n";
    else
        cout << "Hing...NoJam\n";

    return 0;
}