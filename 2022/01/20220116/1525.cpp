// 백준 1525: 퍼즐
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

#define MAX_PERMUTATION 362880

struct PuzzleState
{
    vector<int> puzzle;
    int movement;
    int zeroX;
    int zeroY;
};

int fact[10];
bool check[MAX_PERMUTATION];
int xMove[4] = { -1, 1, 0, 0 };
int yMove[4] = { 0, 0, -1, 1 };

void CalcFactorial()
{
    int number = 1;
    fact[0] = 1;
    for (int i = 1; i < 10; i++)
    {
        number *= i;
        fact[i] = number;
    }
}

// 주어진 순열이 몇 번째 순열인지 구한다.
int PermutationNumber(vector<int> numbers)
{
    int n = 0;
    bool exist[9];
    for (int i = 0; i < 9; i++)
        exist[i] = true;
    
    for (int i = 0; i < 9; i++)
    {
        int order = 0;
        for (int j = 0; j < 9; j++)
        {
            if (numbers[i] == j)
                break;
            if (exist[j])
                order++;
        }

        n += order * fact[8 - i];
        exist[numbers[i]] = false;
    }
    return n;
}

void Swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void PrintState(vector<int> numbers)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            cout << numbers[i * 3 + j] << ' ';
        cout << '\n';
    }
}

int PuzzleMovement(vector<int> numbers)
{
    queue<struct PuzzleState> q;
    
    int zeroX = 0, zeroY = 0;

    for (int i = 0; i < 9; i++)
    {
        if (numbers[i] == 0)
        {
            zeroX = i % 3;
            zeroY = i / 3;
            break;
        }
    }

    vector<int> destState = vector<int>({ 1, 2, 3, 4, 5, 6, 7, 8, 0 });
    int destId = PermutationNumber(destState);

    q.push({numbers, 0, zeroX, zeroY});

    while (!q.empty())
    {
        struct PuzzleState state = q.front();
        q.pop();

        int id = PermutationNumber(state.puzzle);

        if (check[id])
            continue;
        
        check[id] = true;

        if (id == destId)
            return state.movement;

        for (int i = 0; i < 4; i++)
        {
            int nextX = state.zeroX + xMove[i];
            int nextY = state.zeroY + yMove[i];

            if (nextX < 0 || nextX >= 3 ||
                nextY < 0 || nextY >= 3)
                continue;

            struct PuzzleState nextState;
            
            nextState.puzzle = vector<int>(state.puzzle);
            nextState.movement = state.movement + 1;
            nextState.zeroX = nextX;
            nextState.zeroY = nextY;

            // 이동
            Swap(&nextState.puzzle[state.zeroX + state.zeroY * 3], &nextState.puzzle[nextX + nextY * 3]);

            q.push(nextState);
        }
    }

    return -1;
}

int main()
{
    vector<int> numbers(9, 0);
    for (int i = 0; i < 9; i++)
        cin >> numbers[i];

    CalcFactorial();

    cout << PuzzleMovement(numbers);

    return 0;
}