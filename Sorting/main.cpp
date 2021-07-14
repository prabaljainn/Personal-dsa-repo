#include <bits/stdc++.h>
using namespace std;

void print_vector(vector<int> arr);
void bubble_sort(vector<int> &arr);
void selection_sort(vector<int> &arr);
void insertion_sort(vector<int> &arr);
void merge_sort(vector<int> &arr);
vector<int> merge_two_sorted_vectors(vector<int> vector1, vector<int> vector2); //* merging two sorted vectors
void merge(int *arr, int low, int mid, int high);                               //* merge function of merge sort one of the most imp
void merge_sort(int *arr, int n);
void quick_sort_Lomuto(int *arr, int n); //* implimentation of Q sort using Lumato partition
void quick_sort_hoare(int *arr, int n);  //* implimentation of Q sort using Hoare partition
int main()
{
    vector<int> arr{2, 4, 6, 8, 10, 12, 14};
    vector<int> arr2{2, 4, 6, 8, 10, 12, 14};
    int a[] = {10, 15, 20, 40, 8, 11, 15, 22, 25};
    quick_sort_Lomuto(a, 9);

    for (int x : a)
        cout << x << " ";

    return 0;
}

vector<int> merge_two_sorted_vectors(vector<int> vector1, vector<int> vector2)
{
    vector<int> merged_vector;

    // i is counter for vector 1 and j is counter for vector 2
    int i = 0, j = 0;
    while (i < vector1.size() && j < vector2.size())
    {
        if (vector1[i] <= vector2[j])
        {
            merged_vector.push_back(vector1[i]);
            i++;
        }
        else
        {
            merged_vector.push_back(vector2[j]);
            j++;
        }
    }
    while (i < vector1.size())
    {
        merged_vector.push_back(vector1[i]);
        i++;
    }
    while (j < vector2.size())
    {
        merged_vector.push_back(vector2[j]);
        j++;
    }

    return merged_vector;
}

void print_vector(vector<int> arr)
{
    for (auto x : arr)
        cout << x << " ";
}
void bubble_sort(vector<int> &arr)
{
    bool swapped;
    for (int i = 0; i < arr.size() - 1; i++)
    {
        swapped = false;
        for (int k = 0; k < arr.size() - 1 - i; k++)
        {
            if (arr[k] > arr[k + 1])
            {
                swap(arr[k], arr[k + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}
void selection_sort(vector<int> &arr)
{
    int min_index;
    for (int i = 0; i < arr.size(); i++)
    {
        min_index = i;
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[j] < arr[min_index])
                min_index = j;
        }
        swap(arr[min_index], arr[i]);
    }
}

void insertion_sort(vector<int> &arr)
{
    int sorted_unti = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            swap(arr[j], arr[j + 1]);
            j--;
        }
    }
}
void merge(int *arr, int low, int mid, int high)
{
    int l_array_elm = mid - low + 1;
    int r_array_elm = high - mid;

    int l_arr[l_array_elm];
    int r_arr[r_array_elm];

    for (int i = 0; i < l_array_elm; i++)
    {
        l_arr[i] = arr[i + low];
    }
    for (int j = 0; j < r_array_elm; j++)
    {
        r_arr[j] = arr[mid + 1 + j];
    }
    int k = low;

    int i = 0,
        j = 0;
    while (i < l_array_elm && j < r_array_elm)
    {
        if (l_arr[i] <= r_arr[j])
        {
            arr[k++] = l_arr[i++];
        }
        else
        {
            arr[k++] = r_arr[j++];
        }
    }
    while (i < l_array_elm)
    {
        arr[k] = l_arr[i];
        i++;
        k++;
    }
    while (j < r_array_elm)
    {
        arr[k] = r_arr[j];
        j++;
        k++;
    }
}
void merge_sort_utility(int *arr, int start, int end)
{
    if (start >= end)
        return;
    auto mid = start + (end - start) / 2;

    merge_sort_utility(arr, start, mid);
    merge_sort_utility(arr, mid + 1, end);
    merge(arr, start, mid, end);
}

void merge_sort(int *arr, int n)
{
    merge_sort_utility(arr, 0, n);
}

//** Lumato partition
int lomuto_partition(int *arr, int low, int high)
{
    int pivot = arr[high];
    int counter = low - 1;
    for (int i = low; i <= high - 1; i++)
    {
        if (arr[i] <= pivot)
        {
            counter++;
            swap(arr[counter], arr[i]);
        }
    }
    swap(arr[high], arr[counter + 1]);
    return counter + 1;
}
void qSort_Lomuto(int *arr, int low, int high)
{
    if (low < high)
    {
        int pivot = lomuto_partition(arr, low, high);
        qSort_Lomuto(arr, low, pivot - 1);
        qSort_Lomuto(arr, pivot + 1, high);
    }
}
void quick_sort_Lomuto(int *arr, int n) //* i have used qSort_Lomuto in order to get rid of getting low and high from user
{

    qSort_Lomuto(arr, 0, n - 1);
}