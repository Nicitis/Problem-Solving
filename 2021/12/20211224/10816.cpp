// 백준 10816 숫자카드 2(CPP)
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> cards;

int HowManyCards(int card)
{
    int low = 0, high = cards.size() - 1, mid;
    bool isFound = false;

    while (low <= high)
    {
        mid = (low + high) >> 1;
        if (cards[mid] < card) // 찾고자 하는 카드가 더 높음(더 높은 카드 필요)
            low = mid + 1;
        else if (cards[mid] > card) // 찾고자 하는 카드가 더 낮음(더 낮은 카드 필요)
            high = mid - 1;
        else // 카드 발견
        {
            isFound = true;
            break;
        }
    }

    // 발견 못 했을 경우
    if (isFound == false)
        return 0;
    
    int start, end, left, right;
    
    // 같은 카드가 여러 장일 때, 같은 카드들이 어디서부터 어디까지 존재하는지 이분탐색을 통해 구한다.
    left = low;
    right = mid;
    while (left <= right)
    {
        start = (left + right) >> 1;
        if (cards[start] < card) // 찾고자 하는 카드가 더 높음
            left = start + 1;
        else if (start >= 1 && cards[start - 1] == card) // 이전 카드와 지금 카드가 동일하므로 재탐색이 필요
            right = start - 1;
        else // 카드를 발견했고 이전 카드가 없거나 카드가 자신보다 낮을 때
        {
            break;
        }
    }

    left = mid;
    right = high;
    while (left <= right)
    {
        end = (left + right) >> 1;
        if (cards[end] > card) // 찾고자 하는 카드가 더 낮음(낮은 카드 탐색 필요)
            right = end - 1;
        else if (end < cards.size() - 1 && cards[end + 1] == card) // 다음 카드와 지금 카드가 동일하므로 재탐색이 필요
            left = end + 1;
        else // 카드를 발견했고 다음 카드가 없거나 카드가 자신보다 높을 때
        {
            break;
        }
    }

    // 같은 카드의 수를 센다.
    return end - start + 1;
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
        cout << HowManyCards(cases[i]);
        
        if (i + 1 < m)
            cout << ' ';
    }
}