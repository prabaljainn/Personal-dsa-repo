#include <bits/stdc++.h>
using namespace std;

int main()
{

    //* appplications of PQueues or heap DS are : Dijkstra algo, huffman algo, Prism algo , Heap sort
    priority_queue<int, vector<int>> pq; //* priority q in stl impliments Max Heap
    pq.push(15);
    pq.push(45);
    pq.push(25);
    pq.push(32);
    pq.push(89);

    pq.top(); //* so top() will return max elem from the max heap i.e 89 here

    while (pq.empty() == false)
    {
        cout << pq.top() << " ";
        pq.pop();
    }

    cout << "\n";
    priority_queue<int, vector<int>, greater<int>> mpq; //* this impliments Min Heap priority Q
    mpq.push(15);
    mpq.push(45);
    mpq.push(25);
    mpq.push(32);
    mpq.push(89);

    mpq.top(); //* so top() will return max elem from the max heap i.e 15 here

    while (mpq.empty() == false)
    {
        cout << mpq.top() << " ";
        mpq.pop();
    }
    cout << "\n";

    //* you can also make a priority Q from an existing Array of elem
    int arr[] = {1, 5, 8, 9, 566, 88};
    int sizeofArr = sizeof(arr) / sizeof(arr[0]);
    priority_queue<int> pqFromArr(arr, arr + sizeofArr);

    while (pqFromArr.empty() == false)
    {
        cout << pqFromArr.top() << " ";
        pqFromArr.pop();
    }

    return 0;
}