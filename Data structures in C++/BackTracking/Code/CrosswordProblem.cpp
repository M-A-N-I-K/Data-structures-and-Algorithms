#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

bool isValidVertical(char crossword[][10], int row, int col, string word)
{
    int j = row;
    for (int i = 0; i < word.size(); i++)
    {
        if (i > 9)
        {
            return false;
        }
        if (crossword[j][col] == '-' || crossword[j][col] == word[i])
        {
            j++;
        }
        else
        {
            return false;
        }
    }
    return true;
}

bool isValidHorizontal(char crossword[][10], int row, int col, string word)
{
    int j = col;
    for (int i = 0; i < word.size(); i++)
    {
        if (i > 9)
        {
            return false;
        }
        if (crossword[row][j] == '-' || crossword[row][j] == word[i])
        {
            j++;
        }
        else
        {
            return false;
        }
    }
    return true;
}

void setVertical(char crossword[][10], int row, int col, string word, vector<bool> &marking)
{
    int j = row;
    for (int i = 0; i < word.size(); i++)
    {
        if (crossword[j][col] == '-')
        {
            crossword[j][col] = word[i];
            marking.push_back(true);
        }
        else
        {
            marking.push_back(false);
        }
        j++;
    }
}

void setHorizontal(char crossword[][10], int row, int col, string word, vector<bool> &marking)
{
    int j = col;
    for (int i = 0; i < word.size(); i++)
    {
        if (crossword[row][j] == '-')
        {
            crossword[row][j] = word[i];
            marking.push_back(true);
        }
        else
        {
            marking.push_back(false);
        }
        j++;
    }
}

void resetVertical(char crossword[][10], int row, int col, vector<bool> &marking)
{
    int j = row;
    for (int i = 0; i < marking.size(); i++)
    {
        if (marking[i])
        {
            crossword[j][col] = '-';
        }
        j++;
    }
}

void resetHorizontal(char crossword[][10], int row, int col, vector<bool> &marking)
{
    int j = col;
    for (int i = 0; i < marking.size(); i++)
    {
        if (marking[i])
        {
            crossword[row][j] = '-';
        }
        j++;
    }
}

bool crosswordSolve(char crossWord[][10], vector<string> &words, int index)
{
    if (index == words.size())
    {
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                cout << crossWord[i][j] << " ";
            }
            cout << endl;
        }
        return true;
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (crossWord[i][j] == '-' || crossWord[i][j] == words[index][0])
            {
                if (isValidVertical(crossWord, i, j, words[index]))
                {
                    vector<bool> marking;
                    setVertical(crossWord, i, j, words[index], marking);
                    if (crosswordSolve(crossWord, words, index + 1))
                    {
                        return true;
                    }
                    resetVertical(crossWord, i, j, marking);
                }

                if (isValidHorizontal(crossWord, i, j, words[index]))
                {
                    vector<bool> marking;
                    setHorizontal(crossWord, i, j, words[index], marking);
                    if (crosswordSolve(crossWord, words, index + 1))
                    {
                        return true;
                    }
                    resetHorizontal(crossWord, i, j, marking);
                }
            }
        }
    }
    return false;
}

int main()
{
    char crossword[10][10];
    for (int i = 0; i < 10; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < 10; j++)
        {
            crossword[i][j] = s[j];
        }
    }

    string s;
    cin >> s;
    vector<string> words;

    for (int i = 0; i < s.size(); i++)
    {
        int j = i;
        while (s[j] != ';' && j < s.size())
        {
            j++;
        }
        words.push_back(s.substr(i, j - i));
        i = j;
    }

    crosswordSolve(crossword, words, 0);
    return 0;
}