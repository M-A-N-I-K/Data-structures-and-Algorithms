/*
Write a recursive function to convert a given string into the number it represents. That is input will be a numeric string that contains only numbers, you need to convert the string into corresponding integer and return the answer.
Input format :

Numeric string S (string, Eg. "1234")

Output format :

Corresponding integer N (int, Eg. 1234)

Constraints :

0 <= |S| <= 9
where |S| represents length of string S.

Sample Input 1 :

00001231

Sample Output 1 :

1231

Sample Input 2 :

12567

Sample Output 2 :

12567
*/
#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;

int stringToNumber(char input[], int last)
{
    if (last == 0)
    {
        return input[0] - '0';
    }
    int ans = stringToNumber(input, last - 1);
    ans = ans * 10 + (input[last] - '0');
    return ans;
}
int stringToNumber(char input[])
{
    int len = strlen(input);
    return stringToNumber(input, len - 1);
}

// int stringToNumber(char input[])
// {
//     int n = strlen(input);
//     if (n == 0)
//     {
//         return 0;
//     }
//     int num = stringToNumber(input + 1);
//     if (input[0] != '0')
//     {

//         int temp = input[0] - '0';
//         num = pow(10, n - 1) * temp + num;
//     }
//     return num;
// }

int main()
{
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
    return 0;
}
