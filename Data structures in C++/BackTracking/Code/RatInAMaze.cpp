#include <iostream>
#include <iomanip>
#include <string.h>
#define N 18
using namespace std;

int solution[N][N];

void mazeHelper(int maze[][N], int n, int x, int y)
{
    if (x == n - 1 && y == n - 1)
    {
        solution[x][y] = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << solution[i][j] << " ";
            }
        }
        cout << endl;
        solution[x][y] = 0;
        return;
    }
    if (x == n || x < 0 || y == n || y < 0 || maze[x][y] == 0 || solution[x][y] == 1)
    {
        return;
    }

    solution[x][y] = 1;
    mazeHelper(maze, n, x, y + 1);
    mazeHelper(maze, n, x, y - 1);
    mazeHelper(maze, n, x + 1, y);
    mazeHelper(maze, n, x - 1, y);

    solution[x][y] = 0;
}

void ratInAMaze(int maze[][N], int n)
{

    memset(solution, 0, N * N * sizeof(int));
    mazeHelper(maze, n, 0, 0);
}

int main()
{
    int n;
    cin >> n;
    int maze[N][N];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> maze[i][j];
        }
    }
    ratInAMaze(maze, n);
    return 0;
}