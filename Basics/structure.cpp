#include <bits/stdc++.h>
using namespace std;

struct student
{
    int EnNo;
    string name;
    string branch;
};

struct Point
{
    int x;
    int y;
};

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    student student1;
    student1.EnNo = 16100;
    student1.name = "Shubham patel";
    student1.branch = "IT";
    cout << student1.EnNo << endl;
    cout << student1.name << endl;
    cout << student1.branch << endl;

    // taking input of coordinates by sturcture
    Point point[10];
    for (int i = 0; i < 10; i++)
    {
        cin >> point[i].x >> point[i].y;
    }
    // taking input of coordinates by pair
    // syntex pair<data-type,data-type> name
    // for 3D pair<int,pair<int,int>> name;
    pair<int, int> point2;
    cin >> point2.first >> point2.second;
    return 0;
}