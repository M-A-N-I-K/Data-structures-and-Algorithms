/*
Given a string S, remove consecutive duplicates from it recursively.
Input Format :

String S

Output Format :

Output string

Constraints :

1 <= |S| <= 10^3
where |S| represents the length of string

Sample Input 1 :

aabccba

Sample Output 1 :

abcba

Sample Input 2 :

xxxyyyzwwzzz

Sample Output 2 :

xyzwz

*/
#include <iostream>
#include <string.h>
using namespace std;

void removeConsecutiveDuplicates(char s[])
{
    int n = strlen(s);
    if (n <= 1)
    {
        return;
    }
    int i = 0, j = 1;
    while (s[i] == s[j])
    {
        for (int i = 0; i < n - 1; i++)
        {
            s[i] = s[i + 1];
        }
        s[n - 1] = '\0';
    }
    removeConsecutiveDuplicates(s + 1);
}

int main()
{
    char s[100000];
    cin >> s;
    removeConsecutiveDuplicates(s);
    cout << s << endl;
    return 0;
}