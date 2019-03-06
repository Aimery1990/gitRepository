
#include <iostream>
#include <typeinfo>
#include <vector>
#include <string>

using namespace std;

class Student{
public:
    string name;
    int age;
};

void func()
{
    cout << "void func()" << endl;
}

typedef void (*FUN_T)();

// void foo(auto x)  //c++14 is available
// {
//     cout << x << endl;   
// }

int main()
{
    vector<double> vi = {1,2,3,4};
    
    auto i = 5;
    cout << sizeof(i) << endl;

    auto d = 5.0;
    cout << sizeof(d) << endl;

    auto x = i + d;
    cout << sizeof(x) << endl;

    const int m = 100;
    auto n = m;
    n = 10;

    const auto n2 = m;
    //n2 = 9;

    auto fp = func;
    fp();

    // foo(3);
    // foo(3.5);

    vector<double> vx = {1,2,3,4};
    // vector<double>::iterator it = vx.begin();
    // for(;it<vx.end();it++)
    //     cout << *it << endl;
    for(auto & i:vx)
        cout << i << endl;

    auto arr = {1,2,3,4,5,6,7,8};
    cout << sizeof(arr) << " type " << typeid(arr).name() << endl; //16 type St16initializer_listIiE

    auto p = "china0000000000";
    cout << sizeof(p) << " type " << typeid(p).name() << endl; //8 type PKc
    cout << sizeof(char *) << endl; //8
    cout << sizeof(int *) << endl; //8
    cout << sizeof(int ) << endl; //4
    cout << sizeof(string) << endl; //24

    //auto stu = {"tony", 33}; //error
    //cout << sizeof(stu) << " type " << typeid(stu).name() << endl;

    return 0;
}