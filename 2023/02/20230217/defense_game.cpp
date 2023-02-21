// 2022.02.17., 디펜스 게임, https://school.programmers.co.kr/learn/courses/30/lessons/142085
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    priority_queue<int> enemy_pq;
    int round;
    
    for (round = 0; round < enemy.size(); round++)
    {
        n -= enemy[round];
        enemy_pq.push(enemy[round]);
        
        // 더이상 라운드를 진행할 수 없을 때 우선순위 큐로 가장 적의 수가 많은 라운드를 제거한다.
        while (n < 0 && k > 0)
        {
            n += enemy_pq.top();
            enemy_pq.pop();
            k--;
        }
        if (n < 0 && k == 0)
            break;
    }
    
    return round;
}