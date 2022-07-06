#include <iostream>
using namespace std;
void merge(int *arr1, int size1, int *arr2, int size2, int *input)
{
    int i = 0, j = 0, k = 0;
    while (i != size1 && j != size2)
    {
        if (arr1[i] > arr2[j])
        {
            input[k++] = arr2[j++];
        }
        else if (arr1[i] < arr2[j])
        {
            input[k++] = arr1[i++];
        }
        else
        {
            input[k++] = arr1[i++];
            input[k++] = arr2[j++];
        }
    }
    while (i != size1)
    {
        input[k++] = arr1[i++];
    }
    while (j != size2)
    {
        input[k++] = arr2[j++];
    }
}
void mergeSort(int input[], int size)
{
    if (size <= 1)
    {
        return;
    }
    int mid = size / 2;
    mergeSort(input, mid);
    mergeSort(input + mid, size - mid);
    int *arr1 = new int[mid];
    int *arr2 = new int[size - mid];
    int i;
    for (i = 0; i < mid; i++)
    {
        arr1[i] = input[i];
    }
    int j = 0;
    for (; i < size; i++)
    {
        arr2[j] = input[i];
        j++;
    }
    merge(arr1, mid, arr2, size - mid, input);
}

int main()
{
    int length;
    cin >> length;
    int *input = new int[length];
    for (int i = 0; i < length; i++)
        cin >> input[i];
    mergeSort(input, length);
    for (int i = 0; i < length; i++)
    {
        cout << input[i] << " ";
    }
    return 0;
}