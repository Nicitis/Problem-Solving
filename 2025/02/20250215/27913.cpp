#include <iostream>
#include <string>

#define MAX_N 200001

using namespace std;

bool isUpperCaseList[MAX_N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string defaultString = "SciComLove";
    int n, q, x, answer = 0;

    cin >> n >> q;

    for (int i = 1; i <= n; i++)
    {
        char c = defaultString[(i - 1) % defaultString.length()];
        bool isUpper = c >= 'A' && c <= 'Z';
        isUpperCaseList[i] = isUpper;
        answer += isUpper;
    }
    
    for (int i = 0; i < q; i++)
    {
        cin >> x;
        answer += isUpperCaseList[x] ? -1 : 1;
        isUpperCaseList[x] = !isUpperCaseList[x];
        cout << answer << '\n';
    }

    return 0;
}