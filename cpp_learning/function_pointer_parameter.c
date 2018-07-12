
#include<stdio.h>

typedef unsigned char uint8;

typedef int (*Fun1_t)(int) ;
typedef int (*Fun2_t)(double, int);
typedef int (*Fun3_t)(char *);
typedef int (*Fun4_t)(char, int);



typedef enum{
    FUNC_PO1 = 0,
    FUNC_PO2,
    FUNC_PO3,
    FUNC_PO4,
    FUNC_PO_MAX
}Fun_T;

typedef struct FuncItem{
    Fun_T id;
    void * fp;
}FuncItem_t;

FuncItem_t funcList[FUNC_PO_MAX] = {0};




int Print_Int( int a )
{
    printf("%s a is %d\n", __FUNCTION__, a);
    return a;
}

int Print_Double_Int( double x, int a )
{
    printf("%s x is %f, a is %d\n", __FUNCTION__, x, a);
    return a;
}

int Print_Char_Str( char * str )
{
    printf("%s str is %s\n", __FUNCTION__, str);
    return 0;
}

int Print_Char_Int( char c, int a )
{
    printf("%s c is %c, a is %d\n", __FUNCTION__, c, a);
    return 0;
}

void * p[FUNC_PO_MAX] = {Print_Int, Print_Double_Int, Print_Char_Str, Print_Char_Int};

int main()
{
    Fun1_t f1p = Print_Int;
    int ret = f1p(0);
    printf("...................................\n");
    
    int i = FUNC_PO1;
    for(; i<FUNC_PO_MAX; i++)
    {
        funcList[i].id = i;
        funcList[i].fp = p[i];
    }
    
    for(i = 0; i<FUNC_PO_MAX; i++)
    {
        if(i==FUNC_PO1)
            ((Fun1_t)funcList[i].fp)(i);
        if(i==FUNC_PO2)
            ((Fun2_t)funcList[i].fp)(0.1, i);
        if(i==FUNC_PO3)
            ((Fun3_t)funcList[i].fp)("helloworld");
        if(i==FUNC_PO4)
            ((Fun4_t)funcList[i].fp)('x', i);
    }
    
    return 0;
}
