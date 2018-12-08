
#include<iostream>

using namespace std;

class A{
    
public:
    A()
    {
        this->callee(); //here it prints "aaaaaaaaaaaaa" due to virtual table is not ready, EVEN THOUGH, A * p = &b;!!!!
    }
    
    virtual void callee()
    {
        cout << "aaaaaaaaaaa" << endl;
    }
    
    void caller()
    {
        this->callee();  //here it prints "bbbbbbbbb" as normal polymorphism using.
    }
    
    virtual ~A()
    {
        this->callee(); //here it prints "aaaaaaaaaaaaa" due to virtual table has been destroyed or b has been destoryed previously, EVEN THOUGH, A * p = &b;!!!!
    }
    
};

class B: public A{
    
public:
    B()
    {
 
    }
    
    virtual void callee()
    {
        cout << "bbbbbbbb" << endl;
    }
    
    
    virtual ~B()
    {
    }
    
};

int main()
{
    B b;
    A * pa = &b;
    pa->caller();
    
    
    return 0;
}


