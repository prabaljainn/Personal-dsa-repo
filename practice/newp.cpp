#include <bits/stdc++.h>
using namespace std;
struct pairs
{
    int first;

    int last;
};

bool mycomparison(pairs p1, pairs p2)
{
    return (p2.first > p1.first);
}
int main()
{
    vector<pairs> v1;
    v1.push_back({2, 5});
    v1.push_back({5, 5});
    v1.push_back({9, 5});
    v1.push_back({123, 5});
    sort(v1.begin(), v1.end(), mycomparison);
    for (auto x : v1)
    {
        cout << x.first << " ";
    }
    return 0;
}
