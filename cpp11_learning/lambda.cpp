
#include <iostream>

using namespace std;

class Bigger{
public:
    Bigger( int a = 1, int b = 5): a(a), b(b)
    {}

    int operator()()
    {
        return ( a > b ) ? a : b;
    }
private:
    int a;
    int b;

};


int main()
{
    int a = 5;
    int b = 6;
    Bigger bigger;
    cout << bigger() << endl;

    int x = 100;
    int y = 200;

    auto f = [=](){return x+y;};
    cout << f() << endl;
    cout << x << " : " << y << endl;

    x = 100;
    y = 200;
    //auto f05 = [=](){ x = 120; y = 220; return x+y; };  //error
    auto f05 = [=]()mutable { x = 120; y = 220; return x+y; };
    cout << f05() << endl;
    cout << x << " 05: " << y << endl;

    x = 100;
    y = 200;
    auto f06 = [&](){ x = 120; y = 220; return x+y; };
    cout << f06() << endl;
    cout << x << " 06: " << y << endl;

    x = 100;
    y = 200;
    auto f07 = [&x, y]()mutable{x = 120; y = 220; return x+y; };
    cout << f07() << endl;
    cout << x << " 07: " << endl;



    x = 100;
    y = 200;
    auto f1 = [](int x, int y){ x = 120, y = 220; return x+y; };
    cout << f1(x, y) << endl;
    cout << x << " 1: " << y << endl;

    x = 100;
    y = 200;
    auto f2 = [](int & x, int & y){ x = 120, y = 220; return x+y; };
    cout << f2(x, y) << endl;
    cout << x << " 2: " << y << endl;

    double money = 38000;
    double base = 5000;
    double rate = 0.02;

    auto tax = [=](double money){
        return ( money - base ) * rate;
    };

    cout << tax( money ) << endl;

    return 0;
}