# 1005번-ACM Craft

## 문제

- 백준, 골드3, https://www.acmicpc.net/problem/1005
- 풀이 날짜: 2025.1.16
- 풀이 시간: 13:02~13:28(26분 소요)
- 알고리즘 분류: 위상정렬
- 사용 언어: C++

## 문제 해설

해당 문제는 위상정렬처럼 보이지만 약간 변형된 문제이다.

건물을 노드라고 생각하면, 각 노드에서는 선행 노드가 존재한다. 이때 각 건물을 지으려면 선행 노드를 모두 끝마쳐야 한다.

그러면 각 건물을 짓는 데에 필요한 실질적인 시간은 (자신의 건물을 건설하는 시간) + (선행 노드 중 가장 오래 걸리는 시간)이 된다.

가장 간단하게 수행하는 방법은 in_degree가 0인 노드부터 시작해서 위상정렬로 각 노드의 비용을 갱신하는 방법이 있다.

나는 접근 방법을 조금 더 바꾸어서, 만약 도착 노드가 4번 노드라면 4번 노드에서 역으로 선행 노드의 최대 비용을 구하도록 하였다. 입력에서는 필요 없는 노드도 존재하므로, 이렇게 하면 모든 노드를 순회할 필요 없이 도착 노드와 연관된 노드만 순회하면 된다.

해당 알고리즘을 정리하면 이렇게 된다.

1. 역그래프 구하기
2. 도착 노드 W부터 시작해서, DFS로 선행 노드 중 가장 높은 비용을 계산하기
   - 1번, 2번 건물을 짓고 나서 3번 건물을 지을 수 있고 1번 건물이 10초, 2번 건물이 2초 걸린다면 3번 건물은 [10초 + (3번 건물 건설 시간)] 만큼의 시간이 걸린다.
   - 즉, 선행 노드 중 가장 높은 비용을 계산해야 한다.
3. 이를 해당 노드에 더하기

구현하면 이렇게 된다.

```cpp
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

bool visit[1001];

int minTerms(vector<int>& terms, vector<vector<int>>& adj, int v, int N)
{
    int maxTerm = 0, totalTerm;
    visit[v] = true;
    for (int w : adj[v])
    {
        // 최대 경로 비용 찾기
        if (visit[w])
            totalTerm = terms[w];
        else
            totalTerm = minTerms(terms, adj, w, N);

        if (maxTerm < totalTerm)
            maxTerm = totalTerm;
    }
    maxTerm += terms[v];
    terms[v] = maxTerm;
    return maxTerm;
}

int main()
{
    int T, N, K, S;

    scanf("%d", &T);

    for (int i = 0; i < T; i++)
    {
        scanf("%d %d", &N, &K);

        vector<int> buildingTerms(N + 1, 0);
        vector<vector<int>> adj(N + 1, vector<int>());

        for (int j = 1; j <= N; j++)
            scanf("%d", &buildingTerms[j]);
        for (int j = 0; j < K; j++)
        {
            // 역그래프 계산
            int v1, v2;
            scanf("%d %d", &v1, &v2);
            adj[v2].push_back(v1);
        }
        scanf("%d", &S);

        memset(visit, 0, sizeof(bool) * (N + 1));
        printf("%d\n", minTerms(buildingTerms, adj, S, N));
    }

    return 0;
}
```

### 다른 풀이법?

실제 다른 사람들의 풀이를 보니, queue를 통한 풀이 방법을 많이 사용했다.

(참고: [https://www.acmicpc.net/source/80040602](https://www.acmicpc.net/source/80040602), [https://velog.io/@seungboshim/C-백준-1005-ACM-Craft](https://velog.io/@seungboshim/C-%EB%B0%B1%EC%A4%80-1005-ACM-Craft))

각 건물 v의 건설 비용을 cost[v], 전체 비용을 total[v]이라 할 때,

1. 먼저 in_degree(진입차수)가 0인 노드를 queue에 삽입한다.
2. queue에서 정점 v를 꺼낸다.
3. v와 연결된 모든 인접 노드 w에 대하여, v까지 도달하는 비용과 w의 건설 비용을 합한 비용이 현재 w까지 도달하는 비용보다 크다면(total[v] + cost[w] > total[w]), total[w]를 갱신한다.
4. 조사할 때마다 해당 정점의 in degree를 감소시키며, 해당 정점의 in degree가 0이 되면 queue에 push한다.
5. queue가 빌 때까지 반복한다.

이때 4번이 중요한데, 한 정점을 모두 조사한 후에 queue에 넣도록 하여 같은 정점을 여러 번 검사하는 일을 막고, queue에 같은 정점이 여러 개 들어가 메모리 초과가 나는 문제를 막아준다.

꽤 영리한 풀이 방법으로 기억해 놓으면 좋을 듯하다.

```cpp
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, N, K, X, Y, W;
    vector<int> graph[1001];
    int cost[1001], total[1001], in_degree[1001];

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> N >> K;

        fill(in_degree, in_degree + N + 1, 0);

        for (int j = 1; j <= N; j++)
        {
            cin >> cost[j];
            total[j] = cost[j];
            graph[j].clear();
        }
        for (int j = 0; j < K; j++)
        {
            cin >> X >> Y;
            graph[X].push_back(Y);
            in_degree[Y]++;
        }
        cin >> W;

        queue<int> q;
        for (int j = 1; j <= N; j++)
        {
            if (in_degree[j] == 0)
                q.push(j);
        }

        int cur;
        while (!q.empty())
        {
            cur = q.front();
            for (int adj : graph[cur])
            {
                in_degree[adj]--;
                if (in_degree[adj] == 0)
                    q.push(adj);
                total[adj] = max(total[adj], total[cur] + cost[adj]);
            }
            q.pop();
        }
        cout << total[W] << '\n';
    }

    return 0;
}
```

### 팁

memset 대신 fill을 사용할 수도 있다.

C++에서 지원하는 함수로, 1바이트, 4바이트, 8바이트가 아닌 다양한 타입에 대해 0이나 1이 아닌 다른 값들의 대입을 수월하게 해준다.

memset은 4바이트 단위로 값을 할당하기 때문에 0이나 1 이외의 값은 할당하기 어려운데, fill은 그런 제약이 없어서 자유롭게 쓰기 좋다.

다만 memset에 비해 속도가 느리니, 속도가 중요한 코드에서는 memset을 활용하는 것도 방법이다. 그 외에는 fill을 사용하여 편하게 작성하자.
