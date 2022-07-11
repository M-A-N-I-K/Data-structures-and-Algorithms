/*
Check whether a given String S is a palindrome using recursion. Return true or false.
Input Format :

String S

Output Format :

'true' or 'false'

Constraints :

0 <= |S| <= 1000
where |S| represents length of string S.

Sample Input 1 :

racecar

Sample Output 1:

true

Sample Input 2 :

ninja

Sample Output 2:

false
*/

#include <iostream>
using namespace std;

bool checkPalindromeHelper(char input[], int start, int end)
{
    if (start == end)
    {
        return true;
    }
    if (input[start] != input[end])
    {
        return false;
    }
    if (start < end + 1)
    {
        return checkPalindromeHelper(input, start + 1, end - 1);
    }
    return true;
}

bool checkPalindrome(char input[])
{
    int n = 0;
    while (input[n] != '\0')
    {
        n++;
    }
    if (n == 0 || n == 1)
    {
        return true;
    }
    bool ans = checkPalindromeHelper(input, 0, n - 1);
    return ans;
}

int main()
{
    char input[50];
    cin >> input;

    if (checkPalindrome(input))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    return 0;
}