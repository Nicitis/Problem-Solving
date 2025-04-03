#include <iostream>
#include <string>

using namespace std;

bool FindExactlyEqualNumber(int divisor, int target)
{
    int left = 0, right = divisor * 10, mid;
    int fraction;

    while (left <= right)
    {
        mid = (left + right) / 2;
        fraction = mid * 1000 / divisor;

        if (fraction > target)
        {
            right = mid - 1;
        }
        else if (fraction < target)
        {
            left = mid + 1;
        }
        else // ==
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int n;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int averageInt[50];
    int integer, fraction;
    string input;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> input;
        int idx = input.find('.');
        integer = stoi(input.substr(0, idx));
        fraction = stoi(input.substr(idx+1));
        averageInt[i] = integer * 1000 + fraction;
    }

    bool success;
    for (int i = 1; i <= 1000; i++)
    {
        success = true;
        for (int j = 0; j < n; j++)
        {
            if (!FindExactlyEqualNumber(i, averageInt[j]))
            {
                success = false;
                break;
            }
        }
        if (success)
        {
            cout << i << "\n";
            break;
        }
    }


    return 0;
}