#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;

    while (true)
    {
        cin >> N >> M;

        if (N == 0 && M == 0)
            break;

        int source, destination;
        int callStart[10000];
        int callDuration[10000];

        for (int i = 0; i < N; i++)
        {
            cin >> source >> destination >> callStart[i] >> callDuration[i] ;
        }

        for (int i = 0; i < M; i++)
        {
            int startSection, durationSection, call = 0;

            cin >> startSection >> durationSection;

            int endSection = startSection + durationSection;

            for (int i = 0; i < N; i++)
            {
                int startCall = callStart[i];
                int endCall = callStart[i] + callDuration[i];
                if (startSection < endCall && startCall < endSection)
                    call++;
            }
            cout << call << '\n';
        }
    }

    return 0;
}