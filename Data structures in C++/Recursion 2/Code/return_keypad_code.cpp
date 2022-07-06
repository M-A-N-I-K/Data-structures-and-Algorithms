#include <iostream>
#include <string.h>
using namespace std;

int returnKeypadCode(int num, string output[])
{
    if (num == 0)
    {
        output[0] = "";
        return 1;
    }
    int rem = num % 10;
    int smallOutput = returnKeypadCode(num / 10, output);
    string mapping[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string str = mapping[rem];
    string *temp = new string[smallOutput * str.size()];
    int k = 0;
    for (int i = 0; i < smallOutput; i++)
    {
        for (int j = 0; j < str.length(); j++)
        {
            temp[k++] = output[i] + str[j];
        }
    }
    for (int i = 0; i < smallOutput * str.size(); i++)
    {
        output[i] = temp[i];
    }
    return str.size() * smallOutput;
}

int main()
{
    int num;
    cin >> num;

    string output[10000];
    int count = returnKeypadCode(num, output);
    for (int i = 0; i < count && i < 10000; i++)
    {
        cout << output[i] << endl;
    }
    return 0;
}