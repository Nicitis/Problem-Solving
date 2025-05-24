/*
�� �࿡ ��ġ�� ����� 0�̶�� ����
�� ���� ���� ������ ��� �ϳ��� ��ġ�ؾ� �Ѵ�
�� ���̴�. �� ���� �����ϸ�,
��� �ִ� ���� �ִٸ� �װ� � ���̵� �ϳ��� ����
ä�� �� �ִ�.
��, �ϳ��� ���� ä��� ����ִ� �� �ϳ��� ������
ä�� �� �ְ�, �ݴ�� �� �� �ϳ��� ä��� �� ��
�ϳ��� ������ ä�� �� �ִ�.
����, ��� �ִ� ���� ���� ��� �ִ� ���� �� ��
�� ū ���� ������ �ּڰ��̶�� �� �� �ִ�.
*/
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n, m;
    string line;

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    int rowCount[50] = { 0 }, colCount[50] = { 0 };

    for (int i = 0; i < n; i++)
    {
        cin >> line;
        for (int j = 0; j < m; j++)
        {
            if (line[j] == 'X')
            {
                rowCount[i]++;
                colCount[j]++;
            }
        }
    }

    int emptyRows = 0, emptyCols = 0;

    for (int i = 0; i < n; i++)
        if (rowCount[i] == 0)
            emptyRows++;
    for (int i = 0; i < m; i++)
        if (colCount[i] == 0)
            emptyCols++;

    cout << max(emptyRows, emptyCols);

    return 0;
}