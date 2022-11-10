#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> clockHands) 
{
    int** copy = new int* [clockHands.size() + 2];
    for (int i = 0; i < clockHands.size() + 2; i++)
    {
        copy[i] = new int[clockHands[i].size() + 2];
    }

    for (int i = 0; i < clockHands.size() + 2; i++)
    {
        for (int j = 0; j < clockHands.size() + 2; j++)
        {
            if (i == 0 || j == 0 || i == clockHands.size() + 1 || j == clockHands.size() + 1 || clockHands[i][j] == 0)
            {
                copy[i][j] = 0;
            }
            else
            {
                copy[i][j] = 4 - clockHands[i][j];
            }
        }
    }

    int answer = 0;
    while (1)
    {
        int MaxScore = 0;
        int score = 0;
        int x = 0;
        int y = 0;
        for (int i = 1; i < clockHands.size() + 1; i++)
        {
            for (int j = 1; j < clockHands[i].size() + 1; j++)
            {
                score = copy[i][j] + copy[i + 1][j] + copy[i - 1][j] + copy[i][j + 1] + copy[i][j - 1];
                if (score > MaxScore)
                {
                    MaxScore = score;
                    x = i;
                    y = j;
                }
            }
        }
        if (MaxScore == 0)
        {
            break;
        }

        int num = copy[x][y];
        answer += num;
        if (x - 1 != 0)
        {
            copy[x - 1][y] -= num;
            if (copy[x - 1][y] < 0)
            {
                copy[x - 1][y] = -copy[x - 1][y];
            }
        }
        if (x + 1 != clockHands.size() + 2)
        {
            copy[x + 1][y] -= num;
            if (copy[x + 1][y] < 0)
            {
                copy[x + 1][y] = -copy[x + 1][y];
            }
        }
        if (y - 1 != 0)
        {
            copy[x][y - 1] -= num;
            if (copy[x][y - 1] < 0)
            {
                copy[x][y - 1] = -copy[x][y - 1];
            }
        }
        if (y + 1 != clockHands.size() + 2)
        {
            copy[x][y + 1] -= num;
            if (copy[x][y + 1] < 0)
            {
                copy[x][y + 1] = -copy[x][y + 1];
            }
        }
        copy[x][y] -= num;
        if (copy[x][y] < 0)
        {
            copy[x][y] = -copy[x][y];
        }
    }

    return answer;
}

int main()
{

}