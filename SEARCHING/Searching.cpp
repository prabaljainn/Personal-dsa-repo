//* better to use( better comments) and (Prettier - Code formatter) extension in VSCODE to view good used comments in the file
#include <bits/stdc++.h>
using namespace std;
int binarySearch(int *arr, int n, int elem);             //* Simple BINARY SEARCH ALGO
int first_occ_in_sortedArray(int *arr, int n, int elem); //* return the index of first occ of an elem in an sorted array
int last_occ_in_sortedArray(int *arr, int n, int elem);  //* return the index of last occ of an elem in an sorted array
int fz_in_a_sorted_array(int *arr, int n, int elem);     //* return the Fz of an elem in an array
//sq root
//unbounded Binary search
int main()
{

    int arr[] = {1, 1, 1, 10, 20, 30};
    int size_n = sizeof(arr) / sizeof(arr[0]);
    cout << fz_in_a_sorted_array(arr, size_n, 1);
    return 0;
}

int binary_util(int *arr, int start, int end, int elem)
{
    while (end >= start)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == elem)
            return mid;
        if (arr[mid] > elem)
            return binary_util(arr, start, mid - 1, elem);
        if (arr[mid] < elem)
            return binary_util(arr, mid + 1, end, elem);
    }
    return -1;
}
int binarySearch(int *arr, int n, int elem)
{
    return binary_util(arr, 0, n - 1, elem);
}
int first_occ_in_sortedArray(int *arr, int n, int elem)
{
    int start = 0;
    int end = n - 1;
    while (end >= start)
    {
        int mid = start + end / 2;

        if (arr[mid] > elem)
            end = mid - 1;
        else if (arr[mid] < elem)
            start = mid + 1;
        else
        {
            if (mid == 0 || arr[mid - 1] != arr[mid])
                return mid;
            else
                end = mid - 1;
        }
    }
    return -1;
}
int last_occ_in_sortedArray(int *arr, int n, int elem)
{

    int start = 0;
    int end = n - 1;
    while (end >= start)
    {
        int mid = start + end / 2;

        if (arr[mid] > elem)
            end = mid - 1;
        else if (arr[mid] < elem)
            start = mid + 1;
        else
        {
            if (mid == n - 1 || arr[mid + 1] != arr[mid])
                return mid;
            else
                start = mid - 1;
        }
    }
    return -1;
}
int fz_in_a_sorted_array(int *arr, int n, int elem)
{
    auto first_occ = first_occ_in_sortedArray(arr, n, elem);
    if (first_occ == -1)
        return -1;
    else
        return (last_occ_in_sortedArray(arr, n, elem) - first_occ + 1);
}