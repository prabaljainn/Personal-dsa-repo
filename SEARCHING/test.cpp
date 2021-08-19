#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define endl "\n"
#define int long long int
#define eb emplace_back
#define pb push_back
#define f first
#define s second

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define fast_io ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
int last_occ_in_sortedArray(int *arr, int n, int elem);
using namespace std;
signed main()
{
    fast_io;
    int n;
    cin >> n;
    int arr[n]{};
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int testcase;
    cin >> testcase;
    while (testcase--)
    {
        int test;
        cin >> test;
        cout << last_occ_in_sortedArray(arr, n, test) << endl;
    }
    return 0;
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
    return 0;
}