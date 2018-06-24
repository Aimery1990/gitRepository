
#include"iostream"
#include<stdio.h>

using namespace std;

class A{
    
public:
    A()
    {
        a = 0;
        b = 0;
    }
    int getA()
    {
        return this->a;
    }
    friend void setA(A * ptr,  int a);

private:
    int a;
    int b;
    
};

class B{
public:
    B()
    {
        b = 0;
    }
    int getB()
    {
        return this->b;
    }
    friend class C;
private:
    int b;
};

class C{
public:
    void modifyB()
    {
        objB.b = 10;
    }
    B & getObjB()
    {
        return this->objB;
    }
private:
    B objB;
    
};

void setA(A * ptr,  int a)
{
    ptr->a = a;
}

int main()
{
    A a0;
    setA(&a0, 11);
    cout << a0.getA() << endl;

    C c;
    c.modifyB();
    cout << c.getObjB().getB() << endl;
    return 0;
}
