// 백준 2251: 물통
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<vector<vector<bool>>> visit;
set<int> states;

void FindAllBottleStates(int a, int b, int c, int maxA, int maxB, int maxC)
{
    int bottles[3], maxBottles[3] = { maxA, maxB, maxC };
    visit[a][b][c] = true;

    if (a == 0)
    {
        states.insert(c);
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            bottles[0] = a;
            bottles[1] = b;
            bottles[2] = c;

            if (bottles[i] == 0 || i == j) 
                continue;
                
            // i -> j
            bottles[j] = bottles[j] + bottles[i];
            bottles[i] = 0;
            if (bottles[j] > maxBottles[j])
            {
                bottles[i] = bottles[j] - maxBottles[j];
                bottles[j] = maxBottles[j];
            }

            if (visit[bottles[0]][bottles[1]][bottles[2]] == false)
            {
                FindAllBottleStates(bottles[0], bottles[1], bottles[2], maxA, maxB, maxC);
            }
        }
    }
}

int main()
{
    int a, b, c;

    cin >> a >> b >> c;

    visit = vector<vector<vector<bool>>>(a + 1, 
        vector<vector<bool>>(b + 1, 
            vector<bool>(c + 1, false)));
    
    FindAllBottleStates(0, 0, c, a, b, c);

    for (auto iter = states.begin(); iter != states.end(); iter++)
    {
        cout << *iter << ' ';
    }
}