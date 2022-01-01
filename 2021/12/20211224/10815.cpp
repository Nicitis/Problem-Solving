// 백준 10815 숫자카드(CPP)
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> cards;

// 이분탐색으로 카드가 존재하는지 찾는다.
bool HasCard(int card)
{
    int low = 0, high = cards.size() - 1, mid;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (cards[mid] < card) // 찾고자 하는 카드가 더 낮음
            low = mid + 1;
        else if (cards[mid] > card) // 찾고자 하는 카드가 더 높음
            high = mid - 1;
        else // 카드 발견
            return true; 
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n, m;
    vector<int> cases;
    
    // 입력
    cin >> n;

    cards = vector<int>(n);

    for (int i = 0; i < n; i++)
    {
        cin >> cards[i];
    }

    cin >> m;

    cases = vector<int>(m);

    for (int i = 0; i < m; i++)
    {
        cin >> cases[i];
    }

    sort(cards.begin(), cards.end());

    // 출력
    for (int i = 0; i < m; i++)
    {
        if (HasCard(cases[i]))
            cout << '1';
        else
            cout << '0';
        
        if (i + 1 < m)
            cout << ' ';
    }
}