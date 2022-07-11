/*
Given a string, compute recursively a new string where all appearances of "pi" have been replaced by "3.14".
Constraints :

1 <= |S| <= 50
where |S| represents the length of string S.

Sample Input 1 :

xpix

Sample Output :

x3.14x

Sample Input 2 :

pipi

Sample Output :

3.143.14

Sample Input 3 :

pip

Sample Output :

3.14p

Constraints:-

1<=|S|<=50
*/
#include <iostream>
#include <string.h>
using namespace std;

void replacePi(char input[])
{
    int n = strlen(input);
    if (n == 0)
    {
        return;
    }
    if (input[0] == 'p' && input[1] == 'i')
    {
        for (int i = n + 2; i > 2; i--)
        {
            input[i] = input[i - 2];
        }
        input[0] = '3';
        input[1] = '.';
        input[2] = '1';
        input[3] = '4';
    }
    replacePi(input + 1);
}

int main()
{
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
    return 0;
}