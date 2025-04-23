#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
4.23.
역추적을 할 때 어림짐작으로 원래 값보다 작거나 같은 값이 나온다는 가정 하에 진행해버려서
잘못된 결과가 나오는 것 같다.
무조건 정상적인 결과만 얻을 수 있도록, 각 수열의 인덱스마다 {증가하는 부분 수열의 이전 idx}를 
기록해놓자. 그러면 마지막 요소만 역추적하면 정상적인 결과를 얻을 수 있다.
*/

int a[1000000];
int link[1000000];

int main()
{
    int n, idx;
    vector<int> lis; // element
    vector<int> lisIdx; // idx in a

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    // make the longest increase sequence(lis)
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        auto lower = lower_bound(lis.begin(), lis.end(), a[i]);
        idx = lower - lis.begin();
        if (lower != lis.end())
        {
            *lower = a[i];
            lisIdx[idx] = i;
            // cout << "replace: a["<<i<<"] = " << a[i] << ", idx = " << idx << "\n";
        }
        else
        {
            lis.push_back(a[i]);
            lisIdx.push_back(i);
            // cout << "push: a[i] = " << a[i] << ", idx = " << idx << "\n";
        }
        // 최초 요소일 경우 
        if (idx == 0)
        {
            link[i] = -1;
        }
        // 아닐 경우 이전 노드 연결
        else 
        {
            link[i] = lisIdx[idx - 1];
        }
    }

    // 최장 길이 lis 찾기
    int cur = lisIdx[lis.size() - 1];
    for (int i = lis.size() - 1; i >= 0; i--)
    {
        lis[i] = a[cur];
        cur = link[cur];
    }

    cout << lis.size() << "\n";
    for (int i : lis)
    {
        cout << i << " ";
    }

    cout << "\n";

    return 0;
}