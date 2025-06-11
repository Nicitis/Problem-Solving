#include <iostream>
#include <cctype>

using namespace std;

int main()
{
    string line;
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    getline(cin, line);
    
    while (line[0] != '#')
    {
        int cnt = 0;
        for (int i = 0; i < line.size(); i++)
        {
            char c = tolower(line[i]);
            switch (c)
            {
                case 'a':
                case 'i':
                case 'e':
                case 'o':
                case 'u':
                    cnt++;
                    break;
            }
        }
        cout << cnt << "\n";
        getline(cin, line);
    }
    
    return 0;
}