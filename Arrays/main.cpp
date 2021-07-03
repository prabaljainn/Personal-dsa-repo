#include <bits/stdc++.h>
using namespace std;
int largestElementIndex(int *arr, int n); //* arr is array and n is the size of array
bool arraySorted(int *arr, int n);
void reverseArray(int *arr, int n);
int removeRepeatedElm(int *arr, int n);
void moveZerosAtEnd(int *arr, int n);
void leader(int *arr, int n);
void fzInSortedArray(int *arr, int n);
int maxDifference_j_i(int *arr, int n); // max differnce so far such that arr[j] - arr[i] is max and where j>  i
int Stock_Buy_sell(int *arr, int n);
int maximun_cons_ones(int *arr, int n);
int maxSum_Subarray(int *arr, int n);           //O(n^2)
int maxSum_SubArray_Efficient(int *arr, int n); //Kadane's Algo
int max_Length_evenOdd(int *arr, int n);
int main()
{
    int arr[] = {5, 10, 20, 63, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << max_Length_evenOdd(arr, size);

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
void fzInSortedArray(int *arr, int n)
{
    int i = 1;
    int freq = 1;

    while (i <= n && n != 1)
    {
        if (arr[i] != arr[i - 1])
        {
            cout << arr[i - 1] << " " << freq << endl;
            freq = 1;
        }
        else
        {
            freq++;
        }
        i++;
    }
    if (n == 1)
    {
        cout << arr[i] << " " << 1 << endl;
    }
}
int maxDifference_j_i(int *arr, int n)
{
    int max_diff_so_far = arr[1] - arr[0];
    int min_value = arr[0];
    for (int j = 1; j < n; j++)
    {
        max_diff_so_far = max(arr[j] - min_value, max_diff_so_far);
        min_value = min(min_value, arr[j]);
    }
    return max_diff_so_far;
}
int Stock_Buy_sell(int *arr, int n)
{
    int profit = 0;
    for (int i = 1; i < n; i++)
        if (arr[i] > arr[i - 1])
            profit += arr[i] - arr[i - 1];
    return profit;
}
int maximun_cons_ones(int *arr, int n)
{
    int count = 0;
    int max_cunt = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            count++;
        }
        else
        {
            max_cunt = max(max_cunt, count);
            count = 0;
        }
    }
    return max_cunt;
}
int maxSum_Subarray(int *arr, int n)
{
    int max_so_far = arr[0];
    for (int i = 0; i < n; i++)
    {
        int current_sum = 0;
        for (int y = i; y < n; y++)
        {
            current_sum += arr[y];
            max_so_far = max(current_sum, max_so_far);
        }
    }
    return max_so_far;
}
int maxSum_SubArray_Efficient(int *arr, int n)
{
    int max_so_far = arr[0];
    int max_ending_with = arr[0];
    for (int i = 1; i < n; i++)
    {
        max_ending_with = max(arr[i], max_ending_with + arr[i]);
        max_so_far = max(max_so_far, max_ending_with);
    }
    return max_so_far;
}
int max_Length_evenOdd(int *arr, int n)
{
    int max_len_so_far = 1;
    int current_len = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] % 2 != arr[i - 1] % 2)
        {
            current_len++;
            max_len_so_far = max(max_len_so_far, current_len);
        }
        else
        {
            current_len = 1;
        }
    }
    return max_len_so_far;
}