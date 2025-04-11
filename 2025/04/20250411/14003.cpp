#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
문제: lis의 길이는 알겠지만, 정확한 lis가 아니다.
따라서 답을 구한 후에 정답이 되는 lis를 구해줘야 한다.
이때 입력 N <= 100만이므로, O(NlogN) 이하의 알고리즘이 필요하다.

처음에 들어온 입력 a[n]을 저장해놓고, 다시 입력을 순회하여 정답을 탐색해야 한다
방법 1. lis의 인덱스를 저장해놓고, 그 순서대로 순회하자. 
단, 몇 개는 재갱신되었을 수도 있으므로 실제로 믿을 수 있는 건 마지막 인덱스뿐이다.
그렇다면, 마지막에서부터 역으로 순회하면서 lis[i]번째보다 크거나 같은 원소가 나오면
최종 lis[i]로 기록한다.
이를 통해 nlogn + n = ~nlogn의 시간에 문제를 해결할 수 있다.

*실제로 가능한가?
각 요소를 갱신할 때 '새 입력보다 같거나 큰 원소가 있다면 대체한다'고 구성했다.
따라서, 갱신되기 전 lis[i]는 현재 lis[i]보다 더 큰 값이었을 것이다.
예제 입력: 10 20 10 30 20 50 25 30 22 40 50 
임시 lis: 10 20 22 30 40 50
정답 lis: 10 20 25 30 40 50
50(V) -> 기본 값, lis[5](lis[5]=50)
40(V) -> lis[4]보다 크거나 같으므로 합격(lis[4]=40)
22 -> lis[3] 30보다 작으므로 기각
30(V) -> lis[3] 30보다 크거나 같으므로 합격(lis[3]=30)
25(V) -> lis[2] 22보다 크거나 같으므로 합격(lis[2] = 25)
50 -> lis[1] 20보다 크다. 하지만 다음 값이 되어야 하는 25보다 값이 크다. 따라서 기각.
(lis[i+1] > a[k] >= lis[i]여야 한다.)
20 -> lis[1] 20보다 크거나 같으므로 합격(lis[1] = 20)
10 -> lis[0] 10보다 크거나 같으므로 합격(lis[0] = 10)

즉, 각 요소마다 lis[i] <= a[k] < lis[i+1]을 만족해야 한다.
이 입력을 만족하면 정의에 따라 대체된 원소의 원본임을 예상할 수 있다.


잠깐만.

마지막 인덱스를 갱신하는 거.. 생각해보면 꼭 하나 길이가 늘어날 때가 아니라
마지막 값을 갱신할 때에도 있을 수 있지 않나?
그렇다면 다음과 같은 경우에 오류가 생길 수 있다.

7
4 5 6 1 2 3 -1

출력:
-1 2 3
정답:
1 2 3

*역추적할 때 문제?
아마도 역추적시에 정확하게 추적되지 않는 게 문제가 되는 것 같다.
아마도.. 순서가 이상하게 꼬일 수도 있지 않을까?
예를 들어 원래 값은 30이어야 하는데, 22로 갱신되는 바람에 23을 발견했을 때 
그 값이 그 자리에 있어야 할 값이라고 추론하게 되고, 그로 인해 앞에 22보다 큰 값이
와 있어야 하는데 그걸 발견 못하는 경우가 있지 않을까?

입력: 10 25 30 40 23 40 50 20 22
                        ^ last
정답: 10 25 30 40 50
출력: 10 20 23 40 50

이걸 어떻게 해결하지?

문제는 "같은 값이 나와서 순서가 헷깔릴 때"이다.
위에서도 40이 한 번 더 나오지 않았다면 이런 식으로 순서가 꼬일 일이 없었을 것이다.

그렇다면... 같은 값이 나오면 애초에 a[i]에 안 넣었다면 헷깔릴 일이 없었지 않을까?
아예 제외해보자.


*/

int a[1000000];
int main()
{
    int n, last_idx = -1;
    vector<int> lis;

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    // make the longest increase sequence(lis)
    for (int i = 0, idx = 0; i < n; ++i, ++idx)
    {
        cin >> a[idx];
        auto lower = lower_bound(lis.begin(), lis.end(), a[idx]);
        if (lower != lis.end())
        {
            // 같은 값 발견시 a[i]에도 기록하지 않음.
            if (*lower == a[idx])
            {
                --idx;
                continue;
            }
            if (lower + 1 == lis.end()) // 마지막 요소를 수정할 땐 범위를 수정
                last_idx = idx;
            *lower = a[idx];
        }
        else
        {
            last_idx = idx;
            lis.push_back(a[idx]);
        }
    }

    // find original lis
    int seq_idx = lis.size() - 2;
    for (int i = last_idx - 1; i >= 0; --i)
    {
        if (seq_idx < 0)
            break;
        // cout << "check (i: "<< i<<", seq_idx: " << seq_idx <<") " << a[i] << ", "
            // << "lis[seq_idx]: " << lis[seq_idx] << ", lis[seq_idx+1]: " << lis[seq_idx + 1] << "\n";
        if (lis[seq_idx] <= a[i] && a[i] < lis[seq_idx + 1])
        {
            // cout << "lis[" << seq_idx <<"]=" << lis[seq_idx] << "->" << a[i] <<"\n";
            lis[seq_idx] = a[i];
            --seq_idx;
        }
    }

    cout << lis.size() << "\n";
    for (int i : lis)
    {
        cout << i << " ";
    }
    cout << "\n";

    return 0;
}