#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int n;
    int votes[50], answer = 0;
    int *maxElem;
    
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        cin >> votes[i];
    }
    if (n <= 1)
    {
        cout << "0\n";
        return 0;
    }
    // 최다득표자의 득표 수가 1번의 득표 수보다 크거나 같을 때 매수 시도
    while (*(maxElem = max_element(votes + 1, votes + n)) >= votes[0])
    {
        answer++;
        (*maxElem)--;
        votes[0]++;
    }
    cout << answer << '\n';

    return 0;
}