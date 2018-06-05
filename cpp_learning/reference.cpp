#include"iostream"
#include<stdio.h>

using namespace std;

struct Teacher{
    static char & a; // sizeof(Teacher::a) is:1
    char & b;
    int c;
};

struct A{
    int a;
    A()
    {
        cout << "create A" << endl;
    }

};

A & getA()
{
    A a;
    a.a = 10;
    printf("local a address is %p\n", &a);
    return a; //warning: reference to stack memory associated with local variable 'a' returned [-Wreturn-stack-address]
}

A  getA1()
{
    A a;
    a.a = 10;
    printf("local a address is %p\n", &a);
    return a;
}

int main()
{
    int a = 10;
    int & b = a;
    
    cout << "sizeof(Teacher) is:" << sizeof(Teacher) << endl;
    cout << "sizeof(Teacher::a) is:" << sizeof(Teacher::a) << endl;
    // sizeof(Teacher) is:16
    // sizeof(Teacher::a) is:1
    
    A aa = getA();
    cout << "============A aa = getA();============"<< endl;
    cout << endl;
    A & aaa = getA();
    cout << "============A & aaa = getA();============"<< endl;
    cout << endl;
    cout << "aa  is:"<< aa.a << endl;   // aa  is:10
    cout << "aaa is:"<< aaa.a << endl;  // aaa is:-1826490784
    
    // A & aaaa = getA1();  //error: non-const lvalue reference to type 'A' cannot bind to a temporary of type 'A'
    
    const int & bb = a;
    //bb = 20;  // error: cannot assign to variable 'bb' with const-qualified type 'const int &'
                //bb is a firm defender of a
    
    // int & x = 19;  error: non-const lvalue reference to type 'int' cannot bind to a temporary of type 'int'
    const char & x = 'a'; // working!  x is in symbol table, constant value 19 has constant memory space.
    printf("x's address is %p, sizeof(x) is %d\n", &x, sizeof(x)); // reference x has its memory space.
    
    
    
    return 0;
}

