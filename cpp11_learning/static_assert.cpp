

#include <iostream>

using namespace std;

//error: static_assert failed "64-bit code generation is not supported"
//static_assert(sizeof(void *) == 4, "64-bit code generation is not supported"); 

static_assert(sizeof(void *) != 4, "32-bit code generation is not supported");

template< typename T, typename U>
int my_bit_copy(T & a, U & b)
{

    static_assert(sizeof(a)==sizeof(b), "parameters' must have same width");

    return 0;
}


int main()
{
    int a; 
    int b;
    char c;

    my_bit_copy(a, b);
    my_bit_copy(a, c);


    return 0;
}