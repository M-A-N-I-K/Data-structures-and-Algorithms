#include <iostream>
using namespace std;

void printKeypadCodes(int num, string out)
{
    if (num == 0)
    {
        cout << out << endl;
        return;
    }
    string mapping[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string str = mapping[num % 10];
    for (int i = 0; i < str.size(); i++)
    {
        printKeypadCodes(num / 10, str[i] + out);
    }
}

int main()
{
    int num;
    cin >> num;

    string output;
    printKeypadCodes(num, output);
    return 0;
}