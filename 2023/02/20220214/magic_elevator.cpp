// 2023.02.14., 마법의 엘리베이터, https://school.programmers.co.kr/learn/courses/30/lessons/148653
#include <string>
#include <vector>

#define MIN(X, Y) ((X)<(Y)?(X):(Y))

using namespace std;
// 아래 자리수부터 0으로 맞춰나간다. 
// 16의 경우 6을 0으로 만드는 대신 윗자리수를 1 더하는 것이 이득인지(이동횟수 10-6회), 
// 그냥 0으로 만드는 것이 이득인지(이동횟수 6회) 브루트포스로 계산한다.

// 주어진 숫자의 가장 아랫자리를 0으로 만들고 이동하는 횟수를 구한다.
int move(int floor)
{
    int r = floor % 10;
    if (floor < 10)
        return MIN(r, 10-r+1);
    return MIN(r + move(floor/10),             // -N층을 눌러 해당 자리를 0으로 만드는 이동횟수
               (10 - r) + move(floor/10 + 1)); // +N층을 눌러 해당 자리를 0으로 만드는 이동횟수
}

int solution(int storey) {
    return move(storey);
}