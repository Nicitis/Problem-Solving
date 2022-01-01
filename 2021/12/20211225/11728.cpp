// 백준 11728 배열 합치기(C++)
#include <iostream>
#include <vector>

using namespace std;

// 두 벡터를 하나로 합치는 함수
void Merge(vector<int> v1, vector<int> v2, vector<int>& resultVector)
{
    int indexA = 0, indexB = 0, cnt = 0;

    while (true)
    {
        if (v1[indexA] <= v2[indexB])
        {
            resultVector[cnt++] = v1[indexA++];
        }
        else
        {
            resultVector[cnt++] = v2[indexB++];
        }

        if (indexA == v1.size())
        {
            while (indexB < v2.size())
            {
                resultVector[cnt++] = v2[indexB++];
            }
            break;
        }

        if (indexB == v2.size())
        {
            while (indexA < v1.size())
            {
                resultVector[cnt++] = v1[indexA++];
            }
            break;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    int n, m;

    cin >> n >> m;

    vector<int> v1(n);
    vector<int> v2(m);
    vector<int> resultVector(n + m);

    for (int i = 0; i < n; i++)
        cin >> v1[i];
    
    for (int i = 0; i < m; i++)
        cin >> v2[i];
    
    Merge(v1, v2, resultVector);

    for (int i = 0; i < n + m; i++)
    {
        cout << resultVector[i] << ' ';
    }
    return 0;
}