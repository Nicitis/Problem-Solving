// 2023.03.09.(수정), [카카오 블라인드 채용 3차]방금그곡, https://school.programmers.co.kr/learn/courses/30/lessons/17683
// 기존 버전과 달리, 먼저 샵이 포함된 음표를 소문자로 치환한 후 시작한다.
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int time(string str)
{
    int hour = stoi(str);
    string minuteStr = str.substr(3);
    int minute = stoi(minuteStr);
    
    return hour * 60 + minute;
}

string convertNotes(string original)
{
    string notes = "";
    for (int i = 0; i < original.length(); i++)
    {
        if (original[i] != '#')
            notes.push_back(original[i]);
        else
            notes.back() = notes.back() - ('A' - 'a');
    }
    return notes;
}

struct MusicInfo
{
    string start;
    string end;
    string title;
    string notes;
    
    MusicInfo(string start, string end, string title, string notes)
        : start(start)
        , end(end)
        , title(title)
        , notes(convertNotes(notes))
    {}
    
    // 재생된 노트의 수
    int length() const
    {
        return time(end) - time(start) + 1;
    }
    
    // 음악 길이가 긴 순서로 정렬한다.
    const bool operator<(const MusicInfo &other) const
    {
        return length() > other.length();
    }
};

bool comparePattern(string m, string notes, int totalPlayTime)
{
    for (int i = 0; i < notes.length(); i++)
    {
        if (m[0] != notes[i])
            continue;
        
        // 곡의 길이를 초과하면 실패했다고 간주한다.
        if (i + m.length() > totalPlayTime)
            break;
        
        int j;
        // 문자열 비교
        for (j = 0; j < m.length(); j++)
            if (m[j] != notes[(i+j)%notes.length()])
                break;
        
        if (j == m.length())
            return true;
    }
    return false;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    vector<MusicInfo> infos;
    
    // m을 변환한다.
    m = convertNotes(m);
    
    for (int i = 0; i < musicinfos.size(); i++)
    {
        istringstream iss(musicinfos[i]);
        string buffer[4];
        
        for (int j = 0; j < 4; j++)
        {
            getline(iss, buffer[j], ',');
        }
        infos.push_back(
            MusicInfo(buffer[0],buffer[1],buffer[2],buffer[3]));
    }
    
    stable_sort(infos.begin(), infos.end()); // 시간순으로 정렬
    
    for (int i = 0; i < infos.size(); i++)
    {
        if (comparePattern(m, infos[i].notes, infos[i].length()))
        {
            answer = infos[i].title;
            break;
        }
    }
    
    return answer;
}