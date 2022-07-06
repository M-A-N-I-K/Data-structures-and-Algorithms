#include <iostream>
using namespace std;

int partition(int *arr, int start, int end)
{
    int countSmaller = 0;
    for (int i = start + 1; i <= end; i++)
    {
        if (arr[start] >= arr[i])
        {
            countSmaller++;
        }
    }
    int temp = arr[start];
    arr[start] = arr[countSmaller + start];
    arr[countSmaller + start] = temp;
    int i = start, j = end;
    while (i < start + countSmaller && j > start + countSmaller)
    {
        if (arr[i] <= arr[start + countSmaller])
        {
            i++;
        }
        else if (arr[j] > arr[start + countSmaller])
        {
            j--;
        }
        else
        {
            int temp = arr[i];
            arr[i++] = arr[j];
            arr[j--] = temp;
        }
    }
    return start + countSmaller;
}

void quickSort(int *arr, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int part = partition(arr, start, end);
    quickSort(arr, start, part - 1);
    quickSort(arr, part + 1, end);
}
int main()
{
    int length;
    cin >> length;
    int *input = new int[length];
    for (int i = 0; i < length; i++)
        cin >> input[i];
    quickSort(input, 0, length - 1);
    for (int i = 0; i < length; i++)
    {
        cout << input[i] << " ";
    }
    return 0;
}