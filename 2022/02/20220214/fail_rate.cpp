#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class StageInfo
{
public:
    int index;
    int failure;
    int challenger;
    double failRate;
    StageInfo(int idx) 
        : index(idx), failure(0), challenger(0), failRate(0.0) {}
};

bool comparer(StageInfo a, StageInfo b)
{
    if (a.failRate == b.failRate)
        return a.index < b.index;
    return a.failRate > b.failRate;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    
    vector<StageInfo> infos;
    for (int s = 0; s < N; s++)
        infos.push_back(StageInfo(s + 1));

    // 실패자의 수를 센다.
    for (int stage : stages)
    {
        if (stage == N + 1)
            continue;
        infos[stage - 1].failure++;
    }
    
    // 스테이지 도전자 = (이전 스테이지 도전자) - (이전 스테이지의 실패자)
    infos[0].challenger = stages.size(); // 모두 1스테이지를 도전했음
    infos[0].failRate = (double)infos[0].failure / infos[0].challenger;
    for (int s = 1; s < N; s++)
    {
        infos[s].challenger = infos[s - 1].challenger - infos[s - 1].failure;
        infos[s].failRate = (double)infos[s].failure / infos[s].challenger;
    }
    
    stable_sort(infos.begin(), infos.end(), comparer);
    
    for (int i = 0; i < N; i++)
        answer.push_back(infos[i].index);
    
    return answer;
}