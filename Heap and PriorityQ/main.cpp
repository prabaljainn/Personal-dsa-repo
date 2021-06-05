#include <bits/stdc++.h>

using namespace std;
class MinHeap
{
    int *arr;
    int size;
    int capacity;

public:
    MinHeap(int c)
    {
        arr = new int[c];
        this->capacity = c;
        size = 0;
    }
    int left(int i)
    {
        return (2 * i + 1);
    }
    int right(int i)
    {
        return (2 * i + 2);
    }
    int parent(int i)
    {
        return ((i - 1) / 2);
    }

    void insert(int x)
    {
        if (size == capacity)
            return;
        size++;
        this->arr[size - 1] = x;
        for (int i = size - 1; i != 0 && this->arr[parent(i)] > this->arr[i];)
        {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }
    void printsarrr()
    {
        cout << *(this->arr) << " ";
    }
    void minHeapify(int index)
    {
        int Lt = left(index);
        int Rt = right(index);
        int smallest = index;
        if (Lt < size && arr[Lt] < arr[index])
            smallest = Lt;
        if (Rt < size && arr[Rt] < arr[index])
            smallest = Rt;
        if (smallest != index)
        {
            swap(arr[index], arr[smallest]);
            minHeapify(smallest);
        }
    }
    int extractMin()
    {
        if (size == 0)
            return INT_MAX;
        if (size == 1)
        {
            size--;
            return arr[0];
        }
        swap(arr[0], arr[size - 1]);
        size--;
        minHeapify(0);
        return arr[size];
    }
};

int main()
{
    MinHeap h(10);
    h.insert(11);
    h.insert(55);
    h.insert(89);
    h.printsarrr();

    return 0;
}