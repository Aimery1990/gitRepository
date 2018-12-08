
#include <iostream>
#include <string>


using namespace std;

class A;  //forward declaration: incomplete type using: 1 unable to define specific object
          //                                            2 able to use reference or pointer of such type
          //                                            3 able to use parameter or return value of such type

class B{
public:
    void showA( A & t);
};

class A{
public:
    
private:
    int x;
    int y;
    
    friend void showA( A & t );
    friend void B::showA( A & t);  //class A must follow class B due to B:: or say: class A needs to know class B completely.
    friend class C;
    
};

void showA( A & t)
{
    cout << t.x <<" " << t.y << endl;
}

//function implementation locates here due to it must follow friend void B::showA( A & t);
void B::showA( A & t)
{
    cout << t.x <<" " << t.y << endl;
}

class C{
public:
    void showA1( A & t);
    void showA2( A & t);
};

void C::showA1( A & t)
{
    cout << t.x <<" " << t.y << endl;
}

void C::showA2( A & t)
{
    cout << t.x + t.y << endl;
}


int main()
{
    A x;
    showA(x);
    B bx;
    bx.showA(x);
    C cx;
    cx.showA1(x);
    cx.showA2(x);
    
    
    return 0;
}
