#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) 
{
    vector<int> answer(id_list.size(), 0);
    vector<set<int>> reporter_ids_list(id_list.size()); // 유저별로 자신을 신고한 id를 저장한다
    
    for (string s : report)
    {
        // slice
        int space = s.find(' ');
        string reporter = s.substr(0, space);
        string reported = s.substr(space + 1, s.size() - space);

        int reporter_id, reported_id;

        // 유저 id를 id 번호로 바꾼다.
        for (int i = 0; i < id_list.size(); i++)
        {
            if (id_list[i] == reporter)
                reporter_id = i;
            else if (id_list[i] == reported)
                reported_id = i;
        }

        // 신고자의 id 번호를 신고받는 유저의 신고 리스트에 추가한다.
        reporter_ids_list[reported_id].insert(reporter_id);
    }

    for (int i = 0; i < id_list.size(); i++)
    {
        // 이용 정지될 만큼 신고를 많이 받으면
        if (reporter_ids_list[i].size() >= k)
        {
            // 해당 유저를 신고한 유저에게 메일을 보낸다.
            for (int id : reporter_ids_list[i])
            {
                answer[id]++;
            }
        }
    }
    
    return answer;
}