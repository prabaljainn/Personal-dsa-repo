#include <bits/stdc++.h>
using namespace std;
// **Unorderd set STl
// * sets are based on red balck tree and un_set are based on hashing
// * un_set doesnt maintain any order
int main()
{
    unordered_set<int> us;
    us.insert(5);
    us.insert(55);
    us.insert(5656);
    us.insert(55656);
    cout << us.size() << endl;
    return 0;
}