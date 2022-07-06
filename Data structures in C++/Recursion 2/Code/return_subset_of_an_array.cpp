#include <iostream>
using namespace std;

int subset(int *input, int length, int output[][20])
{
    if (length == 0)
    {
        output[0][0] = 0;
        return 1;
    }
    int smallOutput = subset(input + 1, length - 1, output);
    for (int i = 0; i < smallOutput; i++)
    {
        int size = output[i][0];
        output[i + smallOutput][0] = size + 1;
        output[i + smallOutput][1] = input[0];
        for (int j = 1; j <= size; j++)
        {
            output[i + smallOutput][j + 1] = output[i][j];
        }
    }
    return 2 * smallOutput;
}

int main()
{
    int input[20], length, output[35000][20];
    cin >> length;
    for (int i = 0; i < length; i++)
        cin >> input[i];

    int size = subset(input, length, output);

    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j <= output[i][0]; j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}