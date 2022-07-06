#include <iostream>
#include <string.h>
using namespace std;

bool checkAB(char input[])
{
    int n = strlen(input);
    if (n == 0)
    {
        return false;
    }
    if (input[0] == 'b')
    {
        return false;
    }
    if (input[0] == 'a' && input[1] == '\0')
    {
        return true;
    }
    if (input[0] == 'a' && input[1] == 'b' && input[2] == 'b' && (input[3] == 'a' || input[3] == '\0'))
    {
        return true;
    }
    bool smallAns = checkAB(input + 1);
    return smallAns;
}

int main()
{
    char input[100];
    bool ans;
    cin >> input;
    ans = checkAB(input);
    if (ans)
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return 0;
}