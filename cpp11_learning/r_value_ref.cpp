
#include <iostream>

using namespace std;

class A
{
public:
    A():x(10)
    {
        cout << "A()" << this << endl;
    }

    ~A()
    {
        cout << "~A()" << this << endl;
    }

    A( const A & ano):x(ano.x)
    {
        cout << "A( const A & ano)" << &ano << "->" << this << endl;
    }
    void dis() const
    {
        cout << "xxxxxoooooooo" << endl;
    }

    const int x;//review: const member variables must initialized in initialized parameters list
};

A getObjectA()
{
    return A();
}

void func( const A & a) // review: by const a can hold a temporary stack object from given parameter on stack
{
}

long long funcll()
{
    return 10;
}



int main()
{
    // by &&, a as a reference can hold a temporary stack object from getObjectA() safely
    A && a = getObjectA();
    const A & ar = getObjectA();
    ar.dis(); //void dis() const

    //review: const member variables must initialized in initialized parameters list

    func(A());
    //review:
    int i = 3;
    const int & ri = 10;
    const double & rd = i;
    const long long &rll = funcll();
    cout << i << endl;
    cout << rd << endl;
    i = 8;
    cout << i << endl;
    cout << rd << endl;

    int b = 20;
    int && rb = 10;
    double && rbd = b;
    long long && rbll = funcll();
    cout << b << endl;
    cout << rbd << endl;
    b = 90;
    cout << b << endl;
    cout << rbd << endl;



    return 0;
}