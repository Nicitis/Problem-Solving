#include <iostream>
#include <algorithm>
// #include <set>

using namespace std;

int arr[8];
int answerArray[8];
int N, M, curIdx = 0;

// candidates: 선택 가능한지 여부
void NextPermutation(bool candidates[8], int remained)
{
    if (remained == 0)
    {
        for (int i = 0; i < M; i++)
        {
            cout << answerArray[i] << ' ';
        }
        cout << '\n';
        return;
    }

    // set<int> checkSet;
    int prev = -1;

    for (int i = 0; i < N; i++)
    {
        // if (candidates[i] && checkSet.find(arr[i]) == checkSet.end())
        if (candidates[i] && prev != arr[i])
        { 
            prev = arr[i];
            // checkSet.insert(arr[i]);
            candidates[i] = false;

            answerArray[curIdx++] = arr[i];
            NextPermutation(candidates, remained - 1);
            curIdx--;

            candidates[i] = true;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    bool candidates[8];
    for (int i = 0; i < N; i++)
        candidates[i] = true;
    for (int i = N; i < 8; i++)
        candidates[i] = false;

    sort(arr, arr + N);

    NextPermutation(candidates, M);

    return 0;
}