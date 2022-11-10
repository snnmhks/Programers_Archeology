#include <string>
#include <vector>

using namespace std;

void ScoreFix(int **ScoreBoard, vector<vector<int>> clockHands)
{
    for (int i = 0; i < clockHands.size(); i++)
    {
        for (int j = 0; j < clockHands[i].size(); j++)
        {
            ScoreBoard[i + 1][j + 1];
        }
    }
}

int solution(vector<vector<int>> clockHands) 
{
    int** copy = new int* [clockHands.size() + 2];
    for (int i = 0; i < clockHands.size() + 2; i++)
    {
        copy[i] = new int[clockHands[i].size() + 2];
    }
    for (int i = 0; i < clockHands.size() + 2; i++)
    {
        for (int j = 0; j < clockHands[i].size() + 2; j++)
        {
            copy[i + 1][j + 1] = clockHands[i][j];
        }
    }

    int** ScoreBoard = new int*[clockHands.size()];
    for (int i = 0; i < clockHands.size(); i++)
    {
        ScoreBoard[i] = new int[clockHands[i].size()];
    }

    int index = 0;
    int answer = 0;
    return answer;
}