#include <bits/stdc++.h>

using namespace std;

int main()
{
    int Sqaure_matrix_size;
    cin >> Sqaure_matrix_size;
    vector<vector<int>> arr(Sqaure_matrix_size);
    //For Filling the Matrix i am writing a looop

    for (int i = 0; i < Sqaure_matrix_size; i++)
    {
        for (int j = 0; j < Sqaure_matrix_size; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << arr[0][0];
}