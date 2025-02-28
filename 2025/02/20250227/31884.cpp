#include <iostream>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    map<int, int> heightMap;
    int q, type, x;
    map<int, int>::iterator it;
    int maximumY;

    cin >> q;

    for (int i = 0; i < q; i++)
    {
        cin >> type >> x;
        maximumY = 0;

        switch (type)
        {
            case 1:
                // find maximum y
                for (int j = x; j < x + 4; j++)
                {
                    it = heightMap.find(j);
                    if (it != heightMap.end() && it->second > maximumY)
                        maximumY = it->second;
                }
                // update
                for (int j = x; j < x + 4; j++)
                {
                    heightMap[j] = maximumY + 1;
                }
                break;
            case 2:
                it = heightMap.find(x);
                if (it != heightMap.end() && it->second > maximumY)
                    maximumY = it->second;
                heightMap[x] = maximumY + 4;
                break;
            case 3:
                it = heightMap.find(x);
                if (it != heightMap.end() && it->second > maximumY)
                    maximumY = it->second;
                cout << maximumY << '\n';
                break;
        }
    }

    return 0;
}