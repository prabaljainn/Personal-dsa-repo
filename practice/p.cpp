#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int testcase;
    cin >> testcase;
    while (testcase--)
    {
        int arr[4];
        for (int i = 0; i < 4; i++)
        {
            cin >> arr[i];
        }
        unordered_set<int> s(arr, arr + 4);
        int number_of_d_elem = s.size();
        if (number_of_d_elem == 1 && arr[0] == arr[1] && arr[1] == arr[2])
        {
            number_of_d_elem = 0;
        }
        if (number_of_d_elem == 0)
            cout << 0 << endl;
        if (number_of_d_elem == 1)
            cout << 1 << endl;
        if (number_of_d_elem == 4 || number_of_d_elem == 2)
            cout << 2 << endl;
    }
    return 0;
}