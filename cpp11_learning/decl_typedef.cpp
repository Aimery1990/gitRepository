
#include <iostream>
#include <map>

using namespace std;


int main()
{
    map<int, string> mis;
    mis.insert(map<int, string>::value_type(1, "china"));

    typedef decltype(map<int, string>::value_type()) mypair;
    mis.insert(mypair(2, "america"));

    for(auto & i:mis)
        cout << i.first << " : " << i.second << endl;
}
