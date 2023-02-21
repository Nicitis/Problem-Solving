// 2023.02.08., 뒤에 있는 큰 수 찾기, https://school.programmers.co.kr/learn/courses/30/lessons/154539
// 1번째 시도: O(N^2) 알고리즘이라 떨어진듯.
// #include <string>
// #include <vector>
// #include <list>
// #include <iostream>

// using namespace std;

// vector<int> solution(vector<int> numbers) {
//     vector<int> answer(numbers.size(), -1);
//     list<int> waitList;
    
//     for (int i = 0; i < numbers.size(); i++)
//     {
//         for (auto it = waitList.begin(); it != waitList.end();)
//         {
//             if (numbers[*it] < numbers[i])
//             {
//                 answer[*it] = numbers[i];
//                 it = waitList.erase(it);
//             }
//             else
//                 it++;
//         }
//         waitList.push_back(i);
//     }
//     return answer;
// }