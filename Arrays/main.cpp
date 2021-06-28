#include <bits/stdc++.h>
using namespace std;
int largestElementIndex(int *arr, int n); //* arr is array and n is the size of array
bool arraySorted(int *arr, int n);
void reverseArray(int *arr, int n);
int removeRepeatedElm(int *arr, int n);
void moveZerosAtEnd(int *arr, int n);
void leader(int *arr, int n);
int main()
{
    int arr[] = {7, 10, 4, 10, 6, 5, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    leader(arr, size);

    return 0;
}
int largestElementIndex(int *arr, int n)
{
    int maxSoFar = INT_MIN;
    int result_index = 0;
    for (int y = 0; y < n; y++)
    {
        if (arr[y] > maxSoFar)
        {
            result_index = y;
            maxSoFar = arr[y];
        }
    }
    return result_index;
}
bool arraySorted(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
            return false;
    }

    return true;
}
void reverseArray(int *arr, int n)
{
    for (int i = 0; i < n / 2; i++)
    {
        swap(arr[i], arr[n - i - 1]);
    }
}
int removeRepeatedElm(int *arr, int n)
{
    int result = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[result - 1])
        {
            arr[result] = arr[i];
            result++;
        }
    }
}
void moveZerosAtEnd(int *arr, int n)
{
    int count = 0; // count of non xero elem
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[count], arr[i]);
            count++;
        }
    }
}
void leader(int *arr, int n)
{
    int max_so_far = INT_MIN;
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] > max_so_far)
        {
            max_so_far = arr[i];
            cout << max_so_far << " ";
        }
    }
}