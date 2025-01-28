#include <iostream>
#include <string>

using namespace std;

int arr[8], N, M;

void NextSequence(int prev, int remained)
{
    if (remained == 0)
    {
        string answer = "";
        answer.push_back('0' + arr[0]);
        for (int i = 1; i < M; i++)
        {
            answer.push_back(' ');
            answer.push_back('0' + arr[i]);
        }
        cout << answer << '\n';
        return;
    }

    int idx = M - remained;
    for (int i = prev; i <= N; i++)
    {
        arr[idx] = i;
        NextSequence(i, remained - 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);

    cin >> N >> M;

    NextSequence(1, M);    

    return 0;
}