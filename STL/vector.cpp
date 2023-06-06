#include <bits/stdc++.h>
using namespace std;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    // vector <date-type> name;  for empty vector
    // vector <data-type> name(size);
    // vector <data-type> name (size,defaultvalue);
    // to find size of vector name.size()
    vector<int> vec;
    cout << vec.size() << endl;
    vector<int> vec1(1000);
    cout << vec1.size() << endl;
    vector<int> vec2(3, 0);
    cout << vec2.size() << endl;
    // time complexity size() O(1)
    // accessing a particular element of vector
    // 0 based indexing
    // name[0]==> 1st element
    // name.push_back(value) to add new element in vector
    // time complexity push_back() O(1)
    vec2.push_back(4);
    cout << vec2[3] << endl;
    // to change size of vector at any point name.resize(size)
    // to sort vector in assending order sort(name.begin(),name.end())
    // time complexity sort() O(N logN)
    sort(vec2.begin(), vec2.end());
    for (int i = 0; i < 4; i++)
    {
        cout << vec2[i] << " ";
    }
    cout << endl;
    // to reverse a vector reverse(name.begin(),name.end())
    // time complexity reverse() O(N)
    reverse(vec2.begin(), vec2.end());
    for (int i = 0; i < 4; i++)
    {
        cout << vec2[i] << " ";
    }
    cout << endl;
    for (auto num : vec2)
    {
        cout << num << " ";
    }
    cout << endl;
    // to delete last element of vector name.pop_back()
    // time complexity pop_back() O(1)
    vec2.pop_back();
    for (auto num : vec2)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}