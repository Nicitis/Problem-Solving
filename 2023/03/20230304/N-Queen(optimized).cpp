#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

// 0~(n-1) 행 및 열로 구성된 체스판 위에서 row 행에서 조건에 맞는 곳에 퀸을 배치한다.
// pos의 인덱스는 행이 되고, pos[r]은 해당 행에 배치된 퀸의 열을 가리킨다.
int GetNQueen(vector<int>& pos, int row, int n)
{
    if (row == n)
        return 1;
    
    int result = 0;
    vector<bool> available(n, true); // 해당 행 row에서 배치 가능한 열을 표시한다.
    
    // 배치 불가능한 위치를 배제한다.
    for (int r = 0; r < pos.size(); r++)
    {
        available[pos[r]] = false;
        int deltaY = row - r;
        if (pos[r] - deltaY >= 0) // 이미 배치된 퀸의 왼쪽 아래 대각선에 있는 자리를 제외
            available[pos[r] - deltaY] = false;
        if (pos[r] + deltaY < n) // 이미 배치된 퀸의 오른쪽 아래 대각선에 있는 자리를 제외
            available[pos[r] + deltaY] = false;
    }
    
    for (int col = 0; col < n; col++)
        if (available[col])
        {
            pos.push_back(col);
            result += GetNQueen(pos, row + 1, n);
            pos.pop_back();
        }
    
    return result;
}

int solution(int n) {
    vector<int> pos;
    return GetNQueen(pos, 0, n);
}

int main()
{
    int n;
    cout << "input N: ";
    cin >> n;
    cout << solution(n) << endl;

    return 0;
}