#include <bits/stdc++.h>
using namespace std;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    // set is a special kind of STL container which stores unique elements in sorted order
    // syntax of set set<data-type> name
    set<int> st;
    // to insert a number name.insert(value);
    // time complexity insert() O(logN)
    st.insert(4);
    st.insert(3);
    // to know size of set name.size();
    // time complexity size() O(1);
    st.size();
    // to delete number from set name.erase(number);
    // time complexity erase() O(logN)
    st.erase(3);
    // to know if set is empty name.empty()
    bool IsEmpty = st.empty();
    /* to print all element of set:-
     for (auto it = name.begin(); it != name.end(); it++)
     {
        cout << *it << " ";
     }
    */
    // to find number auto it = name.find(number); cout << *it endl;

    return 0;
}