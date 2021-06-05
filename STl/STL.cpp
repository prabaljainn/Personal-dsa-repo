#include <bits/stdc++.h>
using namespace std;

int main()
{
    //**set<int >s will make a set in generally increasing order
    //**but set<int , greater <int>> willl store in decreaasing order
    //**always use greater<int > to reverse the order
    set<int> s;
    s.insert(2);
    s.insert(5);
    s.insert(5);
    s.insert(0);
    s.insert(45);
    s.insert(87);
    s.insert(54);

    // for (set<int>::iterator i = s.begin(); i != s.end(); i++)
    // {
    //     cout << *i << " ";
    // }
    // cout << endl;
    // for (auto i = s.rbegin(); i != s.rend(); i++)
    // {
    //     cout << *i << " ";
    // }
    // cout << endl;

    //** so s.begin() returns the iterator to thefirst elemt of the set
    //** s.end() returns the iterator to the last elem +1 elem
    //** s.rbegin() and s.rend() returns iterator reverse of begin() and end() as shown in last to set treversals
    //* s.clear() clears the whole set
    //* s.erase(45) will erase the existance of 45 in the set & if the elem 45 is not present in the set the set remain unchaged, erase can also take range of ityerators to ercase
    //* s.find(x) will return a iterator to the elem in set but if the elem is not presnt in the set it will return the iterator to s.end()
    //* while s.count() return the frequency of times the elem occured for set it would either be 0 or 1; makes sense for multisets

    // auto x = s.find(45);
    // auto y = s.count(45);
    // s.erase(x, s.end());
    // for (auto x : s)
    //     cout << x << " ";
    //** Lower bound and upper Bound

    s.insert(2);
    s.insert(5);
    s.insert(45);
    s.insert(87);
    s.insert(54);
    s.insert(88);
    //* lower bound : Smalles greater elem or the elm is prestent
    auto sa = s.lower_bound(44);
    if (sa != s.end())
        cout << "\n"
             << *sa;
    auto sb = s.upper_bound(45);
    if (sb != s.end())
        cout << "\n"
             << *sb;
    //* set is used to store only keys while map is used to store key value pairs

    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";

    map<int, vector<int>> cop;
    cop[0].push_back(2);
    cop[0].push_back(5);

    for (auto i : cop)

    {
        for (auto x : i.second)
            cout << x << " ";
    }

    return 0;
}