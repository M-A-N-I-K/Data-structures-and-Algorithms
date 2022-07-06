#include <iostream>
#include <cmath>
using namespace std;
int subs(string input, string output[])
{
    if (input.empty())
    {
        output[0] = "";
        return 1;
    }
    string str = input.substr(1);
    int smallerOutput = subs(str, output);
    for (int i = 0; i < smallerOutput; i++)
    {
        output[i + smallerOutput] = input[0] + output[i];
    }
    return 2 * smallerOutput;
}
int main()
{
    string s = "abcd";
    int n = pow(2, s.size());
    string *s1 = new string[n];
    int size = subs(s, s1);
    for (int i = 0; i < size; i++)
    {
        cout << s1[i] << endl;
    }
    return 0;
}