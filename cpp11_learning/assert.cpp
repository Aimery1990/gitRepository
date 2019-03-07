
#include <iostream>
#include <assert.h>

using namespace std;


char * myStrcpy( char * dst, const char * src)
{
    assert(dst); //runtime issue
    assert(src); //runtime issue

    char *d = dst;
    while(*dst++ = *src++);
    return d;
}

int main()
{
    char * dst = NULL;
    char * src = NULL;
    myStrcpy(dst, src);
    return 0;
}