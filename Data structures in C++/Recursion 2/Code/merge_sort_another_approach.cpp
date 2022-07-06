#include <iostream>
using namespace std;

void merge(int *input, int start, int mid, int end)
{
    int *temp = new int[end - start + 1];
    int i = start, j = mid + 1, k = 0;
    while (i <= mid && j <= end)
    {
        if (input[i] >= input[j])
        {
            temp[k++] = input[j++];
        }
        else
        {
            temp[k++] = input[i++];
        }
    }
    while (i <= mid)
    {
        temp[k++] = input[i++];
    }
    while (j <= end)
    {
        temp[k++] = input[j++];
    }
    for (int l = 0; l < k; l++)
    {
        input[start++] = temp[l];
    }
    delete[] temp;
}

void mergeSort(int *input, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int mid = (start + end) / 2;
    mergeSort(input, start, mid);
    mergeSort(input, mid + 1, end);
    merge(input, start, mid, end);
}

int main()
{
    int length;
    cin >> length;
    int *input = new int[length];
    for (int i = 0; i < length; i++)
        cin >> input[i];
    mergeSort(input, 0, length - 1);
    for (int i = 0; i < length; i++)
    {
        cout << input[i] << " ";
    }
    return 0;
}