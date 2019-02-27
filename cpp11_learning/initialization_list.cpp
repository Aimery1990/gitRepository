
#include<iostream>
#include <vector>
#include <list>
#include <map>

using namespace std;

int main()
{
    int arr[] = {1,2,3,4,5};
    int arr2[] {1,2,3,4,5};

    // vector<int> vi;
    // vector<int> vi(10);
    // vector<int> vi(10, 101);
    // vector<int> vi(arr, arr+10);
    // vector<int> vi{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
     vector<int> vi = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};


    for(auto & i: vi)
    {
        cout << i << ", ";
    }
    cout << endl;

    // list<int> li;
    // list<int> li(10);
    // list<int> li(10, 101);
    // list<int> li(arr, arr+10);
    // list<int> li{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
     list<int> li = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};


    for(auto & i: li)
    {
        cout << i << ", ";
    }
    cout << endl;

    // map<int, string> mis;
    // mis[0] = "china";
    // mis[1] = "america";
    // mis[2] = "canada";

    // mis.insert(make_pair<int, string>(3, "japan"));
    // mis.insert(make_pair<int, string>(4, "germany"));
    // mis.insert(make_pair<int, string>(5, "british"));

    // mis.insert(map<int, string>::value_type(6, "france"));
    // mis.insert(map<int, string>::value_type(7, "italy"));
    // mis.insert(map<int, string>::value_type(8, "australia"));

    map<int, string> mis = {
        {1, "china"},
        {2, "ameria"},
        {3, "canada"}
    };    

    mis.insert({8, "australia"});

    for(auto i:mis)
    {
        cout << i.first << ": " << i.second << endl;
    }



    return 0;
}