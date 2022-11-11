#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> clockHands) 
{
    int** copy = new int* [clockHands.size() + 2];
    for (int i = 0; i < clockHands.size() + 2; i++)
    {
        copy[i] = new int[clockHands.size() + 2];
    }

    for (int i = 0; i < clockHands.size() + 2; i++)
    {
        for (int j = 0; j < clockHands.size() + 2; j++)
        {
            copy[i][j] = 0;
        }
    }

    for (int i = 0; i < clockHands.size(); i++)
    {
        for (int j = 0; j < clockHands.size(); j++)
        {
            if (clockHands[i][j] != 0)
            {
                copy[i+1][j+1] = 4 - clockHands[i][j];
            }
        }
    }

    int answer = 0;
    while (1)
    {
        int score1 = 0;
        int score2 = 0;
        int OnOff = 1;
        for (int i = 1; i < clockHands.size() + 1; i++)
        {
            OnOff = 1;
            for (int j = 1; j < clockHands.size() + 1; j++)
            {
                for (int k = 0; k < clockHands.size() + 2; k++)
                {
                    for (int l = 0; l < clockHands.size() + 2; l++)
                    {
                        cout << copy[k][l] << " ";
                    }
                    cout << endl;
                }
                int c;
                cin >> c;
                score2 = 0;
                score1 = copy[i][j] + copy[i + 1][j] + copy[i - 1][j] + copy[i][j + 1] + copy[i][j - 1];
                if (copy[i][j] - 1 == -1)
                {
                    score2 += 3;
                }
                else
                {
                    score2 += copy[i][j] - 1;
                }
                if (i + 1 != clockHands.size() + 1 && copy[i + 1][j] - 1 == -1)
                {
                    score2 += 3;
                }
                else
                {
                    score2 += copy[i + 1][j] - 1;
                }
                if (i - 1 != 0 && copy[i - 1][j] - 1 == -1)
                {
                    score2 += 3;
                }
                else
                {
                    score2 += copy[i - 1][j] - 1;
                }
                if (j + 1 != clockHands.size() + 1 && copy[i][j + 1] - 1 == -1)
                {
                    score2 += 3;
                }
                else
                {
                    score2 += copy[i][j + 1] - 1;
                }
                if (j - 1 != 0 && copy[i][j - 1] - 1 == -1)
                {
                    score2 += 3;
                }
                else
                {
                    score2 += copy[i][j - 1] - 1;
                }

                if (score2 < score1)
                {
                    OnOff = 0;
                    answer += 1;
                    if (i - 1 != 0)
                    {
                        copy[i - 1][j] -= 1;
                        if (copy[i - 1][j] < 0)
                        {
                            copy[i - 1][j] = 4 + copy[i - 1][j];
                        }
                    }
                    if (i + 1 != clockHands.size() + 1)
                    {
                        copy[i + 1][j] -= 1;
                        if (copy[i + 1][j] < 0)
                        {
                            copy[i + 1][j] = 4 + copy[i + 1][j];
                        }
                    }
                    if (j - 1 != 0)
                    {
                        copy[i][j - 1] -= 1;
                        if (copy[i][j - 1] < 0)
                        {
                            copy[i][j - 1] = 4 + copy[i][j - 1];
                        }
                    }
                    if (j + 1 != clockHands.size() + 1)
                    {
                        copy[i][j + 1] -= 1;
                        if (copy[i][j + 1] < 0)
                        {
                            copy[i][j + 1] = 4 + copy[i][j + 1];
                        }
                    }
                    copy[i][j] -= 1;
                    if (copy[i][j] < 0)
                    {
                        copy[i][j] = 4 + copy[i][j];
                    }
                }
            }
        }
        if (OnOff)
        {
            break;
        }   
    }

    return answer;
}

int main()
{
    vector<vector<int>> clockHands = { {1,0,0,0,1},{0,3,3,3,0},{0,3,3,3,0},{0,3,3,3,0},{1,0,0,0,1} };
    int result = solution(clockHands);
    cout << result;
    int j;
    cin >> j;
}