
#include<iostream>
#include<string>
#include<functional>

using namespace std;

void foo()
{
    cout << "void foo()" << endl;
}

void foo(int a)
{
    cout << "void foo(int a) a is " << a << endl;
}

class Foo
{
public:
    void method()
    {
        cout << "void Foo::method()" << endl;
    }

    void method2(string s)
    {
        cout << "void Foo::method2(string s)" << endl;
    }

};

class Bar
{
public:
    void method3(int a, string s)
    {
        cout << "void Bar::method3(int a, string s)" << endl;
    }

};

function<void(void)> f[5] = {0};

int main()
{
    f[0] = bind((void (*)())&foo);
    //f();

    //f = bind((void (*)(int))&foo, placeholders::_1); error due to f is void(void) type style placeholder is not accepted
    int x = 25;
    f[1] = bind((void (*)(int))&foo, x);
    //f();

    Foo fo;
    f[2] = bind(&Foo::method,fo);
    //f();

    string s = "great";
    f[3] = bind(&Foo::method2, fo, s);
    //f();

    Bar bar;
    x = 33;
    s = "magic";
    f[4] = bind(&Bar::method3, bar, x, s);
    //f();

    for(auto & i:f)
        i();

    return 0;
}