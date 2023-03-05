// 2023.03.05., [카카오 블라인드 채용 3차]방금그곡, https://school.programmers.co.kr/learn/courses/30/lessons/17683#
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

struct MusicInfo
{
    string m_start;
    string m_end;
    string m_title;
    string m_song;
    
    MusicInfo(string start, string end, string title, string song)
        : m_start(start)
        , m_end(end)
        , m_title(title)
        , m_song(song)
    {}
    
    int length() const
    {
        return time(m_end) - time(m_start);
    }
    
    // 음악 길이가 긴 순서로 정렬한다.
    const bool operator<(const MusicInfo &other) const
    {
        return length() > other.length();
    }
};

bool comparePattern(string m, string song, int totalPlayTime)
{
    int mLength = m.length() - std::count(m.begin(), m.end(), '#');
    int sharpCount = 0;
    for (int i = 0; i < song.length(); i++)
    {
        if (song[i] == '#')
            sharpCount++;

        if (m[0] != song[i])
            continue;
        
        int j;
        // 문자열 비교
        for (j = 0; j < m.length(); j++)
        {
            if (m[j] != song[(i+j)%song.length()])
                break;
        }
        
        // 만약 다음에 #이 있어서 음이 다른 경우, 패턴이 다르다고 판단한다.
        if (j == m.length() && song[(i+j)%song.length()] != '#')
        {
            // 곡의 길이를 초과해도 패턴이 다르다 판단한다.
            int currentPlayTime = (i - sharpCount) + mLength - 1;
            if (currentPlayTime > totalPlayTime)
                continue;
            return true;
        }
    }
    return false;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    vector<MusicInfo> infos;
    
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
        if (comparePattern(m, infos[i].m_song, infos[i].length()))
        {
            answer = infos[i].m_title;
            break;
        }
    }
    
    return answer;
}