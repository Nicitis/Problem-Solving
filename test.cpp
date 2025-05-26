#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

struct new_data
{
public:
    int n;

    explicit new_data(int newN) : n(newN) {}
    
    bool operator<(const new_data& rhs) const
    {
        return n < rhs.n;
    }

    bool operator>(const new_data& rhs) const
    {
        return n > rhs.n;
    }
};

int main ()
{
    vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(1);
    v.push_back(5);

    cout << "v original: ";
    for (int i : v)
    {
        cout << i << " ";
    }
    cout << "\n";

    // cout << "v remove: ";
    // for (auto it = std::remove(v.begin(), v.end(), 1); it < v.end(); it++)
    // {
    //     cout << *it << " ";
    // }
    // cout << "\n";

    // cout << "after remove: ";
    // for (int i : v)
    // {
    //     cout << i << " ";
    // }
    // cout << "\n";
    
    // v.erase(std::remove(v.begin(), v.end(), 1), v.end());

    // cout << "after erase: ";
    // for (int i : v)
    // {
    //     cout << i << " ";
    // }
    // cout << "\n";

    sort(v.begin(), v.end());

    cout << "v sort: ";
    for (int i : v)
    {
        cout << i << " ";
    }
    cout << "\n";

    sort(v.begin(), v.end(), greater<int>());

    cout << "v descendent: ";
    for (int i : v)
    {
        cout << i << " ";
    }
    cout << "\n";

    sort(v.begin(), v.end(), less<int>());
    cout << "v descendent: ";
    for (int i : v)
    {
        cout << i << " ";
    }
    cout << "\n";

    vector<new_data> newV;
    for (int i : v)
    {
        newV.push_back(new_data(i));
    }
    
    cout << "v original: ";
    for (auto i : newV)
    {
        cout << i.n << " ";
    }
    cout << "\n";

    cout << "newV sort: ";
    for (auto i : newV)
    {
        cout << i.n << " ";
    }
    cout << "\n";

    sort(newV.begin(), newV.end(), greater<new_data>());

    cout << "newV descendent: ";
    for (auto i : newV)
    {
        cout << i.n << " ";
    }
    cout << "\n";

    sort(newV.begin(), newV.end(), less<new_data>());
    cout << "newV descendent: ";
    for (auto i : newV)
    {
        cout << i.n << " ";
    }
    cout << "\n";


    // cout << "string conversion\n";
    // char ch = 'A';
    // string temp = "";
    // temp += ch;

    // cout << "temp : " << temp << "\n";
    
    // // string -> char -> 그냥 인덱싱

    // // int -> string
    // int num = 5123;
    // string str = to_string(num);
    // cout << "to_string(5123) = " << str << "\n";

    // // string -> int or double
    // string n_str = "1123d";
    // int n1 = stoi(n_str);
    // double n2 = stod(n_str);

    // cout << n_str << " -> n1, n2 = " << n1 << ", " << n2 << "\n";

    // // char -> int
    // char ch2 = '9';
    // int n = ch2 - '0';
    // cout << "n = " << n << "\n";

    bitset<16> bs(128);

    cout << "8th bit is 1? " << bs.test(8) << ", 7th bit is 1? " << bs.test(7) << "\n";

    cout << 128 << "-> bitset<16> bs = " << bs.to_string() << "\n";

    bs.flip(2);
    cout << "flip bs(2) -> " << bs.to_string() << "(" << bs.to_ulong() << ")\n";

    

    return 0;
}