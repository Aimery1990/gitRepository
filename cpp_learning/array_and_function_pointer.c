
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//how to define an array type
//how to define a pointer type pointing to an array

//int array[10];
typedef int Int_Array_t[10];
typedef int (*Int_Array_Ptr_t)[10];

typedef int (Func_t)(int);
typedef int (*Func_Ptr_t)(int);


int test_func(int a)
{
    printf("This is %s a is %d\n", __FUNCTION__, a);
    return 0;
}




int main()
{
    Int_Array_t arr0 ={0};
    Int_Array_Ptr_t arr_p = &arr0;
    arr0[2] = 1;
    arr0[8] = 1;
    
    int i = 0;
    for(; i<10; i++)
    {
        printf("%d ", arr0[i]);
    }
    printf("\n");
    
    for(i = 0; i<10; i++)
    {
        //printf("%d ", *( arr_p + i )); incorrect!!! by arr_p + i address jumps to next Int_Array_t variable
        printf("%d ", *((*arr_p) +i));
    }
    printf("\n");
    
    
//    Func_t f0;
//    f0 = *test_func; //this is incorrect, test_func shouldn't be pointed in.
//    f0(0);
    Func_t * fp0;
    fp0 = test_func;
    fp0(0);
    
    Func_Ptr_t fp1;
    fp1 = test_func;  //fp1 = & test_func is also correct
    fp1(1);
    
    
    int (*fun_p)(int);
    fun_p = test_func;
    fun_p(2);
    
    
    return 0;
}
