#include <iostream>
using namespace std;

int binarySearch(int *arr, int low, int high, int x)
{
    if (low > high)
    {
        return -1;
    }
    int mid = low + (high - low) / 2;
    if (arr[mid] == x)
    {
        return mid;
    }
    else if (arr[mid] > x)
    {
        return binarySearch(arr, low, mid - 1, x);
    }
    else
    {
        return binarySearch(arr, mid + 1, high, x);
    }
}

int main()
{
    int input[100000], length, element, ans;
    cin >> length;
    for (int i = 0; i < length; i++)
    {
        cin >> input[i];
    }

    cin >> element;
    ans = binarySearch(input, 0, length - 1, element);
    cout << ans << endl;
    return 0;
}