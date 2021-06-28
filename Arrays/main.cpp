#include <bits/stdc++.h>
using namespace std;
int largestElementIndex(int *arr, int n); //* arr is array and n is the size of array
bool arraySorted(int *arr, int n);
int main()
{
    int arr[] = {1, 4, 5, 6, 8, 22, 33, 66, 66, 99, 100, 10001};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << arraySorted(arr, size) << endl;

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