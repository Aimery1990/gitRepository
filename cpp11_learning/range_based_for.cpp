
#include <iostream>
#include <vector>
#include <list>
#include <map>

using namespace std;


int main()
{
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};

    for(auto i:arr)         //without & elements in arr are not modified
    {
        i += 5;
    }

    for(auto i:arr)
    {
        cout << i << endl;
    }

    cout << "---------------" << endl;

    for(auto & i:arr)   //with & elements in arr are modified
    {
        i += 5;
    }

    for(auto i : arr)
    {
        cout << i << endl;
    }
    cout << "------------------" << endl;
    // char * p = "china";
    // for(auto i : p)    // error: p is not involved by begin or end unless it's a real array
    // {
    //     cout << i << endl;
    // }

    char p[] = "china";
    for(auto i : p)
    {
        cout << i << endl;
    }
    cout << "------------------" << endl;
    vector<int> vi(arr, arr+10);
    vector<int>::iterator it;
 
    for(it = vi.begin(); it < vi.end(); ++it)  //for(it = vi.begin(); it != vi.end(); ++it)
    {
        cout << *it << ", ";
    }
    cout << endl;

    for(auto i : vi)
    {
        cout << i << endl;
    }
    cout << "------------------" << endl;
    list<int> li(arr, arr+10);
    list<int>::iterator itl;
    for(auto i : li)
    {
        cout << i << ",";
    }
    cout << endl;
    cout << "------------------" << endl;

    map<int, string> mis;
    mis[0] = "china";
    mis[1] = "america";
    mis.insert({100, "canada"});

    map<int, string>::iterator itm;
    for(itm = mis.begin(); itm != mis.end(); ++itm) //error: for(itm = mis.begin(); itm < mis.end(); ++itm)
    {
        cout << itm->first << " : " << itm->second << endl;
    }
    cout << "------------------" << endl;
    
    for(auto item:mis)
    {
        cout << item.first << " : " << item.second << endl;
    }



    return 0;
}