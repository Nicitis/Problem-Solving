#include <iostream>
#include <cstring>

#define STARTLEN (8)

using namespace std;

int main()
{
    int len;
    char t[101], answer[101];
    const char* startStr = "CHICKENS";

    cin >> t;

    len = strlen(t);

    bool success;
    for (int k = 0; k < 256; k++)
    {
        success = true;
        for (int i = 0; i < STARTLEN; i++)
        {
            answer[i] = t[i] ^ k;
            if (answer[i] != startStr[i])
            {
                success = false;
                break;
            }
        }

        if (!success)
            continue;

        for (int i = STARTLEN; i < len; i++)
            answer[i] = t[i] ^ k;
        answer[len] = '\0';
        break;
    }

    cout << answer << '\n';

    return 0;
}