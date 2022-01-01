// 백준 1992: 쿼드트리(C++)
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 쿼드트리를 만들어 string으로 반환한다.
void MakeQuadTree(int row, int col, int size, const vector<string>& image, string& result)
{
    bool isEqual = true;
    if (size > 1)
    {
        for (int currRow = row; currRow < row + size; currRow++)
        {
            for (int currCol = col; currCol < col + size; currCol++)
            {
                if (image[currRow][currCol] != image[row][col])
                {
                    isEqual = false;
                    break;
                }
            }
            if (!isEqual)
                break;
        }
    }

    if (isEqual)
    {
        result.push_back(image[row][col]);
    }
    else
    {
        int nextSize = size/2;
        result.push_back('(');
        MakeQuadTree(row, col, nextSize, image, result);
        MakeQuadTree(row, col + nextSize, nextSize, image, result);
        MakeQuadTree(row + nextSize, col, nextSize, image, result);
        MakeQuadTree(row + nextSize, col + nextSize, nextSize, image, result);
        result.push_back(')');
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    vector<string> image(n);
    string result;

    for (int i = 0; i < n; i++)
        cin >> image[i];

    MakeQuadTree(0, 0, n, image, result);
    // PrintQuadTree(0, 0, n, image);

    cout << result;
    
    return 0;
}

// 쿼드트리를 출력한다.
// void PrintQuadTree(int row, int col, int size, const vector<string>& image)
// {
//     bool isEqual = true;
//     if (size > 1)
//     {
//         for (int currRow = row; currRow < row + size; currRow++)
//         {
//             for (int currCol = col; currCol < col + size; currCol++)
//             {
//                 if (image[currRow][currCol] != image[row][col])
//                 {
//                     isEqual = false;
//                     break;
//                 }
//             }
//             if (!isEqual)
//                 break;
//         }
//     }

//     if (isEqual)
//     {
//         cout << image[row][col];
//     }
//     else
//     {
//         int nextSize = size/2;
//         cout << "(";
//         PrintQuadTree(row, col, nextSize, image);
//         PrintQuadTree(row, col + nextSize, nextSize, image);
//         PrintQuadTree(row + nextSize, col, nextSize, image);
//         PrintQuadTree(row + nextSize, col + nextSize, nextSize, image);
//         cout << ")";
//     }
// }