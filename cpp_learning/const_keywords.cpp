#include "iostream"
#include <stdio.h>

using namespace std;

struct Teacher{
    char name[32];
    int age;
};

void tryTea( const Teacher * p)
{
    // incorrect: error: cannot assign to variable 'p' with const-qualified type 'const Teacher *'
    //p->age = 30;
    
}

void tryTea2( Teacher * const p )
{
    // incorrect: error: cannot assign to variable 'p' with const-qualified type 'Teacher *const'
    // p = NULL;
    
}

int main()
{
    //initial value must be given to const variable
    const int a = 10;
    // actually,  a hasn't been given a real memory, it's in key-value symbol table,
    // if a's address is needed later, a's memory is allocated.
    // but a is ultimately in symbol table
    int const b = 30;
    
    char test[a+b] = {0};
    // this is working for C++, but not for C, due to a and b is in symbol table, they are very like macro
    
    int * p = (int *)&a;
    *p = 11;
    printf("p points to %p and *p is %d\n", p, *p);
    printf("a stored at %p and a  is %d\n", &a, a);
    //p points to 0x7ffeecabcb28 and *p is 11
    //a stored at 0x7ffeecabcb28 and a  is 10

    cout << a << endl; //The value is still 10 !!!
    
    return 0;
}
