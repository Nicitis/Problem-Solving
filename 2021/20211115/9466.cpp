// 백준 9466: 텀 프로젝트(C++)
#include <cstdio>
#include <vector>
#include <cstring>

#define NO_STUDENT 0

using namespace std;


struct graph
{
    vector<int> adj; // 각각 하나씩만 가질 수 있음
    int independent_student;
};

bool visit[100001];

int get_last_student(struct graph& g, int student)
{
    int next = g.adj[student];
    int last = NO_STUDENT;
    visit[student] = true;

    // cycle을 이루는 첫 번째 학생을 찾는다.
    if (!visit[next])
        last = get_last_student(g, next);
    else
        last = next;
    
    // cycle을 이루는 학생이 나일 경우, cycle을 초기화해줌
    if (last == student)
    {
        last = NO_STUDENT;
        // 사이클에 속한 학생들의 수만큼 팀 미소속 학생 수를 감소시킨다.
        g.independent_student--;
        while (next != student)
        {
            next = g.adj[next];
            g.independent_student--;
        }
    }
    // else if (last == NO_STUDENT) // cycle이 없을 경우 팀이 없으므로
        // g.independent_student++; // 팀 미소속 학생의 수를 증가

    g.independent_student++;

    return last;
}

int main()
{
    int t, n, temp, s;
    scanf("%d", &t);

    vector<struct graph> graphs(t);

    for (int i = 0; i < t; i++)
    {
        // 그래프 생성
        graphs[i].adj.clear();
        graphs[i].independent_student = 0;
        scanf("%d", &n);
        // 첫 번째를 0으로 채워줌
        graphs[i].adj.push_back(0);
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &temp);
            graphs[i].adj.push_back(temp);
        }

        // 학생의 수를 구함
        for (s = 1; s <= n; s++)
            if (!visit[s])
                get_last_student(graphs[i], s);
        
        printf("%d\n", graphs[i].independent_student);

        // 초기화
        if (i + 1 < t)
            memset(visit, false, sizeof(visit));
    }

    return 0;
}