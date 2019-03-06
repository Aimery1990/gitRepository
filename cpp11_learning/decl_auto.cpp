
#include<iostream>

using namespace std;


template<class T1, class T2, class T3>
T1 sum0(T2 a, T3 b)
{
    return a+b;
}

template<class T1, class T2>
auto sum(T1 a,  T2 b)  ->decltype(a+b)
{
    return a+b;
}




int main()
{
    int i = 100;
    double d = 100.1212;

    decltype(i+d) s0 = sum0<decltype(i+d), int, double>(i,d);
    cout << s0 << endl;

    auto s1 = sum(i, d);
    cout << s1 << endl;

    return 0;
}